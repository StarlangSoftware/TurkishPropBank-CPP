//
// Created by Olcay Taner Yıldız on 6.10.2018.
//

#include "RoleSet.h"

RoleSet::RoleSet(string id, string name) {
    this->id = move(id);
    this->name = move(name);
}

string RoleSet::getId() {
    return id;
}

string RoleSet::getName() {
    return name;
}

void RoleSet::addRole(Role role) {
    roles.push_back(role);
}

Role RoleSet::getRole(int index) {
    return roles.at(index);
}

unsigned long RoleSet::size() {
    return roles.size();
}
