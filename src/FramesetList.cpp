//
// Created by Olcay Taner Yıldız on 20.10.2018.
//
#include <string>
#include "FramesetList.h"
#include "XmlDocument.h"

/**
 * A constructor of FramesetList class which reads all frameset files inside the files.txt file. For each
 * filename inside that file, the constructor creates a Frameset and puts in inside the frames ArrayList.
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
 * The size method returns the size of the frames ArrayList.
 *
 * @return the size of the frames ArrayList.
 */
unsigned long FramesetList::size() const{
    return frames.size();
}

/**
 * The getFrameSet method returns the frameset at the given index.
 *
 * @param index  Index of the frameset
 * @return Frameset at the given index.
 */
Frameset FramesetList::getFrameset(unsigned long index) const{
    return frames.at(index);
}

/**
 * The addFrameset method takes a Frameset as input and adds it to the frames ArrayList.
 *
 * @param frameset  Frameset to be added
 */
void FramesetList::addFrameset(const Frameset& frameset) {
    frames.push_back(frameset);
}

/**
 * getFrameSet method returns the Frameset with the given synSet id.
 *
 * @param synSetId  Id of the searched Frameset
 * @return Frameset which has the given id.
 */
Frameset FramesetList::getFrameset(const string& synSetId) const{
    for (Frameset frame : frames){
        if (frame.getId() == synSetId){
            return frame;
        }
    }
}

/**
 * frameExists method checks if there is a Frameset with the given synSet id.
 *
 * @param synSetId  Id of the searched Frameset
 * @return true if the Frameset with the given id exists, false otherwise.
 */
bool FramesetList::frameExists(const string& synSetId) const{
    for (const Frameset& frame : frames){
        if (frame.getId() == synSetId){
            return true;
        }
    }
    return false;
}

/**
 * readFromXML method searches the Frameset with a given synSetId if there is a Frameset with the given synSet id,
 * returns the arguments of that Frameset as an HashMap.
 *
 * @param synSetId  Id of the searched Frameset
 * @return an HashMap containing the arguments of the searched Frameset
 */
map<ArgumentType, string> FramesetList::readFromXML(const string& synSetId) {
    map<ArgumentType, string> frameset;
    for (const Frameset& frame : frames){
        if (frame.getId() == synSetId){
            for (unsigned long i = 0; i < frame.getFramesetArguments().size(); i++){
                frameset.insert_or_assign(getArguments(frame.getFramesetArguments().at(i).getArgumentType()), frame.getFramesetArguments().at(i).getDefinition());
            }
        }
    }
    return frameset;
}
