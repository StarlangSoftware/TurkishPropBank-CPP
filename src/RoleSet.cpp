//
// Created by Olcay Taner Yıldız on 6.10.2018.
//

#include "RoleSet.h"

/**
 * A constructor of RoleSet class which takes _id and _name as inputs and initializes corresponding attributes
 * with these inputs.
 *
 * @param _id  Id of the roleSet
 * @param _name Name of the roleSet
 */
RoleSet::RoleSet(const string& _id, const string& _name) {
    this->id = _id;
    this->name = _name;
}

/**
 * Accessor for id.
 *
 * @return id.
 */
string RoleSet::getId() const{
    return id;
}

/**
 * Accessor for name.
 *
 * @return name.
 */
string RoleSet::getName() const{
    return name;
}

/**
 * The addRole method takes a Role as input and adds it to the roles ArrayList.
 *
 * @param role  Role to be added
 */
void RoleSet::addRole(const Role& role) {
    roles.push_back(role);
}

/**
 * The getRole method returns the role at the given index.
 *
 * @param index  Index of the role
 * @return Role at the given index.
 */
Role RoleSet::getRole(int index) const{
    return roles.at(index);
}

/**
 * The size method returns the size of the roles ArrayList.
 *
 * @return the size of the roles ArrayList.
 */
unsigned long RoleSet::size() const{
    return roles.size();
}

/**
 * Finds and returns the role with the given argument number n. For example, if n == 0, the method returns
 * the argument ARG0.
 * @param n Argument number
 * @return The role with the given argument number n.
 */
Role RoleSet::getRoleWithArgument(const string& n) const{
    for (auto role : roles){
        if (role.getN() == n){
            return role;
        }
    }
}
