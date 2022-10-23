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
    string getArgumentType() const;
    string getDefinition() const;
    string getFunction() const;
    void setDefinition(const string& _definition);
    void setFunction(const string& _function);
    string to_string() const;
};


#endif //PROPBANK_FRAMESETARGUMENT_H
