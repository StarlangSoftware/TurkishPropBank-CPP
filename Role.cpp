#include <utility>

//
// Created by Olcay Taner Yıldız on 6.10.2018.
//

#include "Role.h"

Role::Role(string description, string f, string n) {
    this->description = move(description);
    this->f = move(f);
    this->n = move(n);
}

string Role::getDescription() {
    return description;
}

string Role::getF() {
    return f;
}

string Role::getN() {
    return n;
}

ArgumentType Role::getArgumentType() {
    transform(f.begin(), f.end(), f.begin(), ::toupper);
    return getArguments("ARG" + f);
}
