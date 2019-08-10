//
// Created by Olcay Taner Yıldız on 7.10.2018.
//

#include "Predicate.h"

/**
 * A constructor of {@link Predicate} class which takes lemma as input and initializes lemma with this input.
 * The constructor also initializes the roleSets array.
 *
 * @param lemma  Lemma of the predicate
 */
Predicate::Predicate(string lemma) {
    this->lemma = move(lemma);
}

/**
 * Accessor for lemma.
 *
 * @return lemma.
 */
string Predicate::getLemma() {
    return lemma;
}

/**
 * The addRoleSet method takes a {@link RoleSet} as input and adds it to the roleSets {@link ArrayList}.
 *
 * @param roleSet  RoleSet to be added
 */
void Predicate::addRoleSet(RoleSet roleSet) {
    roleSets.push_back(roleSet);
}

/**
 * The size method returns the size of the roleSets {@link ArrayList}.
 *
 * @return the size of the roleSets {@link ArrayList}.
 */
unsigned long Predicate::size() {
    return roleSets.capacity();
}

/**
 * The getRoleSet method returns the roleSet at the given index.
 *
 * @param index  Index of the roleSet
 * @return {@link RoleSet} at the given index.
 */
RoleSet Predicate::getRoleSet(unsigned long index) {
    return roleSets.at(index);
}

/**
 * Another getRoleSet method which returns the roleSet with the given roleSet id.
 *
 * @param roleId  Id of the searched roleSet
 * @return {@link RoleSet} which has the given id.
 */
RoleSet Predicate::getRoleSet(string roleId) {
    for (RoleSet roleSet : roleSets){
        if (roleSet.getId() == roleId){
            return roleSet;
        }
    }
}
