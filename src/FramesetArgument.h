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
    string grammaticalCase;
public:
    FramesetArgument(const string& _argumentType, const string& _definition, const string& _function, const string& _grammaticalCase);
    [[nodiscard]] string getArgumentType() const;
    [[nodiscard]] string getDefinition() const;
    [[nodiscard]] string getFunction() const;
    [[nodiscard]] string getGrammaticalCase() const;
    void setDefinition(const string& _definition);
    void setFunction(const string& _function);
    void setGrammaticalCase(const string& _grammaticalCase);
    [[nodiscard]] string to_string() const;
};


#endif //PROPBANK_FRAMESETARGUMENT_H
