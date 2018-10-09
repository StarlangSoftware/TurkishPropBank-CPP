//
// Created by Olcay Taner Yıldız on 7.10.2018.
//

#ifndef PROPBANK_PREDICATE_H
#define PROPBANK_PREDICATE_H
#include <string>
#include <vector>
#include "RoleSet.h"

using namespace std;

class Predicate {
private:
    string lemma;
    vector<RoleSet> roleSets;
public:
    Predicate(string lemma);
    string getLemma();
    void addRoleSet(RoleSet roleSet);
    unsigned long size();
    RoleSet getRoleSet(unsigned long index);
    RoleSet getRoleSet(string roleId);
};


#endif //PROPBANK_PREDICATE_H
