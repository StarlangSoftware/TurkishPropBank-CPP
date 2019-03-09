cmake_minimum_required(VERSION 3.12)

project(PropBank)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(library/XmlParser-CPP)

include_directories(library/XmlParser-CPP)

add_library(PropBank Argument.cpp Argument.h ArgumentType.h Role.cpp Role.h RoleSet.cpp RoleSet.h FramesetArgument.cpp FramesetArgument.h Frameset.cpp Frameset.h Predicate.cpp Predicate.h PredicateList.cpp PredicateList.h FramesetList.cpp FramesetList.h)

target_link_libraries(PropBank XmlParser)

add_executable(TestPropBank Argument.cpp Argument.h ArgumentType.h Role.cpp Role.h RoleSet.cpp RoleSet.h FramesetArgument.cpp FramesetArgument.h Frameset.cpp Frameset.h Predicate.cpp Predicate.h PredicateList.cpp PredicateList.h FramesetList.cpp FramesetList.h TestPropBank.cpp)

target_link_libraries(TestPropBank XmlParser)
