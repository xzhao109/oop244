/////////////////////////////////////////////////////////
// WorkSho#5  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 18
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"

#include <cstring>
using namespace std;

namespace sdds {
void Book::init_book() {
    m_title[0] = '\0';
    m_author[0] = '\0';
    m_num_chapters = 0;
    m_num_pages = 0;
}

Book::Book() {
    init_book();
}

Book::Book(const char* title_) {
    init_book();
    strcpy(m_title, title_);
}

Book::Book(const char* title_, const char* author_, double price_) {
    init_book();
    strcpy(m_title, title_);
    strcpy(m_author, author_);
    m_price = price_;
}

// Print a book summary
void Book::summary() {
    cout.setf(ios::left);
    cout << "| ";
    cout.width(MAX_BOOK_TITEL);
    cout << m_title << " | ";
    cout.width(MAX_AUTHOR_NAME);
    cout << m_author << " | ";
    cout.width(3);
    cout << m_num_chapters << "  ";
    cout.width(4);
    cout << m_num_pages << " | ";
    cout.width(6);
    cout << m_price << " |" << endl;
}

// postfix operator
Book& Book::operator++(int) {
    Book temp{*this};
    ++m_num_chapters;
    return *this = temp;
}
int Book::add_chapter(Chapter* chapter) {
    m_chapters[m_num_chapters] = *chapter;
    m_num_pages += chapter->getPages();
    return ++m_num_chapters;
}
std::ostream& Book::display(std::ostream& os) const {
    cout.setf(std::ios::left);
    os << "Title:"
       << "'" << m_title << "'" << endl;
    os << "Author: "
       << "'" << m_author << "'" << endl;
    for (int i = 0; i < m_num_chapters; i++) {
        m_chapters[i].display(os);
    }
    return os;
}
// type cast operator
Book::operator int() const {
    return m_num_chapters;
}
Book::operator bool() const {
    return (m_title[0] && m_author[0] && m_num_chapters && m_chapters->getPages() > 0);
}
Book::operator double() const {
    return (double)m_price;
}
Book::operator const char*() const {
    return (const char*)m_title;
}
// not operator overload
bool Book::operator!() const {
    return !(m_title[0] && m_author[0] && m_num_chapters && m_chapters->getPages() > 0);
}
// +=/-= operator overload
Book& Book::operator+=(Chapter& chapter) {
    add_chapter(&chapter);
    return *this;
}
Book& Book::operator-=(double discount) {
    m_price -= discount;
    return *this;
}

// helper function
std::ostream& operator<<(std::ostream& os, const Book& book) {
    return book.display(os);
}

}  // namespace sdds
