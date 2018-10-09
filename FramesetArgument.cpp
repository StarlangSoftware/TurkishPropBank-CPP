//
// Created by Olcay Taner Yıldız on 7.10.2018.
//

#include "FramesetArgument.h"

FramesetArgument::FramesetArgument(string argumentType, string definition) {
    this->argumentType = move(argumentType);
    this->definition = move(definition);
}

string FramesetArgument::getArgumentType() {
    return argumentType;
}

string FramesetArgument::getDefinition() {
    return definition;
}

void FramesetArgument::setDefinition(string definition) {
    this->definition = move(definition);
}

string FramesetArgument::to_string() {
    return argumentType + ":" + definition;
}
