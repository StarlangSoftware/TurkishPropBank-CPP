//
// Created by Olcay Taner Yıldız on 7.10.2018.
//

#include "Predicate.h"

Predicate::Predicate(string lemma) {
    this->lemma = move(lemma);
}

string Predicate::getLemma() {
    return lemma;
}

void Predicate::addRoleSet(RoleSet roleSet) {
    roleSets.push_back(roleSet);
}

unsigned long Predicate::size() {
    return roleSets.capacity();
}

RoleSet Predicate::getRoleSet(unsigned long index) {
    return roleSets.at(index);
}

RoleSet Predicate::getRoleSet(string roleId) {
    for (RoleSet roleSet : roleSets){
        if (roleSet.getId() == roleId){
            return roleSet;
        }
    }
}
