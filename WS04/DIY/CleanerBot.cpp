/////////////////////////////////////////////////////////
// WorkSho#4  :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 12
/////////////////////////////////////////////////////////

#include "CleanerBot.h"

#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

namespace sdds {
CleanerBot::CleanerBot() {
    setEmpty();
}

CleanerBot::CleanerBot(const char* m_location,
                       const double m_battery,
                       const int m_brush,
                       const bool m_active) {
    set(m_location, m_battery, m_brush, m_active);
}

CleanerBot::~CleanerBot() {
    deallocate();
}

void CleanerBot::setEmpty() {
    m_location = nullptr;
    m_battery = 0;
    m_brush = 0;
    m_active = false;
}

void CleanerBot::deallocate() {
    delete[] m_location;
    m_location = nullptr;
}

// setter functions
CleanerBot& CleanerBot::set(const char* location,
                            double battery,
                            int brush,
                            bool active) {
    deallocate();

    if (location && location[0] && battery > 0 && brush > 0 &&
        (active == 0 || active == 1)) {
        setLocation(location);
        m_battery = battery;
        m_brush = brush;
        setActive(active);
    } else {
        setEmpty();
    }
    return *this;
}

CleanerBot& CleanerBot::setLocation(const char* location) {
    deallocate();
    m_location = new char[strlen(location) + 1];
    strcpy(m_location, location);
    return *this;
}

CleanerBot& CleanerBot::setActive(const bool active) {
    m_active = active;
    return *this;
}

// getter functions
const char* CleanerBot::getLocation() const {
    return m_location;
}

double CleanerBot::getBattery() const {
    return m_battery;
}

int CleanerBot::getBrush() const {
    return m_brush;
}

bool CleanerBot::isActive() const {
    return m_active;
}

// helper functions
bool CleanerBot::isValid() const {
    return (m_location && m_location[0] && m_battery > 0 &&
            m_brush > 0 && (m_active == 0 || m_active == 1));
}

void CleanerBot::display() const {
    if (isValid()) {
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

        if (this->m_active) {
            cout << "YES"
                 << "|" << endl;
        } else {
            cout << "NO"
                 << "|" << endl;
        }
    }
}

// Global (stand-alone) functions
void displayInfo(const CleanerBot bot[], const short num_bots) {
    for (int i = 0; i < num_bots; i++) {
        if (bot[i].isValid()) {
            bot[i].display();
        }
    }
}

int noOfLowBattery(const CleanerBot bot[], const short num_bots) {
    int counter = 0;
    for (int i = 0; i < num_bots; i++) {
        if (bot[i].isValid() && bot[i].getBattery() < 30.0) {
            counter++;
        }
    }
    return counter;
}

void sort(CleanerBot* bot, const short num_bots) {
    int i, j;
    CleanerBot temp{};

    for (i = num_bots; i > 0; i--) {
        for (j = num_bots - 1; j > num_bots - i; j--) {
            if (bot[j].getBattery() > bot[j - 1].getBattery()) {
                temp.set(bot[j - 1].getLocation(), bot[j - 1].getBattery(),
                         bot[j - 1].getBrush(), bot[j - 1].isActive());

                bot[j - 1].set(bot[j].getLocation(), bot[j].getBattery(),
                               bot[j].getBrush(), bot[j].isActive());

                bot[j].set(temp.getLocation(), temp.getBattery(),
                           temp.getBrush(), temp.isActive());
            }
        }
    }
}

int report(CleanerBot* bot, const short num_bots) {
    cout << "         ------ Cleaner Bots Report -----" << endl;
    cout << "     ---------------------------------------" << endl;
    cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
    cout << "|------------+---------+--------------------+--------|" << endl;

    // LOW BATTERY WARNING
    displayInfo(bot, num_bots);
    if (noOfLowBattery(bot, num_bots)) {
        cout << endl;
        cout << "|====================================================|" << endl;
        cout << "| LOW BATTERY WARNING:                               |" << endl;
        cout << "|====================================================|" << endl;
        cout << "| Number of robots to be charged: " << noOfLowBattery(bot, num_bots)
             << "                  |" << endl;
        cout << "| Sorting robots based on their available power:     |" << endl;
        cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
        cout << "|------------+---------+--------------------+--------|" << endl;
    }

    // Sort descending
    sort(bot, num_bots);
    displayInfo(bot, num_bots);
    cout << "|====================================================|" << endl;

    return 0;
}
}  // namespace sdds
