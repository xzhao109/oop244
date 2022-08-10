/////////////////////////////////////////////////////////
// Milestone  :  5
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Aug 9
/////////////////////////////////////////////////////////
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include <cstring>

#include "Lib.h"
#include "Menu.h"
#include "Publication.h"

namespace sdds {
class LibApp {
    char m_filename[SDDS_CHAR_LEN]{};
    Publication* m_publication[SDDS_LIBRARY_CAPACITY]{};
    int m_numOfLoaded{};
    int m_lastRef{};
    Menu m_typeMenu{"Choose the type of publication:"};
    bool m_changed = false;
    Menu m_mainMenu{"Seneca Library Application"};
    Menu m_exitMenu{"Changes have been made to the data, what would you like to do?"};

    bool confirm(const char* message);
    void load();                        // prints: "Loading Data"<NEWLINE>
    void save();                        // prints: "Saving Data"<NEWLINE>
    int search(int selection, char type);  // prints: "Searching for publication"<NEWLINE>
    void returnPub();
    void newPublication();
    void removePublication();
    void checkOutPub();
    Publication* getPub(int libRef);

   public:
    LibApp(const char filename[SDDS_CHAR_LEN]);
    ~LibApp();
    void run();
};
}  // namespace sdds
#endif  // !SDDS_LIBAPP_H