//
// Created by Olcay Taner Yıldız on 7.10.2018.
//

#include "Frameset.h"

Frameset::Frameset(string id) {
    this->id = move(id);
}

Frameset::Frameset(XmlDocument xmlDocument) {
    XmlElement* element, *argument;
    xmlDocument.parse();
    element = xmlDocument.getFirstChild();
    id = move(element->getAttributeValue("id"));
    argument = element->getFirstChild();
    while (argument != nullptr){
        FramesetArgument framesetArgument = FramesetArgument(argument->getAttributeValue("name"), argument->getPcData());
        framesetArguments.push_back(framesetArgument);
        argument = argument->getNextSibling();
    }
}

bool Frameset::containsArgument(ArgumentType argumentType) {
    for (FramesetArgument framesetArgument : framesetArguments){
        if (getArguments(framesetArgument.getArgumentType()) == argumentType){
            return true;
        }
    }
    return false;
}

void Frameset::addArgument(string type, string definition) {
    bool check = false;
    for (FramesetArgument a : framesetArguments) {
        if (a.getArgumentType() == type) {
            a.setDefinition(definition);
            check = true;
            break;
        }
    }
    if (!check) {
        FramesetArgument arg = FramesetArgument(type, definition);
        framesetArguments.push_back(arg);
    }
}

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

vector<FramesetArgument> Frameset::getFramesetArguments() {
    return framesetArguments;
}

string Frameset::getId() {
    return id;
}

void Frameset::setId(string id) {
    this->id = move(id);
}
