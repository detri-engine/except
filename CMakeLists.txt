cmake_minimum_required(VERSION 4.1)
project(except)

set(CMAKE_CXX_STANDARD 26)

add_library(detri_except STATIC)
target_sources(detri_except PUBLIC FILE_SET HEADERS
    BASE_DIRS src
    FILES src/detri/except.hpp
)
target_sources(detri_except PRIVATE src/detri/except.cpp)
