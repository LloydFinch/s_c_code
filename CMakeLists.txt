cmake_minimum_required(VERSION 3.13)
project(c_code C)

set(CMAKE_C_STANDARD 99)

add_executable(c_code main.c support.c main1.c)