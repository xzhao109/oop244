///////////////////////////////////////////////////
// WorkSho#1  :  Part1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  May 19
///////////////////////////////////////////////////

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H 

namespace sdds {
    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);
};

#endif