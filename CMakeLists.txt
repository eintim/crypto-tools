cmake_minimum_required(VERSION 3.17)
project(crypto_tools C)

set(CMAKE_C_STANDARD 11)

include_directories(src/Caesar)

add_executable(crypto_tools
        src/Caesar/caesar.c
        src/Caesar/caesar.h
        src/main.c)
