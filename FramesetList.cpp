//
// Created by Olcay Taner Yıldız on 20.10.2018.
//
#include <string>
#include <fstream>
#include "FramesetList.h"
#include "XmlDocument.h"

FramesetList::FramesetList() {
    ifstream inputStream;
    string fileName;
    inputStream.open("../files-turkish.txt", ifstream::in);
    while (inputStream.good()){
        getline(inputStream, fileName);
        addFrameset(Frameset(XmlDocument("../Frames-Turkish/" + fileName)));
    }
    inputStream.close();
}

unsigned long FramesetList::size() {
    return frames.capacity();
}

Frameset FramesetList::getFrameset(unsigned long index) {
    return frames.at(index);
}

void FramesetList::addFrameset(Frameset frameset) {
    frames.push_back(frameset);
}

Frameset FramesetList::getFrameset(string synSetId) {
    for (Frameset frame : frames){
        if (frame.getId() == synSetId){
            return frame;
        }
    }
}

bool FramesetList::frameExists(string synSetId) {
    for (Frameset frame : frames){
        if (frame.getId() == synSetId){
            return true;
        }
    }
    return false;
}

map<ArgumentType, string> FramesetList::readFromXML(string synSetId) {
    map<ArgumentType, string> frameset;
    for (Frameset frame : frames){
        if (frame.getId() == synSetId){
            for (unsigned long i = 0; i < frame.getFramesetArguments().capacity(); i++){
                frameset.insert_or_assign(getArguments(frame.getFramesetArguments().at(i).getArgumentType()), frame.getFramesetArguments().at(i).getDefinition());
            }
        }
    }
    return frameset;
}
