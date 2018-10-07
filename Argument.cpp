#include <utility>
//
// Created by Olcay Taner Yıldız on 4.10.2018.
//

#include "Argument.h"
using namespace std;

Argument::Argument(string argument) {
    if (argument.find('$') != string::npos){
        argumentType = argument.substr(0, argument.find('$'));
        id = argument.substr(argument.find('$') + 1);
    } else {
        argumentType = "NONE";
    }
}

Argument::Argument(string argumentType, string id) {
    this->argumentType = move(argumentType);
    this->id = move(id);
}

string Argument::getArgumentType() {
    return argumentType;
}

string Argument::getId() {
    return id;
}

string Argument::to_string() {
    if (argumentType == "NONE"){
        return argumentType;
    } else {
        return argumentType + "$" + id;
    }
}
