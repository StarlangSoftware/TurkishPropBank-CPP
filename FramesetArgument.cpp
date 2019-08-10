//
// Created by Olcay Taner Yıldız on 7.10.2018.
//

#include "FramesetArgument.h"

/**
 * A constructor of {@link FramesetArgument} class which takes argumentType and definition as input and initializes corresponding attributes
 *
 * @param argumentType  ArgumentType of the frameset argument
 * @param definition  Definition of the frameset argument
 */
FramesetArgument::FramesetArgument(string argumentType, string definition) {
    this->argumentType = move(argumentType);
    this->definition = move(definition);
}

/**
 * Accessor for argumentType.
 *
 * @return argumentType.
 */
string FramesetArgument::getArgumentType() {
    return argumentType;
}

/**
 * Accessor for definition.
 *
 * @return definition.
 */
string FramesetArgument::getDefinition() {
    return definition;
}

/**
 * Mutator for definition.
 *
 * @param definition to set.
 */
void FramesetArgument::setDefinition(string definition) {
    this->definition = move(definition);
}

/**
 * to_string converts an {@link FramesetArgument} to a string. It returns argument string which is in the form of
 * argumentType:definition
 *
 * @return string form of frameset argument
 */
string FramesetArgument::to_string() {
    return argumentType + ":" + definition;
}
