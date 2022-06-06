/////////////////////////////////////////////////////////
// WorkSho#3  :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 4
/////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "Bar.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace sdds
{
    void Bar::setEmpty()
    {
        barTitle[MAX_TITLE_LEN] = '\0';
        fillSymbol = '\0';
        sampleValue = 0;
    }

    void Bar::set(const char *title, char symbol, int value)
    {
        setEmpty();

        if (isValid())
        {
            strncpy(barTitle, title, MAX_TITLE_LEN);
            fillSymbol = symbol;
            sampleValue = value;
        }
    }

    bool Bar::isValid()
    {
        bool ok = false;
        if (!(sampleValue < 0 || sampleValue > 100))
        {
            ok = true;
        }
        return ok;
    }

    void Bar::draw()
    {
        if (isValid())
        {
            int len = strlen(barTitle);
            
            cout << barTitle;
            for (int i = 0; i < (MAX_TITLE_LEN - len); i++)
            {
                cout << '.';
            }
            cout << '|';
            for (int i = 0; i < (sampleValue / 2); i++)
            {
                cout << fillSymbol;
            }
            cout << "\n";
        }
    }
}