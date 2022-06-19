/////////////////////////////////////////////////////////
// WorkSho#5  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 18
/////////////////////////////////////////////////////////
#ifndef SDDS_CHAPTER_H_
#define SDDS_CHAPTER_H_
#include <iostream>

namespace sdds {
const int MAX_CHAPTER_TITLE = 20;
class Chapter {
    char m_title[MAX_CHAPTER_TITLE + 1];
    int m_num_pages;
    int m_num_words;
    unsigned int m_chapter_number;
    void init_chapter();

   public:
    Chapter();
    Chapter(const char* title_);
    Chapter(const char* title_, int chapter_num, int n_pages, int n_words);
    std::ostream& display(std::ostream&) const;

    // type cast operator
    operator int() const;
    operator double() const;
    operator const char*() const;
    // assignment operator
    Chapter& operator=(const Chapter& chapter);
    // prefix operator
    Chapter& operator++();
    Chapter& operator--();
    // getter function
    int getPages() const;
};

// helper function
std::ostream& operator<<(std::ostream& os, const Chapter& chapter);

}  // namespace sdds
#endif
