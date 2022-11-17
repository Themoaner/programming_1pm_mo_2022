cmake_minimum_required(VERSION 3.25)

set(PROGECT_NAME test)
project("${PROGECT_NAME}")

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENYIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)

add_executable("${PROGECT_NAME}" lab_6.cpp
								Header.h
								func.cpp)