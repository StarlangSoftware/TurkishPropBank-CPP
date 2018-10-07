cmake_minimum_required(VERSION 3.12)
project(PropBank)

set(CMAKE_CXX_STANDARD 17)

add_library(PropBank Argument.cpp Argument.h ArgumentType.h Role.cpp Role.h RoleSet.cpp RoleSet.h)