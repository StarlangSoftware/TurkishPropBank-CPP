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
    string getArgumentType() const;
    string getId() const;
    string to_string() const;
    void setId(const string& _id);
};


#endif //PROPBANK_ARGUMENT_H
