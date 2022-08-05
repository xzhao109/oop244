// Name: Xiaoyue Zhao
// ID: 124899212
// Email: xzhao109@myseneca.ca
// Date: Aug 5
// Section: ZAA

#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_
#include <iostream>

#include "Book.h"
#include "Card.h"
#include "Collection.h"
#include "Pet.h"
using namespace std;

namespace sdds {
// Find with 3 parameters
// to check if a key value matches an array item at a provided index Arguments
// return true if the element at index i of the array equals the key
// >> find(cCol, ii, "Hearts")
template <typename T1, typename T2>
bool find(Collection<T1>& col, int index, T2 el) {
    return col[index] == el;
}

// Find with 4 parameters
// goes through all the elements of the array of objects
// checks if the keys are comparable to the array object
// returns an int that represents the index of a found item that matches the 2 search keys
// returns -1 if no successful matches were found
// >> index = find(cCol, cCol.size(), valuesToSearch[ii], suits[ii]);
template <typename T1, typename T2, typename T3>
int find(Collection<T1>& col, int size, T2 el1, T3 el2) {
    int index = -1;
    for (int i{0}; i < size; i++) {
        if (col[i] == el1 && col[i] == el2) {
            index = i;
        }
    }
    return index;
}

// Insertion operator
// Lists all the elements of an array.
// It will iterate over every item in the collection and insert it into the ostream parameter.
// return ostream  at end.
// >> cout << cCol;
template <typename T>
std::ostream& operator<<(std::ostream& os, Collection<T>& col) {
    for (int i{0}; i < col.size(); i++) {
        os << col[i] << endl;
    }
    return os;
}

// Load Collection
// It will call the overloaded += operator in the collections class to add the new item.
// >> loadCollection(cCol, C[ii]);
template <typename T>
Collection<T> loadCollection(Collection<T>& col, T el) {
    col += el;
    return col;
}

}  // namespace sdds
#endif  // !SDDS_SEARCH_H_
