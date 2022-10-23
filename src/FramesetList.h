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
    unsigned long size() const;
    Frameset getFrameset(unsigned long index) const;
    void addFrameset(const Frameset& frameset);
    Frameset getFrameset(const string& synSetId) const;
    bool frameExists(const string& synSetId) const;
    map<ArgumentType, string> readFromXML(const string& synSetId);
};


#endif //PROPBANK_FRAMELIST_H
