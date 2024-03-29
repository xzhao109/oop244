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
        std::cout << "| ";
        std::cout.setf(ios::left);
        std::cout.width(11);
        std::cout.fill(' ');
        std::cout << this->getLocation();

        std::cout.unsetf(ios::left);

        std::cout << "|";
        std::cout.width(8);
        std::cout.fill(' ');
        std::cout.setf(ios::fixed);
        std::cout.precision(1);
        std::cout << this->getBattery();

        std::cout << " | ";
        std::cout.width(18);
        std::cout.fill(' ');
        std::cout << this->getBrush();

        std::cout << " | ";
        std::cout.setf(ios::left);
        std::cout.width(7);

        if (this->m_active) {
            std::cout << "YES"
                      << "|" << std::endl;
        } else {
            std::cout << "NO"
                      << "|" << std::endl;
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

    // DESC method #1
    // for (i = num_bots; i > 0; i--) {
    //     for (j = num_bots - 1; j > num_bots - i; j--) {
    //         if (bot[j].getBattery() > bot[j - 1].getBattery()) {
    //             temp.set(bot[j - 1].getLocation(), bot[j - 1].getBattery(),
    //                      bot[j - 1].getBrush(), bot[j - 1].isActive());

    //             bot[j - 1].set(bot[j].getLocation(), bot[j].getBattery(),
    //                            bot[j].getBrush(), bot[j].isActive());

    //             bot[j].set(temp.getLocation(), temp.getBattery(),
    //                        temp.getBrush(), temp.isActive());
    //         }
    //     }
    // }

    // DESC method #2
    for (i = 0; i < num_bots; ++i) {
        for (j = i + 1; j < num_bots; ++j) {
            if (bot[i].getBattery() < bot[j].getBattery()) {
                temp.set(bot[i].getLocation(), bot[i].getBattery(),
                         bot[i].getBrush(), bot[i].isActive());

                bot[i].set(bot[j].getLocation(), bot[j].getBattery(),
                           bot[j].getBrush(), bot[j].isActive());

                bot[j].set(temp.getLocation(), temp.getBattery(),
                           temp.getBrush(), temp.isActive());
            }
        }
    }
}

int report(CleanerBot* bot, const short num_bots) {
    std::cout << "         ------ Cleaner Bots Report -----" << std::endl;
    std::cout << "     ---------------------------------------" << std::endl;
    std::cout << "| Location   | Battery |  Number of Brushes | Active |" << std::endl;
    std::cout << "|------------+---------+--------------------+--------|" << std::endl;

    // LOW BATTERY WARNING
    displayInfo(bot, num_bots);
    if (noOfLowBattery(bot, num_bots)) {
        std::cout << std::endl;
        std::cout << "|====================================================|" << std::endl;
        std::cout << "| LOW BATTERY WARNING:                               |" << std::endl;
        std::cout << "|====================================================|" << std::endl;
        std::cout << "| Number of robots to be charged: " << noOfLowBattery(bot, num_bots)
                  << "                  |" << std::endl;
        std::cout << "| Sorting robots based on their available power:     |" << std::endl;
        std::cout << "| Location   | Battery |  Number of Brushes | Active |" << std::endl;
        std::cout << "|------------+---------+--------------------+--------|" << std::endl;
    }

    // Sort descending
    sort(bot, num_bots);
    displayInfo(bot, num_bots);
    std::cout << "|====================================================|" << std::endl;

    return 0;
}
}  // namespace sdds
