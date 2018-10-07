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
    RoleSet(string id, string name);
    string getId();
    string getName();
    void addRole(Role role);
    Role getRole(int index);
    unsigned long size();
};


#endif //PROPBANK_ROLESET_H
