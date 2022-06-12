#define _CRT_SECURE_NO_WARNINGS
#include "CleanerBot.h"
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

namespace sdds
{
    CleanerBot::CleanerBot()
    {
        setEmpty();
    }

    CleanerBot::CleanerBot(const char* m_location,
                           double m_battery,
                           int m_brush,
                           bool m_active)
    {
        set(m_location, m_battery, m_brush, m_active);
    }

    CleanerBot::~CleanerBot()
    {
        deallocate();
    }

    void CleanerBot::setEmpty()
    {
        m_location = nullptr;
        m_battery = 0;
        m_brush = 0;
        m_active = false;
    }

    void CleanerBot::deallocate()
    {
        delete[] m_location;
        m_location = nullptr;
    }

    // setter functions
    CleanerBot& CleanerBot::set(const char* location,
                                double battery,
                                int brush,
                                bool active)
    {
        deallocate();

        if (location && location[0])
        {
            setLocation(location);
        }

        if (battery >= 0.0)
        {
            m_battery = battery;
        }

        if (brush >= 0)
        {
            m_brush = brush;
        }

        if (active == 0 || active == 1)
        {
            setActive(active);
        }

        return *this;
    }

    CleanerBot& CleanerBot::setLocation(const char* location)
    {
        deallocate();
        m_location = new char[strlen(location) + 1];
        strcpy(m_location, location);
        return *this;
    }

    CleanerBot& CleanerBot::setActive(bool active)
    {
        m_active = active;
        return *this;
    }

    // getter functions
    const char* CleanerBot::getLocation() const
    {
        return m_location;
    }

    double CleanerBot::getBattery() const
    {
        return m_battery;
    }

    int CleanerBot::getBrush() const
    {
        return m_brush;
    }

    bool CleanerBot::isActive() const
    {
        // return if a robot is active
        return m_active;
    }

    bool CleanerBot::isValid() const
    {
        return (m_location && m_location[0] && m_battery > 0 && m_brush > 0 &&
                (m_active == 0 || m_active == 1));
    }

    void CleanerBot::display() const
    {
        if (isValid())
        {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(11);
            cout.fill(' ');
            cout << this->getLocation();

            cout.unsetf(ios::left);

            cout << "|";
            cout.width(8);
            cout.fill(' ');
            cout.setf(ios::fixed);
            cout.precision(1);
            cout << this->getBattery();

            cout << " | ";
            cout.width(18);
            cout.fill(' ');
            cout << this->getBrush();

            cout << " | ";
            cout.setf(ios::left);
            cout.width(7);

            if (this->m_active)
            {
                cout << "YES"
                     << "|" << endl;
            }
            else
            {
                cout << "NO"
                     << "|" << endl;
            }
        }
    }

    // Global (stand-alone) functions
    int displayChart(CleanerBot* bot, short num_bots)
    {
        int counter = 0;
        for (int i = 0; i < num_bots; i++)
        {
            if (bot[i].isValid())
            {
                bot[i].display();
                if (bot[i].getBattery() < 30.0)
                {
                    counter++;
                }
            }
        }
        return counter;
    }

    void sort(CleanerBot* bot, short num_bots)
    {
        int i, j;
        CleanerBot temp;

        for (i = num_bots; i > 0; i--)
        {
            for (j = num_bots; j > num_bots - i; j--)
            {
                if (bot[j].getBattery() > bot[j - 1].getBattery())
                {
                    temp = bot[j];
                    bot[j] = bot[j - 1];
                    bot[j - 1] = temp;
                }
            }
        }
    }

    int report(CleanerBot* bot, short num_bots)
    {
        cout << "         ------ Cleaner Bots Report -----" << endl;
        cout << "     ---------------------------------------" << endl;
        cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
        cout << "|------------+---------+--------------------+--------|" << endl;

        // LOW BATTERY WARNING
        int counter = displayChart(bot, num_bots);
        if (counter)
        {
            cout << endl;
            cout << "|====================================================|" << endl;
            cout << "| LOW BATTERY WARNING:                               |" << endl;
            cout << "|====================================================|" << endl;
            cout << "| Number of robots to be charged: " << counter
                 << "                  |" << endl;
            cout << "| Sorting robots based on their available power:     |" << endl;
            cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
            cout << "|------------+---------+--------------------+--------|" << endl;
        }

        // Sort descending
        sort(bot, num_bots);
        displayChart(bot, num_bots);
        cout << "|====================================================|" << endl;

        return 0;
    }
}
