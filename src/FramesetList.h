//
// Created by Olcay Taner Yıldız on 20.10.2018.
//

#ifndef PROPBANK_FRAMELIST_H
#define PROPBANK_FRAMELIST_H
#include <vector>
#include <map>
#include "Frameset.h"

using namespace std;

class FramesetList {
private:
    vector<Frameset> frames;
public:
    FramesetList();
    unsigned long size();
    Frameset getFrameset(unsigned long index);
    void addFrameset(const Frameset& frameset);
    Frameset getFrameset(const string& synSetId);
    bool frameExists(const string& synSetId);
    map<ArgumentType, string> readFromXML(const string& synSetId);
};


#endif //PROPBANK_FRAMELIST_H
