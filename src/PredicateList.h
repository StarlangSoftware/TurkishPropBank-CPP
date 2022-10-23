//
// Created by Olcay Taner Yıldız on 20.10.2018.
//

#ifndef PROPBANK_PREDICATELIST_H
#define PROPBANK_PREDICATELIST_H
#include <string>
#include <map>
#include <unordered_set>
#include "Predicate.h"

using namespace std;

class PredicateList {
private:
    map<string, Predicate> list;
public:
    PredicateList();
    unsigned long size() const;
    Predicate getPredicate(const string& lemma) const;
    unordered_set<string> getLemmaList() const;
};


#endif //PROPBANK_PREDICATELIST_H
