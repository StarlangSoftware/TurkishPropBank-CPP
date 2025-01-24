//
// Created by Olcay Taner YILDIZ on 24.01.2025.
//

#include "ArgumentList.h"
#include "StringUtils.h"

/**
 * Constructor of argument list from a string. The arguments for a word is a concatenated list of arguments
 * separated via '#' character.
 * @param argumentList String consisting of arguments separated with '#' character.
 */
ArgumentList::ArgumentList(const string &argumentList) {
    vector<string> splitWords = StringUtils::split(argumentList, "#");
    for (const string& item : splitWords){
        arguments.emplace_back(item);
    }
}

/**
 * Overloaded toString method to convert an argument list to a string. Concatenates the string forms of all
 * arguments with '#' character.
 * @return String form of the argument list.
 */
string ArgumentList::to_string() const{
    if (arguments.empty()){
        return "NONE";
    } else {
        string result = arguments[0].to_string();
        for (int i = 1; i < arguments.size(); i++){
            result += "#" + arguments[i].to_string();
        }
        return result;
    }
}

/**
 * Replaces id's of predicates, which have previousId as synset id, with currentId.
 * @param previousId Previous id of the synset.
 * @param currentId Replacement id.
 */
void ArgumentList::updateConnectedId(const string &previousId, const string &currentId) {
    for (Argument argument: arguments){
        if (argument.getId() == previousId){
            argument.setId(currentId);
        }
    }
}

/**
 * Adds a predicate argument to the argument list of this word.
 * @param predicateId Synset id of this predicate.
 */
void ArgumentList::addPredicate(const string &predicateId) {
    if (!arguments.empty() && arguments[0].getArgumentType() == "NONE"){
        arguments.erase(arguments.begin());
    }
    arguments.emplace_back("PREDICATE", predicateId);
}

/**
 * Removes the predicate with the given predicate id.
 */
void ArgumentList::removePredicate() {
    for (int i = 0; i < arguments.size(); i++){
        if (arguments[i].getArgumentType() == "PREDICATE"){
            arguments.erase(arguments.begin() + i);
            break;
        }
    }
}

/**
 * Checks if one of the arguments is a predicate.
 * @return True, if one of the arguments is predicate; false otherwise.
 */
bool ArgumentList::containsPredicate() const{
    for (const Argument& argument: arguments){
        if (argument.getArgumentType() == "PREDICATE"){
            return true;
        }
    }
    return false;
}

/**
 * Checks if one of the arguments is a predicate with the given id.
 * @param predicateId Synset id to check.
 * @return True, if one of the arguments is predicate; false otherwise.
 */
bool ArgumentList::containsPredicateWithId(const string &predicateId) const{
    for (const Argument& argument: arguments){
        if (argument.getArgumentType() == "PREDICATE" && argument.getId() == predicateId){
            return true;
        }
    }
    return false;
}

/**
 * Returns the arguments as an array list of strings.
 * @return Arguments as an array list of strings.
 */
vector<string> ArgumentList::getArguments() {
    vector<string> result;
    result.reserve(arguments.size());
    for (const Argument& argument: arguments){
        result.emplace_back(argument.to_string());
    }
    return result;
}

/**
 * Checks if the given argument with the given type and id exists or not.
 * @param argumentType Type of the argument to search for.
 * @param id Id of the argument to search for.
 * @return True if the argument exists, false otherwise.
 */
bool ArgumentList::containsArgument(const string &argumentType, const string &id) const{
    for (const Argument& argument: arguments){
        if (argument.getArgumentType() == argumentType && argument.getId() == id){
            return true;
        }
    }
    return false;
}
