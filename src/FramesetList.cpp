//
// Created by Olcay Taner Yıldız on 20.10.2018.
//
#include <string>
#include <fstream>
#include <iostream>
#include "FramesetList.h"
#include "XmlDocument.h"

/**
 * A constructor of {@link FramesetList} class which reads all frameset files inside the files.txt file. For each
 * filename inside that file, the constructor creates a Frameset and puts in inside the frames {@link ArrayList}.
 */
FramesetList::FramesetList() {
    XmlElement* framesNode, *frameSetNode;
    XmlDocument doc = XmlDocument("turkish-propbank.xml");
    doc.parse();
    framesNode = doc.getFirstChild();
    frameSetNode = framesNode->getFirstChild();
    while (frameSetNode != nullptr){
        addFrameset(Frameset(frameSetNode));
        frameSetNode = frameSetNode->getNextSibling();
    }
}

/**
 * The size method returns the size of the frames {@link ArrayList}.
 *
 * @return the size of the frames {@link ArrayList}.
 */
unsigned long FramesetList::size() {
    return frames.size();
}

/**
 * The getFrameSet method returns the frameset at the given index.
 *
 * @param index  Index of the frameset
 * @return {@link Frameset} at the given index.
 */
Frameset FramesetList::getFrameset(unsigned long index) {
    return frames.at(index);
}

/**
 * The addFrameset method takes a {@link Frameset} as input and adds it to the frames {@link ArrayList}.
 *
 * @param frameset  Frameset to be added
 */
void FramesetList::addFrameset(Frameset frameset) {
    frames.push_back(frameset);
}

/**
 * getFrameSet method returns the {@link Frameset} with the given synSet id.
 *
 * @param synSetId  Id of the searched {@link Frameset}
 * @return {@link Frameset} which has the given id.
 */
Frameset FramesetList::getFrameset(string synSetId) {
    for (Frameset frame : frames){
        if (frame.getId() == synSetId){
            return frame;
        }
    }
}

/**
 * frameExists method checks if there is a {@link Frameset} with the given synSet id.
 *
 * @param synSetId  Id of the searched {@link Frameset}
 * @return true if the {@link Frameset} with the given id exists, false otherwise.
 */
bool FramesetList::frameExists(string synSetId) {
    for (Frameset frame : frames){
        if (frame.getId() == synSetId){
            return true;
        }
    }
    return false;
}

/**
 * readFromXML method searches the {@link Frameset} with a given synSetId if there is a {@link Frameset} with the given synSet id,
 * returns the arguments of that {@link Frameset} as an {@link HashMap}.
 *
 * @param synSetId  Id of the searched {@link Frameset}
 * @return an {@link HashMap} containing the arguments of the searched {@link Frameset}
 */
map<ArgumentType, string> FramesetList::readFromXML(string synSetId) {
    map<ArgumentType, string> frameset;
    for (Frameset frame : frames){
        if (frame.getId() == synSetId){
            for (unsigned long i = 0; i < frame.getFramesetArguments().size(); i++){
                frameset.insert_or_assign(getArguments(frame.getFramesetArguments().at(i).getArgumentType()), frame.getFramesetArguments().at(i).getDefinition());
            }
        }
    }
    return frameset;
}
