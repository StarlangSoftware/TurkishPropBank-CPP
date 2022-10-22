//
// Created by Olcay Taner Yıldız on 6.10.2018.
//

#ifndef PROPBANK_ROLESET_H
#define PROPBANK_ROLESET_H
#include <string>
#include <vector>
#include "Role.h"

using namespace std;

class RoleSet {
private:
    string id;
    string name;
    vector<Role> roles;
public:
    RoleSet(const string& _id, const string& _name);
    string getId();
    string getName();
    void addRole(const Role& role);
    Role getRole(int index);
    unsigned long size();
    Role getRoleWithArgument(const string& n);
};


#endif //PROPBANK_ROLESET_H
