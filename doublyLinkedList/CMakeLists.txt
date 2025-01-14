cmake_minimum_required(VERSION 3.26)
project(doublyLinkedList C)

set(CMAKE_C_STANDARD 11)

add_executable(doublyLinkedList main.c
        doublyLinkedList.h
        doublyLinkedList.c)
