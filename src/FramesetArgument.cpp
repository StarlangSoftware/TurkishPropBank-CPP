//
// Created by Olcay Taner Yıldız on 7.10.2018.
//

#include "FramesetArgument.h"

/**
 * A constructor of FramesetArgument class which takes _argumentType and _definition as input and initializes corresponding attributes
 *
 * @param _argumentType  ArgumentType of the frameset argument
 * @param _definition  Definition of the frameset argument
 * @param _function Function of the frameset argument
 * @param _grammaticalCase Case of the frameset argument
 */
FramesetArgument::FramesetArgument(const string& _argumentType, const string& _definition, const string& _function, const string& _grammaticalCase) {
    this->argumentType = _argumentType;
    this->definition = _definition;
    this->function = _function;
    this->grammaticalCase = _grammaticalCase;
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
 * Accessor for grammaticalCase.
 *
 * @return grammaticalCase.
 */
string FramesetArgument::getGrammaticalCase() const {
    return grammaticalCase;
}

/**
 * Mutator for _definition.
 *
 * @param _definition definition to set.
 */
void FramesetArgument::setDefinition(const string& _definition) {
    this->definition = _definition;
}

/**
 * Mutator for definition.
 *
 * @param _function function to set.
 */
void FramesetArgument::setFunction(const string& _function) {
    this->function = _function;
}

/**
 * Mutator for grammaticalCase.
 *
 * @param _grammaticalCase grammaticalCase to set.
 */
void FramesetArgument::setGrammaticalCase(const string &_grammaticalCase) {
    this->grammaticalCase = _grammaticalCase;
}

/**
 * to_string converts an FramesetArgument to a string. It returns argument string which is in the form of
 * argumentType:definition
 *
 * @return string form of frameset argument
 */
string FramesetArgument::to_string() const{
    return argumentType + ":" + definition;
}
