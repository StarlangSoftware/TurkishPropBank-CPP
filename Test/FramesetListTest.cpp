//
// Created by Olcay Taner YILDIZ on 21.12.2020.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/FramesetList.h"

TEST_CASE("FramesetList-testFrames") {
    FramesetList framesetList = FramesetList();
    REQUIRE(17691 == framesetList.size());
}

TEST_CASE("FramesetList-testArgSize") {
    FramesetList framesetList = FramesetList();
    int count = 0;
    for (int i = 0; i < framesetList.size(); i++){
        count += framesetList.getFrameset(i).getFramesetArguments().size();
    }
    REQUIRE(29759 == count);
}

TEST_CASE("FramesetList-testArgName") {
    FramesetList framesetList = FramesetList();
    map<string, int> nameList = map<string, int>();
    for (int i = 0; i < framesetList.size(); i++){
        for (const FramesetArgument& argument : framesetList.getFrameset(i).getFramesetArguments()){
            if (nameList.contains(argument.getArgumentType())){
                nameList[argument.getArgumentType()] = nameList[argument.getArgumentType()] + 1;
            } else {
                nameList[argument.getArgumentType()] = 1;
            }
        }
    }
    REQUIRE(14668 == nameList["ARG0"]);
    REQUIRE(13126 == nameList["ARG1"]);
    REQUIRE(1886 == nameList["ARG2"]);
    REQUIRE(78 == nameList["ARG3"]);
    REQUIRE(1 == nameList["ARG4"]);
}

TEST_CASE("FramesetList-testArgFunction") {
    FramesetList framesetList = FramesetList();
    map<string, int> functionList = map<string, int>();
    for (int i = 0; i < framesetList.size(); i++){
        for (const FramesetArgument& argument : framesetList.getFrameset(i).getFramesetArguments()){
            if (functionList.contains(argument.getFunction())){
                functionList[argument.getFunction()] = functionList[argument.getFunction()] + 1;
            } else {
                functionList[argument.getFunction()] = 1;
            }
        }
    }
    REQUIRE(481 == functionList["com"]);
    REQUIRE(14 == functionList["ext"]);
    REQUIRE(814 == functionList["loc"]);
    REQUIRE(198 == functionList["rec"]);
    REQUIRE(14 == functionList["pat"]);
    REQUIRE(10687 == functionList["ppt"]);
    REQUIRE(605 == functionList["src"]);
    REQUIRE(801 == functionList["gol"]);
    REQUIRE(156 == functionList["tmp"]);
    REQUIRE(14557 == functionList["pag"]);
    REQUIRE(1432 == functionList["dir"]);
}
