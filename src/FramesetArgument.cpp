//
// Created by Olcay Taner Yıldız on 7.10.2018.
//

#include "FramesetArgument.h"

/**
 * A constructor of {@link FramesetArgument} class which takes _argumentType and _definition as input and initializes corresponding attributes
 *
 * @param _argumentType  ArgumentType of the frameset argument
 * @param _definition  Definition of the frameset argument
 */
FramesetArgument::FramesetArgument(const string& _argumentType, const string& _definition, const string& _function) {
    this->argumentType = _argumentType;
    this->definition = _definition;
    this->function = _function;
}

/**
 * Accessor for argumentType.
 *
 * @return argumentType.
 */
string FramesetArgument::getArgumentType() const{
    return argumentType;
}

/**
 * Accessor for definition.
 *
 * @return definition.
 */
string FramesetArgument::getDefinition() const{
    return definition;
}

/**
 * Accessor for function.
 *
 * @return function.
 */
string FramesetArgument::getFunction() const{
    return function;
}

/**
 * Mutator for _definition.
 *
 * @param _definition to set.
 */
void FramesetArgument::setDefinition(const string& _definition) {
    this->definition = _definition;
}

/**
 * Mutator for definition.
 *
 * @param definition to set.
 */
void FramesetArgument::setFunction(const string& _function) {
    this->function = _function;
}

/**
 * to_string converts an {@link FramesetArgument} to a string. It returns argument string which is in the form of
 * argumentType:definition
 *
 * @return string form of frameset argument
 */
string FramesetArgument::to_string() const{
    return argumentType + ":" + definition;
}
