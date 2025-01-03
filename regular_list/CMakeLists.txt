cmake_minimum_required(VERSION 3.26)
project(regular_list C)

set(CMAKE_C_STANDARD 11)

add_executable(regular_list main.c
        regular_list.h
        regular_list.c)
