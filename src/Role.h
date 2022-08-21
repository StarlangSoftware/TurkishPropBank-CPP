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
    Role(string description, string f, string n);
    string getDescription();
    string getF();
    string getN();
    ArgumentType getArgumentType();
};


#endif //PROPBANK_ROLE_H
