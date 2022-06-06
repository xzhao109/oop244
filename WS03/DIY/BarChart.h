/////////////////////////////////////////////////////////
// WorkSho#3  :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 4
/////////////////////////////////////////////////////////

#ifndef SDDS_BARCHART_H
#define SDDS_BARCHART_H
#define DEBUG
#include "Bar.h"

namespace sdds
{
    class BarChart
    {
    private:
        char *titleOfChart;
        Bar *bars;
        char fillChar{};
        int sizeOfBars{};
        int noOfAdded{};

    public:
        bool allValid() const;
        void init(const char *title, int noOfSampels, char fill);
        void add(const char *bar_title, int value);
        void draw() const;
        void deallocate();
    };
}

#endif