///////////////////////////////////////////////////
// WorkSho#1  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  May 19
///////////////////////////////////////////////////

#ifndef SDDS_FILE_H
#define SDDS_FILE_H 
#include "ShoppingRec.h"

namespace sdds {
    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec* rec);
    void fwriteShoppintRec(const ShoppingRec* rec);
};

#endif