/////////////////////////////////////////////////////////
// WorkSho#3  :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 4
/////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "BarChart.h"
#include "Bar.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace sdds
{
    bool BarChart::allValid() const
    {
        int counter = 0;
        bool ok = false;
        for (int i = 0; i < noOfAdded; i++)
        {
            if (bars[i].isValid())
            {
                counter++;
            }
        }

        if (counter == noOfAdded && noOfAdded == sizeOfBars)
        {
            ok = true;
        }
        return ok;
    }

    void BarChart::init(const char *title, int noOfSampels, char fill)
    {
        titleOfChart = new char[strlen(title) + 1];
        strcpy(titleOfChart, title);
        sizeOfBars = noOfSampels;
        fillChar = fill;
        bars = new Bar[sizeOfBars];
    }

    void BarChart::add(const char *bar_title, int value)
    {
        if (noOfAdded <= sizeOfBars)
        {
            bars[noOfAdded].set(bar_title, this->fillChar, value);
            noOfAdded++;
        }
    }

    void BarChart::draw() const
    {
        if (allValid() && (noOfAdded == sizeOfBars))
        {
            cout << titleOfChart << endl;
            cout << "--------------------------------------------"
                 << "---------------------------\n";
            for (int i = 0; i < sizeOfBars; i++)
            {
                bars[i].draw();
            }
            cout << "--------------------------------------------"
                 << "---------------------------\n";
        }
        else
        {
            cout << "Invalid Chart!\n";
        }
    }

    void BarChart::deallocate()
    {
        delete[] titleOfChart;
        titleOfChart = nullptr;

        delete[] bars;
        bars = nullptr;
    }
}