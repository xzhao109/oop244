/////////////////////////////////////////////////////////
// WorkSho#3  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 3
/////////////////////////////////////////////////////////

#ifndef SDDS_ARMY_H
#define SDDS_ARMY_H

namespace sdds
{
    const int MAX_NAME_LEN = 50;

    class Army
    {
    private:
        char nationality[MAX_NAME_LEN + 1]{};
        int units{};
        double power{};

    public:
        void setEmpty();
        void createArmy(const char *country, double pow, int troops);
        void updateUnits(int troops);
        const char *checkNationality() const;
        int checkCapacity() const;
        double checkPower() const;
        bool isEmpty() const;
        bool isStrongerThan(const Army &army) const;
    };

    // Global (stand-alone) functions
    void battle(Army &arm1, Army &arm2);
    void displayDetails(const Army *armies, int size);
}

#endif