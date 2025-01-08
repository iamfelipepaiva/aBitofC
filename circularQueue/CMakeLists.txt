cmake_minimum_required(VERSION 3.26)
project(circularQueue C)

set(CMAKE_C_STANDARD 11)

add_executable(circularQueue main.c
        circularQueue.h
        circularQueue.c)
