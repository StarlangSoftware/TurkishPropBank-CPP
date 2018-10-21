//
// Created by Olcay Taner Yıldız on 20.10.2018.
//
#include <string>
#include <fstream>
#include "PredicateList.h"
#include "XmlDocument.h"

unsigned long PredicateList::size() {
    return list.size();
}

Predicate PredicateList::getPredicate(string lemma) {
    return list.find(lemma)->second;
}

PredicateList::PredicateList() {
    ifstream inputStream;
    string fileName;
    XmlElement *frameSetNode, *predicateNode, *roleSetNode, *rolesNode, *roleNode;
    inputStream.open("files-english.txt", ifstream::in);
    while (inputStream.good()){
        getline(inputStream, fileName);
        XmlDocument xmlDocument(fileName);
        xmlDocument.parse();
        frameSetNode = xmlDocument.getFirstChild();
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
    }
    inputStream.close();
}
