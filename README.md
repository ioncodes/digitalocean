# digitalocean
Crossplatform Digital Ocean tool :)

# Setup
1. Clone the repo.
2. Get ```json.hpp``` from [here](https://github.com/nlohmann/json).
3. Get and setup ```restclient-cpp``` from [here](https://github.com/mrtazz/restclient-cpp).
4. Change the following two lines to your locations.
```cmake
INCLUDE_DIRECTORIES(/Users/luca/Desktop/include)
target_link_libraries(digitalocean /Users/luca/Desktop/lib/librestclient-cpp.1.dylib)
```
5. Create an evironment variable called ```DIGITAL_OCEAN_TOKEN``` with the value of your api token.
6. Compile and run :)
