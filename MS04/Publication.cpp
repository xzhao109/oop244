/////////////////////////////////////////////////////////
// Milestone  :  4
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Aug 5
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#define TAB '\t'
#include "Publication.h"

#include <cstring>
#include <iomanip>
#include <iostream>

#include "Date.h"
using namespace std;

namespace sdds {
Publication::Publication() {
    setEmpty();
}
Publication::Publication(const Publication& pb) {
    operator=(pb);
}
Publication& Publication::operator=(const Publication& pb) {
    if (this != &pb) {
        set(pb.m_membership);
        setRef(pb.m_libRef);
        setTitle(pb.m_title);
        setShelfId(pb.m_shelfId);
        setDate(pb.m_date);
    }
    return *this;
}
Publication::~Publication() {
    delete[] m_title;
}
// Modifiers
void Publication::setEmpty() {
    m_title = nullptr;
    m_shelfId[0] = '\0';
    m_membership = 0;
    m_libRef = -1;
    m_date.resetToToday();
}
void Publication::set(int member_id) {
    m_membership = member_id;
}
void Publication::setRef(int value) {
    m_libRef = value;
}
void Publication::resetDate() {
    m_date.resetToToday();
}
void Publication::setTitle(const char* title) {
    delete[] m_title;
    if (title) {
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);
    } else {
        m_title = nullptr;
    }
}
void Publication::setShelfId(const char* shelfId) {
    strncpy(m_shelfId, shelfId, SDDS_SHELF_ID_LEN);
}
void Publication::setDate(const Date date) {
    m_date = date;
}
// Queries
char Publication::type() const {
    return 'P';
}
bool Publication::onLoan() const {
    return m_membership;
}
Date Publication::checkoutDate() const {
    return m_date;
}
bool Publication::operator==(const char* title) const {
    return strstr(m_title, title);
}
Publication::operator const char*() const {
    return m_title;
}
int Publication::getRef() const {
    return m_libRef;
}
// Streamable pure virtual function implementations
bool Publication::conIO(std::ios& io) const {
    return (&io == &cin || &io == &cout);
}
ostream& Publication::write(ostream& os) const {
    if (m_title && m_shelfId[0] && m_date.errCode() == 0) {
        if (conIO(os)) {
            os << "| " << m_shelfId << " | ";
            if (strlen(m_title) > SDDS_TITLE_WIDTH) {
                for (int i{0}; i < SDDS_TITLE_WIDTH; i++) {
                    os << m_title[i];
                }
            } else {
                os.fill('.');
                os << left << setw(SDDS_TITLE_WIDTH) << m_title;
            }
            os << " | ";
            if (onLoan()) {
                os << setw(5) << m_membership;
            } else {
                os << setw(5) << " N/A ";
            };
            os << " | " << right << checkoutDate() << " |";
        } else {
            os << type() << TAB << m_libRef << TAB << m_shelfId << TAB
               << m_title << TAB << m_membership << TAB << m_date;
        }
    }
    return os;
}
std::istream& Publication::read(std::istream& is) {
    char title[SDDS_CHARACTER_LEN + 1]{};
    char shelfId[SDDS_SHELF_ID_LEN + 1]{};
    int libRef = -1;
    int membership{};
    Date date{};

    setEmpty();
    if (conIO(is)) {
        cout << "Shelf No: ";
        is.getline(shelfId, SDDS_SHELF_ID_LEN + 1);
        if (strlen(shelfId) != SDDS_SHELF_ID_LEN) {
            is.setstate(ios::failbit);
        }
        cout << "Title: ";
        is.getline(title, SDDS_CHARACTER_LEN + 1);
        cout << "Date: ";
        is >> date;
    } else {
        is >> libRef;
        is.ignore();
        is.getline(shelfId, SDDS_SHELF_ID_LEN + 1, TAB);
        is.getline(title, SDDS_CHARACTER_LEN + 1, TAB);
        is >> membership;
        is.ignore();
        is >> date;
    }
    if (date.errCode() != 0) {
        is.setstate(ios::failbit);
    }
    if (is) {  // istr is in a valid state
        set(membership);
        setRef(libRef);
        setTitle(title);
        setShelfId(shelfId);
        setDate(date);
    }
    return is;
}
Publication::operator bool() const {
    return m_title && m_shelfId[0];
}
}  // namespace sdds