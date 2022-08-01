/////////////////////////////////////////////////////////
// WorkSho#9  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 29
/////////////////////////////////////////////////////////
#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>

namespace sdds {
class Name {
    char* m_value{};

   protected:
    const char* getName() const;

   public:
    Name(const char* name);
    // Rule of three goes here:
    Name(const Name& N);
    Name& operator=(const Name& name);
    virtual ~Name();

    operator const char*() const;
    virtual operator bool() const;
    virtual std::ostream& display(std::ostream& ostr = std::cout) const;
    virtual std::istream& read(std::istream& istr = std::cin);
};
std::ostream& operator<<(std::ostream& ostr, const Name& name);
std::istream& operator>>(std::istream& istr, Name& name);
}  // namespace sdds

#endif