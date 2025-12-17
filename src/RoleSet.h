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
    [[nodiscard]] string getId() const;
    [[nodiscard]] string getName() const;
    void addRole(const Role& role);
    [[nodiscard]] Role getRole(int index) const;
    [[nodiscard]] unsigned long size() const;
    [[nodiscard]] Role getRoleWithArgument(const string& n) const;
};


#endif //PROPBANK_ROLESET_H
