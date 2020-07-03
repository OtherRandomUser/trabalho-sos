cmake_minimum_required(VERSION 3.13)
project(projeto-sos)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads)

add_subdirectory(src bin)