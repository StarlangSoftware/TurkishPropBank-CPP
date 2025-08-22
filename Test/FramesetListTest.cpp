//
// Created by Olcay Taner YILDIZ on 21.12.2020.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/FramesetList.h"

TEST_CASE("FramesetList-testFrames") {
    FramesetList framesetList = FramesetList();
    REQUIRE(17531 == framesetList.size());
}

TEST_CASE("FramesetList-testArgSize") {
    FramesetList framesetList = FramesetList();
    int count = 0;
    for (int i = 0; i < framesetList.size(); i++){
        count += framesetList.getFrameset(i).getFramesetArguments().size();
    }
    REQUIRE(29473 == count);
}

TEST_CASE("FramesetList-testCase") {
    FramesetList framesetList = FramesetList();
    map<string, int> caseList = map<string, int>();
    for (int i = 0; i < framesetList.size(); i++){
        for (const FramesetArgument& argument : framesetList.getFrameset(i).getFramesetArguments()) {
            if (!argument.getGrammaticalCase().empty()) {
                if (argument.getGrammaticalCase().find("abl") != std::string::npos) {
                    if (caseList.contains("abl")){
                        caseList["abl"] = caseList["abl"] + 1;
                    } else {
                        caseList["abl"] = 1;
                    }
                }
                if (argument.getGrammaticalCase().find("acc") != std::string::npos) {
                    if (caseList.contains("acc")){
                        caseList["acc"] = caseList["acc"] + 1;
                    } else {
                        caseList["acc"] = 1;
                    }
                }
                if (argument.getGrammaticalCase().find("dat") != std::string::npos) {
                    if (caseList.contains("dat")){
                        caseList["dat"] = caseList["dat"] + 1;
                    } else {
                        caseList["dat"] = 1;
                    }
                }
                if (argument.getGrammaticalCase().find("gen") != std::string::npos) {
                    if (caseList.contains("gen")){
                        caseList["gen"] = caseList["gen"] + 1;
                    } else {
                        caseList["gen"] = 1;
                    }
                }
                if (argument.getGrammaticalCase().find("ins") != std::string::npos) {
                    if (caseList.contains("ins")){
                        caseList["ins"] = caseList["ins"] + 1;
                    } else {
                        caseList["ins"] = 1;
                    }
                }
                if (argument.getGrammaticalCase().find("loc") != std::string::npos) {
                    if (caseList.contains("loc")){
                        caseList["loc"] = caseList["loc"] + 1;
                    } else {
                        caseList["loc"] = 1;
                    }
                }
                if (argument.getGrammaticalCase().find("nom") != std::string::npos) {
                    if (caseList.contains("nom")){
                        caseList["nom"] = caseList["nom"] + 1;
                    } else {
                        caseList["nom"] = 1;
                    }
                }
            }
        }
    }
    REQUIRE(418 == caseList["abl"]);
    REQUIRE(4633 == caseList["acc"]);
    REQUIRE(2402 == caseList["dat"]);
    REQUIRE(870 == caseList["gen"]);
    REQUIRE(451 == caseList["ins"]);
    REQUIRE(666 == caseList["loc"]);
    REQUIRE(2049 == caseList["nom"]);
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
    REQUIRE(14535 == nameList["ARG0"]);
    REQUIRE(12996 == nameList["ARG1"]);
    REQUIRE(1865 == nameList["ARG2"]);
    REQUIRE(76 == nameList["ARG3"]);
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
    REQUIRE(475 == functionList["com"]);
    REQUIRE(14 == functionList["ext"]);
    REQUIRE(808 == functionList["loc"]);
    REQUIRE(195 == functionList["rec"]);
    REQUIRE(13 == functionList["pat"]);
    REQUIRE(10579 == functionList["ppt"]);
    REQUIRE(597 == functionList["src"]);
    REQUIRE(794 == functionList["gol"]);
    REQUIRE(156 == functionList["tmp"]);
    REQUIRE(14425 == functionList["pag"]);
    REQUIRE(1417 == functionList["dir"]);
}
