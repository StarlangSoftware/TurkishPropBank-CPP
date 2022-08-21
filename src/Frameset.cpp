//
// Created by Olcay Taner Yıldız on 7.10.2018.
//

#include "Frameset.h"

/**
 * A constructor of {@link Frameset} class which takes id as input and initializes corresponding attribute
 *
 * @param id  Id of the frameset
 */
Frameset::Frameset(string id) {
    this->id = move(id);
}

/**
 * Another constructor of {@link Frameset} class which takes inputStream as input and reads the frameset
 *
 * @param xmlDocument  inputStream to read frameset
 */
Frameset::Frameset(XmlElement* frameSetNode) {
    id = move(frameSetNode->getAttributeValue("id"));
    XmlElement* argument = frameSetNode->getFirstChild();
    while (argument != nullptr){
        FramesetArgument framesetArgument = FramesetArgument(argument->getAttributeValue("name"), argument->getPcData(), argument->getAttributeValue("function"));
        framesetArguments.push_back(framesetArgument);
        argument = argument->getNextSibling();
    }
}

/**
 * containsArgument method which checks if there is an {@link Argument} of the given argumentType.
 *
 * @param argumentType  ArgumentType of the searched {@link Argument}
 * @return true if the {@link Argument} with the given argumentType exists, false otherwise.
 */
bool Frameset::containsArgument(ArgumentType argumentType) {
    for (FramesetArgument framesetArgument : framesetArguments){
        if (getArguments(framesetArgument.getArgumentType()) == argumentType){
            return true;
        }
    }
    return false;
}

/**
 * The addArgument method takes a type and a definition of a {@link FramesetArgument} as input, then it creates a new FramesetArgument from these inputs and
 * adds it to the framesetArguments {@link ArrayList}.
 *
 * @param type  Type of the new {@link FramesetArgument}
 * @param definition Definition of the new {@link FramesetArgument}
 */
void Frameset::addArgument(string type, string definition, string function) {
    bool check = false;
    for (FramesetArgument a : framesetArguments) {
        if (a.getArgumentType() == type) {
            a.setDefinition(definition);
            check = true;
            break;
        }
    }
    if (!check) {
        FramesetArgument arg = FramesetArgument(type, definition, function);
        framesetArguments.push_back(arg);
    }
}

/**
 * The deleteArgument method takes a type and a definition of a {@link FramesetArgument} as input, then it searches for the FramesetArgument with these type and
 * definition, and if it finds removes it from the framesetArguments {@link ArrayList}.
 *
 * @param type  Type of the to be deleted {@link FramesetArgument}
 * @param definition Definition of the to be deleted {@link FramesetArgument}
 */
void Frameset::deleteArgument(string type, string definition) {
    int index;
    for (int i = 0; i < framesetArguments.size(); i++) {
        if (framesetArguments.at(i).getArgumentType() == type && framesetArguments.at(i).getDefinition() == definition) {
            index = i;
            break;
        }
    }
    framesetArguments.erase(framesetArguments.begin() + index);
}

/**
 * Accessor for framesetArguments.
 *
 * @return framesetArguments.
 */
vector<FramesetArgument> Frameset::getFramesetArguments() {
    return framesetArguments;
}

/**
 * Accessor for id.
 *
 * @return id.
 */
string Frameset::getId() {
    return id;
}

/**
 * Mutator for id.
 *
 * @param id to set.
 */
void Frameset::setId(string id) {
    this->id = move(id);
}
