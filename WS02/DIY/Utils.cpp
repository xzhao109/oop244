/////////////////////////////////////////////////////////
// WorkSho#2  :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 2
/////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"

namespace sdds
{
    Utils U; // create global Utils object "U"

    int Utils::strlen(const char *str)
    {
        int len = 0;
        while (str[len])
        {
            len++;
        }
        return len;
    }

    void Utils::strcpy(char *des, const char *src)
    {
        int i;
        for (i = 0; src[i]; i++)
        {
            des[i] = src[i];
        }
        des[i] = 0; // null
    }
}