/////////////////////////////////////////////////////////
// Milestone  :  2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 20
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "LibApp.h"

#include <iostream>

#include "Menu.h"
using namespace std;

namespace sdds {
LibApp::LibApp() {
    m_changed = false;
    m_mainMenu.setTitle("Seneca Library Application");
    m_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
    m_mainMenu << "Add New Publication"
               << "Remove Publication"
               << "Checkout publication from library"
               << "Return publication to library";
    m_exitMenu << "Save changes and exit"
               << "Cancel and go back to the main menu";
    load();
}
bool LibApp::confirm(const char* message) {
    Menu confirmMsg(message);
    confirmMsg << "Yes";
    return confirmMsg.run();
}
void LibApp::load() {
    cout << "Loading Data\n";
}
void LibApp::save() {
    cout << "Saving Data\n";
}
void LibApp::search() {
    cout << "Searching for publication\n";
}
void LibApp::returnPub() {
    search();
    cout << "Returning publication\n"
         << "Publication returned\n";
    m_changed = true;
}
void LibApp::newPublication() {
    cout << "Adding new publication to library\n";
    if (confirm("Add this publication to library?")) {
        m_changed = true;
        cout << "Publication added" << endl;
    }
}
void LibApp::removePublication() {
    cout << "Removing publication from library\n";
    search();
    if (confirm("Remove this publication from the library?")) {
        m_changed = true;
        cout << "Publication removed" << endl;
    }
}
void LibApp::checkOutPub() {
    search();
    if (confirm("Check out publication?")) {
        m_changed = true;
        cout << "Publication checked out\n";
    }
}
void LibApp::run() {
    int mainSelection{};
    int exitSelection{};
    do {
        mainSelection = m_mainMenu.run();
        if (mainSelection == 1) {
            newPublication();
            newline();
        } else if (mainSelection == 2) {
            removePublication();
            newline();
        } else if (mainSelection == 3) {
            checkOutPub();
            newline();
        } else if (mainSelection == 4) {
            returnPub();
            newline();
        } else {
            if (m_changed) {
                exitSelection = m_exitMenu.run();
                if (exitSelection == 1) {
                    save();
                } else if (exitSelection == 2) {
                    newline();
                } else {
                    if (confirm("This will discard all the changes are you sure?")) {
                        m_changed = false;
                    }
                }
            }
        }
    } while (!((!mainSelection && !m_changed) || exitSelection == 1));
    endMsg();
}
void LibApp::endMsg() {
    cout << "\n-------------------------------------------"
         << "\nThanks for using Seneca Library Application\n";
}
void LibApp::newline() {
    cout << '\n';
}
}  // namespace sdds