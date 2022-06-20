/////////////////////////////////////////////////////////
// WorkSho#5  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 18
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Chapter.h"

#include <cstring>
#include <iostream>
using namespace std;

namespace sdds {
void Chapter::init_chapter() {
    m_title[0] = '\0';
    m_num_pages = 0;
    m_num_words = 0;
    m_chapter_number = 0;
}
Chapter::Chapter() {
    init_chapter();
}

Chapter::Chapter(const char* title_) {
    init_chapter();
    strcpy(m_title, title_);
}
Chapter::Chapter(const char* title_, int chapter_num, int n_pages, int n_words) {
    strcpy(m_title, title_);
    m_chapter_number = chapter_num;
    m_num_pages = n_pages;
    m_num_words = n_words;
}
ostream& Chapter::display(std::ostream& os) const {
    cout.setf(std::ios::left);
    os << "| Chapter ";
    os.width(2);
    os << m_chapter_number << " | ";
    os.width(MAX_CHAPTER_TITLE);
    os << m_title << " |" << endl;
    return os;
}

// type cast operator
Chapter::operator int() const {
    return m_num_pages;
}
Chapter::operator double() const {
    return (double)m_num_words / (double)m_num_pages;
}
Chapter::operator const char*() const {
    return (const char*)m_title;
}
// assignment operator
Chapter& Chapter::operator=(const Chapter& chapter) {
    if (this != &chapter) {
        strcpy(m_title, chapter.m_title);
        m_chapter_number = chapter.m_chapter_number;
        m_num_pages = chapter.m_num_pages;
        m_num_words = chapter.m_num_words;
    }
    return *this;
}
// prefix operator
Chapter& Chapter::operator++() {
    ++m_num_pages;
    return *this;
}
Chapter& Chapter::operator--() {
    --m_num_pages;
    return *this;
}
// getter function
int Chapter::getPages() const {
    return m_num_pages;
}

// helper function
std::ostream& operator<<(std::ostream& os, const Chapter& chapter) {
    return chapter.display(os);
}

}  // namespace sdds
