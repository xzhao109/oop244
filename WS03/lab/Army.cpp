/////////////////////////////////////////////////////////
// WorkSho#3  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 3
/////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Army.h"
using namespace std;

namespace sdds
{
    void Army::setEmpty()
    {
        nationality[MAX_NAME_LEN] = '\0';
        units = 0;
        power = 0.0;
    }

    void Army::createArmy(const char *country, double pow, int troops)
    {
        setEmpty();

        if (country && country[0] && pow > 0 && troops > 0)
        {
            strncpy(nationality, country, MAX_NAME_LEN);
            power = pow;
            units = troops;
        }
        else
        {
            setEmpty();
        }
    }

    void Army::updateUnits(int troops)
    {
        units += troops;
        power += troops * (0.25);
    }

    const char *Army::checkNationality() const
    {
        return nationality;
    }

    int Army::checkCapacity() const
    {
        return units;
    }

    double Army::checkPower() const
    {
        // return a double type value (precision(1))
        cout.setf(ios::fixed);
        cout.precision(1);
        return power;
    }

    bool Army::isEmpty() const
    {
        bool ok = true;
        if (nationality[0] && units && power)
        {
            ok = false;
        }
        return ok;
    }

    bool Army::isStrongerThan(const Army &army) const
    {
        bool ok = false;
        if (this->checkPower() > army.checkPower())
        {
            ok = true;
        }
        return ok;
    }

    void battle(Army &arm1, Army &arm2)
    {
        if (!(arm1.isEmpty() && arm2.isEmpty()))
        {
            cout << "In battle of " << arm1.checkNationality()
                 << " and " << arm2.checkNationality() << ", ";

            if (arm1.isStrongerThan(arm2))
            {
                cout << arm1.checkNationality() << " is victorious!\n";
                arm2.updateUnits(int((-0.5) * (arm2.checkCapacity())));
            }
            else
            {
                cout << arm2.checkNationality() << " is victorious!\n";
                arm1.updateUnits(int((-0.5) * arm1.checkCapacity()));
            }
        }
    }

    void displayDetails(const Army *armies, int size)
    {
        cout << "Armies reporting to battle: \n";
        for (int i = 0; i < size; i++)
        {
            if (!armies[i].isEmpty())
            {
                cout << "Nationality: " << armies[i].checkNationality()
                     << ", Units Count: " << armies[i].checkCapacity()
                     << ", Power left: " << armies[i].checkPower() << endl;
            }
        }
    }
}
