//
// Created by Olcay Taner Yıldız on 6.10.2018.
//

#ifndef PROPBANK_ROLE_H
#define PROPBANK_ROLE_H
#include <string>
#include "ArgumentType.h"

using namespace std;

class Role {
private:
    string description;
    string f;
    string n;
public:
    Role(const string& _description, const string& _f, const string& _n);
    string getDescription() const;
    string getF() const;
    string getN() const;
    ArgumentType getArgumentType() const;
};


#endif //PROPBANK_ROLE_H
