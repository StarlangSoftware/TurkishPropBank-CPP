//
// Created by Olcay Taner Yıldız on 20.10.2018.
//
#include <string>
#include <fstream>
#include <iostream>
#include "PredicateList.h"
#include "XmlDocument.h"

/**
 * The size method returns the number of predicates inside the list.
 *
 * @return the size of the list HashMap.
 */
unsigned long PredicateList::size() const{
    return list.size();
}

/**
 * getPredicate method returns the Predicate with the given lemma.
 *
 * @param lemma  Lemma of the searched predicate
 * @return Predicate which has the given lemma.
 */
Predicate PredicateList::getPredicate(const string& lemma) const{
    return list.find(lemma)->second;
}

/**
 * A constructor of PredicateList class which reads all predicate files inside the 'Frames' folder. For each
 * file inside that folder, the constructor creates a Predicate and puts in inside the list HashMap.
 */
PredicateList::PredicateList() {
    XmlElement *framesNode, *frameSetNode, *predicateNode, *roleSetNode, *rolesNode, *roleNode;
    XmlDocument xmlDocument("english-propbank.xml");
    xmlDocument.parse();
    framesNode = xmlDocument.getFirstChild();
    frameSetNode = framesNode->getFirstChild();
    while (frameSetNode != nullptr){
        predicateNode = frameSetNode->getFirstChild();
        while (predicateNode != nullptr){
            if (predicateNode->hasAttributes()){
                string lemma = predicateNode->getAttributeValue("lemma");
                Predicate newPredicate(lemma);
                roleSetNode = predicateNode->getFirstChild();
                while (roleSetNode != nullptr){
                    if (roleSetNode->hasAttributes()){
                        string id = roleSetNode->getAttributeValue("id");
                        string name = roleSetNode->getAttributeValue("name");
                        RoleSet newRoleSet(id, name);
                        rolesNode = roleSetNode->getFirstChild();
                        if (rolesNode != nullptr){
                            roleNode = rolesNode->getFirstChild();
                            while (roleNode != nullptr){
                                if (roleNode->hasAttributes()){
                                    string description = roleNode->getAttributeValue("descr");
                                    string f = roleNode->getAttributeValue("f");
                                    string n = roleNode->getAttributeValue("n");
                                    newRoleSet.addRole(Role(description, f, n));
                                }
                                roleNode = roleNode->getNextSibling();
                            }
                        }
                        newPredicate.addRoleSet(newRoleSet);
                    }
                    roleSetNode = roleSetNode->getNextSibling();
                }
                list.emplace(newPredicate.getLemma(), newPredicate);
            }
            predicateNode = predicateNode->getNextSibling();
        }
        frameSetNode = frameSetNode->getNextSibling();
    }
}

/**
 * The method returns all lemma in the predicate list.
 * @return All lemma in the predicate list.
 */
unordered_set<string> PredicateList::getLemmaList() const{
    unordered_set<string> lemmaList;
    for (auto& iterator : list){
        lemmaList.insert(iterator.first);
    }
    return lemmaList;
}
