//
// Created by Olcay Taner YILDIZ on 21.12.2020.
//

#include "catch.hpp"
#include "../PredicateList.h"

TEST_CASE("PredicateList-testPredicateSize") {
    PredicateList predicateList = PredicateList();
    REQUIRE(8656 == predicateList.size());
}

TEST_CASE("PredicateList-testRoleSetSize") {
    PredicateList predicateList = PredicateList();
    int count = 0;
    for (string lemma : predicateList.getLemmaList()){
        count += predicateList.getPredicate(lemma).size();
    }
    REQUIRE(10685 == count);
}

TEST_CASE("PredicateList-testRoleSize") {
    PredicateList predicateList = PredicateList();
    int count = 0;
    for (string lemma : predicateList.getLemmaList()){
        for (int i = 0; i < predicateList.getPredicate(lemma).size(); i++){
            count += predicateList.getPredicate(lemma).getRoleSet(i).size();
        }
    }
    REQUIRE(27080 == count);
}

TEST_CASE("PredicateList-testFunction") {
    PredicateList predicateList = PredicateList();
    map<string, int> functionList = map<string, int>();
    for (string lemma : predicateList.getLemmaList()){
        for (int i = 0; i < predicateList.getPredicate(lemma).size(); i++){
            for (int j = 0; j < predicateList.getPredicate(lemma).getRoleSet(i).size(); j++){
                string function = predicateList.getPredicate(lemma).getRoleSet(i).getRole(j).getF();
                if (functionList.find(function) != functionList.end()){
                    functionList[function] = functionList[function] + 1;
                } else {
                    functionList[function] = 1;
                }
            }
        }
    }
    REQUIRE(197 == functionList["com"]);
    REQUIRE(292 == functionList["ext"]);
    REQUIRE(580 == functionList["loc"]);
    REQUIRE(1104 == functionList["prd"]);
    REQUIRE(2395 == functionList["gol"]);
    REQUIRE(19 == functionList["adj"]);
    REQUIRE(980 == functionList["dir"]);
    REQUIRE(118 == functionList["prp"]);
    REQUIRE(1007 == functionList["mnr"]);
    REQUIRE(4 == functionList["rec"]);
    REQUIRE(679 == functionList["vsp"]);
    REQUIRE(14 == functionList["adv"]);
    REQUIRE(10282 == functionList["ppt"]);
    REQUIRE(267 == functionList["cau"]);
    REQUIRE(37 == functionList["tmp"]);
    REQUIRE(9105 == functionList["pag"]);
}

TEST_CASE("PredicateList-testN") {
    PredicateList predicateList = PredicateList();
    map<string, int> nList = map<string, int>();
    for (string lemma : predicateList.getLemmaList()){
        for (int i = 0; i < predicateList.getPredicate(lemma).size(); i++){
            for (int j = 0; j < predicateList.getPredicate(lemma).getRoleSet(i).size(); j++){
                string n = predicateList.getPredicate(lemma).getRoleSet(i).getRole(j).getN();
                if (nList.find(n) != nList.end()){
                    nList[n] = nList[n] + 1;
                } else {
                    nList[n] = 1;
                }
            }
        }
    }
    REQUIRE(8906 == nList["0"]);
    REQUIRE(10375 == nList["1"]);
    REQUIRE(5934 == nList["2"]);
    REQUIRE(1313 == nList["3"]);
    REQUIRE(417 == nList["4"]);
    REQUIRE(57 == nList["5"]);
    REQUIRE(6 == nList["6"]);
    REQUIRE(72 == nList["m"]);
}
