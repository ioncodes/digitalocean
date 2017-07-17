cmake_minimum_required(VERSION 3.7)
project(digitalocean)

set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(/Users/luca/Desktop/include)


set(SOURCE_FILES main.cpp)
add_executable(digitalocean ${SOURCE_FILES})
target_link_libraries(digitalocean /Users/luca/Desktop/lib/librestclient-cpp.1.dylib)