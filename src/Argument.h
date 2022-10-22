//
// Created by Olcay Taner Yıldız on 4.10.2018.
//

#ifndef PROPBANK_ARGUMENT_H
#define PROPBANK_ARGUMENT_H
#include <string>

using namespace std;

class Argument {
private:
    string argumentType;
    string id;
public:
    explicit Argument(const string& argument);
    Argument(const string& _argumentType, const string& _id);
    string getArgumentType();
    string getId();
    string to_string();
};


#endif //PROPBANK_ARGUMENT_H
