cmake_minimum_required(VERSION 3.15)
project(sharepoint)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

add_subdirectory(OpenXLSX)

add_executable(sharepoint main.cpp
        Sharepoint.h
        Sharepoint.cpp
)

target_link_libraries(sharepoint OpenXLSX::OpenXLSX)
