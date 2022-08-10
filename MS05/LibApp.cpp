/////////////////////////////////////////////////////////
// Milestone  :  5
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Aug 9
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "LibApp.h"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "Book.h"
#include "PublicationSelector.h"
using namespace std;

namespace sdds {
LibApp::LibApp(const char filename[SDDS_CHAR_LEN]) {
    strcpy(m_filename, filename);
    m_numOfLoaded = 0;
    m_lastRef = 0;
    m_changed = false;

    m_mainMenu.setTitle("Seneca Library Application");
    m_mainMenu << "Add New Publication"
               << "Remove Publication"
               << "Checkout publication from library"
               << "Return publication to library";

    m_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
    m_exitMenu << "Save changes and exit"
               << "Cancel and go back to the main menu";

    m_typeMenu.setTitle("Choose the type of publication:");
    m_typeMenu << "Book"
               << "Publication";
    load();
}
LibApp::~LibApp() {
    for (int i{0}; i < m_numOfLoaded; i++) {
        delete m_publication[i];
    }
}
bool LibApp::confirm(const char* message) {
    Menu confirmMsg(message);
    confirmMsg << "Yes";
    return confirmMsg.run();
}
void LibApp::load() {
    cout << "Loading Data\n";
    ifstream inf(m_filename);
    char type{};
    for (int i{0}; inf; i++) {
        inf >> type;
        inf.ignore();
        if (inf) {
            if (type == 'P') {
                m_publication[i] = new Publication;
            } else if (type == 'B') {
                m_publication[i] = new Book;
            } else {
                cout << "no data\n";
            }
            if (m_publication[i] && i < SDDS_LIBRARY_CAPACITY) {
                inf >> *m_publication[i];
                m_lastRef = m_publication[i]->getRef();
                m_numOfLoaded++;
            }
        }
    }
}
void LibApp::save() {
    cout << "Saving Data\n";
    ofstream outf(m_filename);
    for (int i{0}; i < m_numOfLoaded; i++) {
        if (m_publication[i]->getRef()) {
            outf << *m_publication[i] << '\n';
        }
    }
}
void prnPub(Publication* publication[], int size, int ref) {
    for (int i{0}; i < size; i++) {
        if (ref == publication[i]->getRef()) {
            cout << *publication[i] << '\n';
            i = size;
        }
    }
}
int LibApp::search(int selection, char type) {
    int ref{0};
    PublicationSelector ps("Select one of the following found matches:", 15);
    cout << "Publication Title: ";
    char title[SDDS_CHAR_LEN];
    cin.getline(title, SDDS_CHAR_LEN);
    if (selection == 1) {
        for (int i{0}; i < m_numOfLoaded; i++) {
            if (strstr(*m_publication[i], title) && m_publication[i]->getRef() &&
                type == m_publication[i]->type())
                ps << m_publication[i];
        }
    } else if (selection == 2) {
        for (int i{0}; i < m_numOfLoaded; i++) {
            if (strstr(*m_publication[i], title) && !m_publication[i]->onLoan() &&
                m_publication[i]->getRef() && type == m_publication[i]->type()) {
                ps << m_publication[i];
            }
        }
    } else if (selection == 3) {
        for (int i{0}; i < m_numOfLoaded; i++) {
            if (strstr(*m_publication[i], title) && m_publication[i]->onLoan() &&
                m_publication[i]->getRef() && type == m_publication[i]->type()) {
                ps << m_publication[i];
            }
        }
    }
    if (ps) {
        ps.sort();
        ref = ps.run();
        if (ref) {
            prnPub(m_publication, m_numOfLoaded, ref);
        } else {
            cout << "Aborted!\n";
        }
    } else {
        cout << "No matches found!\n";
    }
    return ref;
}
void LibApp::returnPub() {
    cout << "Return publication to the library\n";
    int selection = m_typeMenu.run();
    char type;
    if (selection == 1) {
        type = 'B';
    } else {
        type = 'P';
    }
    int ref = search(3, type);
    if (ref && confirm("Return Publication?")) {
        m_changed = true;
        Date date = getPub(ref)->checkoutDate();
        Date today;
        int days = today - date;
        days -= SDDS_MAX_LOAN_DAYS;
        if (days > 0) {
            cout << fixed;
            cout << setprecision(2);
            cout << "Please pay $" << float(days) * (0.5)
                 << " penalty for being " << days << " days late!\n";
        }
        getPub(ref)->set(0);
        cout << "Publication returned\n";
    }
}
void LibApp::newPublication() {
    if (m_numOfLoaded >= SDDS_LIBRARY_CAPACITY) {
        cout << "Library is at its maximum capacity!\n";
        return;
    }
    cout << "Adding new publication to the library\n";
    int selection = m_typeMenu.run();
    Publication* p = nullptr;
    if (selection == 0) {
        cout << "Aborted!\n";
        return;
    } else if (selection == 1) {
        p = new Book;
        cin >> *p;
    } else if (selection == 2) {
        p = new Publication;
        cin >> *p;
    }
    if (cin.fail()) {
        cout << "\nAborted!\n";
        exit(0);
    }
    if (confirm("Add this publication to the library?")) {
        m_changed = true;
        m_publication[m_numOfLoaded] = p;
        m_lastRef++;
        m_publication[m_numOfLoaded]->setRef(m_lastRef);
        m_numOfLoaded++;
        cout << "Publication added\n";
    }
    if (!*p) {
        cout << "Failed to add publication!\n";
        delete p;
    }
}
Publication* LibApp::getPub(int libRef) {
    for (int i{0}; i < m_numOfLoaded; i++) {
        if (libRef == m_publication[i]->getRef()) {
            return m_publication[i];
        }
    }
    return nullptr;
}
void LibApp::removePublication() {
    cout << "Removing publication from the library\n";
    int selection = m_typeMenu.run();
    char type{};
    if (selection == 1) {
        type = 'B';
    } else {
        type = 'P';
    }
    int ref = search(1, type);
    if (ref && confirm("Remove this publication from the library?")) {
        m_changed = true;
        getPub(ref)->setRef(0);
        cout << "Publication removed\n";
    }
}
void LibApp::checkOutPub() {
    cout << "Checkout publication from the library\n";
    int selection = m_typeMenu.run();
    char type{};
    if (selection == 1) {
        type = 'B';
    } else {
        type = 'P';
    }
    int ref = search(2, type);
    if (ref && confirm("Check out publication?")) {
        m_changed = true;
        int num{};
        cout << "Enter Membership number: ";
        while (true) {
            cin >> num;
            if (num > 9999 && num <= 99999) {
                break;
            }
            cout << "Invalid membership number, try again: ";
        }
        getPub(ref)->set(num);
        cout << "Publication checked out\n";
    }
}
void LibApp::run() {
    while (true) {
        int mainSelection = m_mainMenu.run();
        if (mainSelection == 1) {
            newPublication();
        } else if (mainSelection == 2) {
            removePublication();
        } else if (mainSelection == 3) {
            checkOutPub();
        } else if (mainSelection == 4) {
            returnPub();
        } else if (mainSelection == 0) {
            if (m_changed) {
                int exitSelection = m_exitMenu.run();
                if (exitSelection == 1) {
                    save();
                    break;
                } else if (exitSelection == 2) {
                    ;
                } else if (exitSelection == 0) {
                    if (confirm("This will discard all the changes are you sure?"))
                        break;
                }
            } else
                break;
        }
        cout << '\n';
    }
    cout << "\n-------------------------------------------\n";
    cout << "Thanks for using Seneca Library Application\n";
}
}  // namespace sdds