/////////////////////////////////////////////////////////
// WorkSho#3  :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 4
/////////////////////////////////////////////////////////

#ifndef SDDS_BAR_H
#define SDDS_BAR_H

namespace sdds
{
    const int MAX_TITLE_LEN = 20;

    class Bar
    {
    private:
        char barTitle[MAX_TITLE_LEN + 1]{};
        char fillSymbol{};
        int sampleValue{};

    public:
        void setEmpty();
        void set(const char *title, char symbol, int value);
        bool isValid();
        void draw();
    };
}

#endif