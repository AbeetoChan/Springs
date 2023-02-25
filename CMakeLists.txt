cmake_minimum_required(VERSION 3.20)
project("Springs")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB_RECURSE SRCS "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.hpp")

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(
    "Springs" 
    ${SRCS} 
    ${HEADERS}
)

target_include_directories("Springs" PRIVATE "${PROJECT_BINARY_DIR}")
target_link_libraries("Springs" sfml-graphics)