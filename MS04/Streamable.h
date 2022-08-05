/////////////////////////////////////////////////////////
// Milestone  :  4
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Aug 5
/////////////////////////////////////////////////////////
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>

namespace sdds {
class Streamable {
   public:
    virtual ~Streamable(){};

    virtual std::ostream& write(std::ostream& os = std::cout) const = 0;
    virtual std::istream& read(std::istream& is = std::cin) = 0;
    virtual bool conIO(std::ios& io) const = 0;
    virtual operator bool() const = 0;
};
std::ostream& operator<<(std::ostream& os, const Streamable& sm);
std::istream& operator>>(std::istream& is, Streamable& sm);
}  // namespace sdds

#endif