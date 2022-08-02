/////////////////////////////////////////////////////////
// Milestone  :  3
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 29
/////////////////////////////////////////////////////////
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include <iostream>

#include "Date.h"
#include "Lib.h"
#include "Streamable.h"

namespace sdds {
class Publication : public Streamable {
    char* m_title{};  // dynamic
    char m_shelfId[SDDS_SHELF_ID_LEN + 1]{};
    int m_membership{};
    int m_libRef{};
    Date m_date{};

   public:
    Publication();
    // rule of three
    Publication(const Publication& pb);
    Publication& operator=(const Publication& pb);
    ~Publication();

    // Modifiers
    virtual void set(int member_id);
    void setRef(int value);
    void resetDate();

    void setEmpty();
    void setTitle(const char* title);
    void setShelfId(const char* shelfId);
    void setDate(const Date date);

    // Queries
    virtual char type() const;
    bool onLoan() const;
    Date checkoutDate() const;
    bool operator==(const char* title) const;
    operator const char*() const;
    int getRef() const;

    // Streamable pure virtual function implementations
    bool conIO(std::ios& io) const;
    std::ostream& write(std::ostream& os) const;
    std::istream& read(std::istream& is);
    operator bool() const;
};
}  // namespace sdds

#endif