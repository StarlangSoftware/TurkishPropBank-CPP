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
    explicit Predicate(const string& _lemma);
    [[nodiscard]] string getLemma() const;
    void addRoleSet(const RoleSet& roleSet);
    [[nodiscard]] unsigned long size() const;
    [[nodiscard]] RoleSet getRoleSet(unsigned long index) const;
    [[nodiscard]] RoleSet getRoleSet(const string& roleId) const;
};


#endif //PROPBANK_PREDICATE_H
