//
// Created by Olcay Taner YILDIZ on 24.01.2025.
//

#ifndef PROPBANK_ARGUMENTLIST_H
#define PROPBANK_ARGUMENTLIST_H

#include "Argument.h"
#include <vector>

class ArgumentList {
private:
    vector<Argument> arguments;
public:
    explicit ArgumentList(const string& argumentList);
    [[nodiscard]] string to_string() const;
    void updateConnectedId(const string& previousId, const string& currentId) const;
    void addPredicate(const string& predicateId);
    void removePredicate();
    [[nodiscard]] bool containsPredicate() const;
    [[nodiscard]] bool containsPredicateWithId(const string& predicateId) const;
    [[nodiscard]] vector<string> getArguments() const;
    [[nodiscard]] bool containsArgument(const string& argumentType, const string& id) const;
};


#endif //PROPBANK_ARGUMENTLIST_H
