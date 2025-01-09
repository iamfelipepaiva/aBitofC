cmake_minimum_required(VERSION 3.26)
project(linkedList C)

set(CMAKE_C_STANDARD 11)

add_executable(linkedList main.c
        linkedList.h
        linkedList.c)
