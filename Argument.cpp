//
// Created by Olcay Taner Yıldız on 4.10.2018.
//

#include "Argument.h"
using namespace std;

/**
 * A constructor of {@link Argument} class which takes argument string which is in the form of argumentType$id
 * and parses this string into argumentType and id. If the argument string does not contain '$' then the
 * constructor return a NONE type argument.
 *
 * @param argument  Argument string containing the argumentType and id
 */
Argument::Argument(string argument) {
    if (argument.find('$') != string::npos){
        argumentType = argument.substr(0, argument.find('$'));
        id = argument.substr(argument.find('$') + 1);
    } else {
        argumentType = "NONE";
    }
}

/**
 * Another constructor of {@link Argument} class which takes argumentType and id as inputs and initializes corresponding attributes
 *
 * @param argumentType  Type of the argument
 * @param id  Id of the argument
 */
Argument::Argument(string argumentType, string id) {
    this->argumentType = move(argumentType);
    this->id = move(id);
}

/**
 * Accessor for argumentType.
 *
 * @return argumentType.
 */
string Argument::getArgumentType() {
    return argumentType;
}

/**
 * Accessor for id.
 *
 * @return id.
 */
string Argument::getId() {
    return id;
}

/**
 * to_string converts an {@link Argument} to a string. If the argumentType is "NONE" returns only "NONE", otherwise
 * it returns argument string which is in the form of argumentType$id
 *
 * @return string form of argument
 */
string Argument::to_string() {
    if (argumentType == "NONE"){
        return argumentType;
    } else {
        return argumentType + "$" + id;
    }
}
