//
// Created by Olcay Taner Yıldız on 7.10.2018.
//

#ifndef PROPBANK_FRAMESET_H
#define PROPBANK_FRAMESET_H
#include <string>
#include <vector>
#include "FramesetArgument.h"
#include "ArgumentType.h"
#include "XmlDocument.h"

using namespace std;

class Frameset {
private:
    string id;
    vector<FramesetArgument> framesetArguments;
public:
    explicit Frameset(const string& _id);
    explicit Frameset(XmlElement* frameSetNode);
    bool containsArgument(ArgumentType argumentType) const;
    void addArgument(const string& type, const string& definition, const string& function, const string& grammaticalCase);
    void deleteArgument(const string& type, const string& definition);
    vector<FramesetArgument> getFramesetArguments() const;
    string getId() const;
    void setId(const string& _id);
};


#endif //PROPBANK_FRAMESET_H
