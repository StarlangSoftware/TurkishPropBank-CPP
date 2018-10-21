//
// Created by Olcay Taner Yıldız on 20.10.2018.
//

#ifndef PROPBANK_PREDICATELIST_H
#define PROPBANK_PREDICATELIST_H
#include <string>
#include <map>
#include "Predicate.h"

using namespace std;

class PredicateList {
private:
    map<string, Predicate> list;
public:
    PredicateList();
    unsigned long size();
    Predicate getPredicate(string lemma);
};


#endif //PROPBANK_PREDICATELIST_H
