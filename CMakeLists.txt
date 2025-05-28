cmake_minimum_required(VERSION 3.10)
project(StarForge)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(StarForge src/main.cpp src/Game.cpp)
target_link_libraries(StarForge sfml-graphics sfml-window sfml-system)