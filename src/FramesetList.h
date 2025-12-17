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
    [[nodiscard]] unsigned long size() const;
    [[nodiscard]] Frameset getFrameset(unsigned long index) const;
    void addFrameset(const Frameset& frameset);
    [[nodiscard]] Frameset getFrameset(const string& synSetId) const;
    [[nodiscard]] bool frameExists(const string& synSetId) const;
    [[nodiscard]] map<ArgumentType, string> readFromXML(const string& synSetId) const;
};


#endif //PROPBANK_FRAMELIST_H
