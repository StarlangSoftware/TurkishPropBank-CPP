cmake_minimum_required(VERSION 3.12)
project(PropBank)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(PropBank src/Argument.cpp src/Argument.h src/ArgumentType.h src/Role.cpp src/Role.h src/RoleSet.cpp src/RoleSet.h src/FramesetArgument.cpp src/FramesetArgument.h src/Frameset.cpp src/Frameset.h src/Predicate.cpp src/Predicate.h src/PredicateList.cpp src/PredicateList.h src/FramesetList.cpp src/FramesetList.h)
target_link_libraries(PropBank ${CONAN_LIBS})
add_executable(Test src/Argument.cpp src/Argument.h src/ArgumentType.h src/Role.cpp src/Role.h src/RoleSet.cpp src/RoleSet.h src/FramesetArgument.cpp src/FramesetArgument.h src/Frameset.cpp src/Frameset.h src/Predicate.cpp src/Predicate.h src/PredicateList.cpp src/PredicateList.h src/FramesetList.cpp src/FramesetList.h Test/catch.hpp Test/FramesetListTest.cpp Test/PredicateListTest.cpp Test/ArgumentTypeTest.cpp)
target_link_libraries(Test ${CONAN_LIBS})
