#include <utility>

//
// Created by Olcay Taner Yıldız on 6.10.2018.
//

#include "Role.h"

/**
 * A constructor of {@link Role} class which takes _description, _f, and _n as inputs and initializes corresponding with these inputs.
 *
 * @param _description  Description of the role
 * @param _f  Argument Type of the role
 * @param _n  Number of the role
 */
Role::Role(const string& _description, const string& _f, const string& _n) {
    this->description = _description;
    this->f = _f;
    this->n = _n;
}

/**
 * Accessor for description.
 *
 * @return description.
 */
string Role::getDescription() {
    return description;
}

/**
 * Accessor for f.
 *
 * @return f.
 */
string Role::getF() {
    return f;
}

/**
 * Accessor for n.
 *
 * @return n.
 */
string Role::getN() {
    return n;
}

/**
 * Constructs and returns the argument type for this role.
 *
 * @return Argument type for this role.
 */
ArgumentType Role::getArgumentType() {
    transform(f.begin(), f.end(), f.begin(), ::toupper);
    return getArguments("ARG" + f);
}
