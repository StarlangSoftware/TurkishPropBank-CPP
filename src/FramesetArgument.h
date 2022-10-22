//
// Created by Olcay Taner Yıldız on 7.10.2018.
//

#ifndef PROPBANK_FRAMESETARGUMENT_H
#define PROPBANK_FRAMESETARGUMENT_H
#include <string>

using namespace std;

class FramesetArgument {
private:
    string argumentType;
    string definition;
    string function;
public:
    FramesetArgument(const string& _argumentType, const string& _definition, const string& _function);
    string getArgumentType();
    string getDefinition();
    string getFunction();
    void setDefinition(const string& _definition);
    void setFunction(const string& _function);
    string to_string();
};


#endif //PROPBANK_FRAMESETARGUMENT_H
