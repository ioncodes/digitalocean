#include <iostream>
#include <restclient-cpp/restclient.h>
#include <restclient-cpp/connection.h>
#include <json/json.hpp>

using json = nlohmann::json;

std::string get(std::string);
void showHelp();

int main(int argc, const char **argv) {
    std::string endpoint = "";

    if(std::string(argv[1]) == "list") {
        endpoint = "/v2/droplets";
    } else {
        showHelp();
        std::cout << "Unknown option." << std::endl;
        return -1;
    }

    std::string response = get(endpoint);

    if(response == "") {
        std::cout << "DIGITAL_OCEAN_TOKEN not set." << std::endl;
        return -1;
    }

    json json = json::parse(response);

    for (json::iterator it = json["droplets"].begin(); it != json["droplets"].end(); ++it) {
        auto droplet = it.value();
        std::string name = droplet["name"];
        std::string status = droplet["status"];
        std::string os = droplet["image"]["distribution"];
        std::string memory = droplet["size"]["slug"];
        std::string vcpus = std::to_string(droplet["size"]["vcpus"].get<int>());
        std::string disk = std::to_string(droplet["size"]["disk"].get<int>());
        std::string ip = droplet["networks"]["v4"][0]["ip_address"];
        std::stringstream ss;
        ss << "Name: " << name << "\nStatus: " << status << "\nOS: " << os << "\nMemory: " << memory << "\nCPUs: " << vcpus << "\nDisksize: " << disk <<  "\nIP: " << ip << std::endl;
        std::cout << ss.str() << std::endl;
    }

    return 0;
}

std::string get(std::string endpoint) {
    RestClient::init();

    RestClient::Connection* conn = new RestClient::Connection("https://api.digitalocean.com");

    auto token = std::getenv("DIGITAL_OCEAN_TOKEN");

    if(token == NULL) {
        return "";
    }

    RestClient::HeaderFields headers;
    headers["Authorization"] = std::string("Bearer ").append(token);
    conn->SetHeaders(headers);

    RestClient::Response r = conn->get(endpoint);

    RestClient::disable();

    return r.body;
}

void showHelp() {
    std::cout << "Commands:\nlist: list all droplets" <<    std::endl;
}