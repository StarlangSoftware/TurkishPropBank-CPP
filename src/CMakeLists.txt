cmake_minimum_required(VERSION 3.12)
project(PropBank)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(util REQUIRED)
find_package(xml_parser REQUIRED)

add_library(PropBank Argument.cpp Argument.h ArgumentType.h Role.cpp Role.h RoleSet.cpp RoleSet.h FramesetArgument.cpp FramesetArgument.h Frameset.cpp Frameset.h Predicate.cpp Predicate.h PredicateList.cpp PredicateList.h FramesetList.cpp FramesetList.h ArgumentList.cpp ArgumentList.h)
target_link_libraries(PropBank xml_parser::xml_parser util::util)
