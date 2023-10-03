//
// Created by Olcay Taner Yıldız on 4.10.2018.
//

#include "Argument.h"
using namespace std;

/**
 * A constructor of Argument class which takes argument string which is in the form of argumentType$id
 * and parses this string into argumentType and id. If the argument string does not contain '$' then the
 * constructor return a NONE type argument.
 *
 * @param argument  Argument string containing the argumentType and id
 */
Argument::Argument(const string& argument) {
    if (argument.find('$') != string::npos){
        argumentType = argument.substr(0, argument.find('$'));
        id = argument.substr(argument.find('$') + 1);
    } else {
        argumentType = "NONE";
    }
}

/**
 * Another constructor of Argument class which takes _argumentType and _id as inputs and initializes corresponding attributes
 *
 * @param _argumentType  Type of the argument
 * @param _id  Id of the argument
 */
Argument::Argument(const string& _argumentType, const string& _id) {
    this->argumentType = _argumentType;
    this->id = _id;
}

/**
 * Accessor for argumentType.
 *
 * @return argumentType.
 */
string Argument::getArgumentType() const{
    return argumentType;
}

/**
 * Accessor for id.
 *
 * @return id.
 */
string Argument::getId() const{
    return id;
}

/**
 * to_string converts an Argument to a string. If the argumentType is "NONE" returns only "NONE", otherwise
 * it returns argument string which is in the form of argumentType$id
 *
 * @return string form of argument
 */
string Argument::to_string() const{
    if (argumentType == "NONE"){
        return argumentType;
    } else {
        return argumentType + "$" + id;
    }
}
