//
// Created by Olcay Taner YILDIZ on 10.02.2021.
//

#include "catch.hpp"
#include "../ArgumentType.h"

TEST_CASE("ArgumentTypeTest-testArgumentType") {
    REQUIRE(getArguments("") == ArgumentType::NONE);
    REQUIRE(getArguments("arg0") == ArgumentType::ARG0);
    REQUIRE(getArguments("argmdis") == ArgumentType::ARGMDIS);
    REQUIRE(getArguments("Arg1") == ArgumentType::ARG1);
    REQUIRE(getArguments("Argmdir") == ArgumentType::ARGMDIR);
}
