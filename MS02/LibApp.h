/////////////////////////////////////////////////////////
// Milestone  :  2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 20
/////////////////////////////////////////////////////////
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include <iostream>
#include "Menu.h"

namespace sdds {
class LibApp {
    bool m_changed{};
    Menu m_mainMenu{};
    Menu m_exitMenu{};

    bool confirm(const char* message);
    void load();      // prints: "Loading Data"<NEWLINE>
    void save();      // prints: "Saving Data"<NEWLINE>
    void search();    // prints: "Searching for publication"<NEWLINE>
    void returnPub(); /*  Calls the search() method.
                          prints "Returning publication"<NEWLINE>
                          prints "Publication returned"<NEWLINE>
                          sets m_changed to true;
                      */
    void newPublication();
    void removePublication();
    void checkOutPub();

   public:
    LibApp();
    void run();
    void endMsg();
    void newline();
};
}  // namespace sdds

#endif