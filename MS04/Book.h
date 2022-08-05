/////////////////////////////////////////////////////////
// Milestone  :  4
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Aug 5
/////////////////////////////////////////////////////////
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>

#include "Publication.h"

namespace sdds {
class Book : public Publication {
    char* m_author{};  // dynamic

   public:
    Book();
    // rule of three
    Book(const Book& book);
    Book& operator=(const Book& book);
    ~Book();

    // virtual methods
    void setAuthor(const char* author);
    virtual void set(int member_id);
    virtual char type() const;
    virtual std::ostream& write(std::ostream& os = std::cout) const;
    virtual std::istream& read(std::istream& is = std::cin);
    virtual operator bool() const;
};
}  // namespace sdds

#endif