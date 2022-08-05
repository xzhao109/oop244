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
#include "Book.h"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "Lib.h"
#include "Publication.h"
using namespace std;

namespace sdds {
Book::Book() {
    m_author = nullptr;
}
// rule of three
Book::Book(const Book& book) {
    operator=(book);
}
Book& Book::operator=(const Book& book) {
    if (this != &book) {
        Publication::operator=(book);
        setAuthor(book.m_author);
    }
    return *this;
}
Book::~Book() {
    delete[] m_author;
}
// virtual methods
void Book::setAuthor(const char* author) {
    delete[] m_author;
    if (author) {
        m_author = new char[strlen(author) + 1];
        strcpy(m_author, author);
    } else {
        m_author = nullptr;
    }
}
void Book::set(int member_id) {
    Publication::set(member_id);
    Publication::resetDate();
}
char Book::type() const {
    return 'B';
}
std::ostream& Book::write(std::ostream& os) const {
    Publication::write(os);
    if (m_author) {
        if (Publication::conIO(os)) {
            os << " ";
            if (strlen(m_author) > SDDS_AUTHOR_WIDTH) {
                for (int i{0}; i < SDDS_AUTHOR_WIDTH; i++) {
                    os << m_author[i];
                }
            } else {
                os.fill(' ');
                os << left << setw(SDDS_AUTHOR_WIDTH) << m_author;
            }
            os << " |";
        } else {
            os << TAB << m_author;
        }
    }
    return os;
}
std::istream& Book::read(std::istream& is) {
    char author[SDDS_CHARACTER_LEN + 1]{};
    m_author = nullptr;

    Publication::read(is);
    if (Publication::conIO(is)) {
        is.ignore();
        cout << "Author: ";
        is.getline(author, SDDS_CHARACTER_LEN + 1);
    } else {
        is.ignore();
        is.get(author, SDDS_CHARACTER_LEN + 1);  // does not read '\n'
    }
    if (is) {
        setAuthor(author);
    }
    return is;
}
Book::operator bool() const {
    return m_author && m_author[0];
}
}  // namespace sdds
