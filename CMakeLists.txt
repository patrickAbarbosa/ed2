cmake_minimum_required(VERSION 3.12)
project(TrabalhoED2 VERSION 0.0.1)

set(DIRECTORY src)
include_directories(${DIRECTORY})

set(SOURCES
  ./main.cpp
  ${DIRECTORY}/classes/Menu.cpp
  ${DIRECTORY}/headers/Menu.h
)
add_executable(cmake-good ${SOURCES})
