#define _CRT_SECURE_NO_WARNINGS
#include "Streamable.h"

#include "Date.h"
#include "Publication.h"
// #include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

namespace sdds {
// Streamable::~Streamable(){};

std::ostream& Streamable::write(std::ostream& os) const {
    // If the os argument is a console IO object (use conIO()),
    // print shelfId, title, membership and date attributes as the following format
    // (title is left-justified padded with dots)
    if (conIO(os)) {
        os.fill('.');
        os << "| " << Publication::getSheifId()
           << " | " << left << setw(30) << Publication::getSheifId()
           << " | " << Publication::getMembership()  //"N/A
           << " | " << Publication::checkoutDate()
           << " |" << '\n';
    } else {
        // Otherwise:
        // Print the type() and then libRef, shelfId, title,
        // membership and date attributes in a tab-separated format.
        os << Publication::type;
    }
    return os;
}
std::istream& Streamable::read(std::istream& is) {
    char temp[100];
    Date date;

    if (conIO(is)) {  //
        cout << "Shelf No: ";
        is >> temp;
        // Publication::setShelfId(temp);
        cout << "Title: ";
        is >> temp;
        // Publication::setTitle(temp);
        cout << "Date: ";
        is >> date;
        // Publication::resetDate();
    }
    return is;
}
bool Streamable::conIO(std::ios& io) const {
    // Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
    return 2;
}
Streamable::operator bool() const {
    // Returns true if neither of the title or shelfId attributes is null or empty.
    // Otherwise, it will return false.
    return (Publication::getTitle() && Publication::getSheifId());
}
// helper
std::ostream& operator<<(std::ostream& os, const Streamable& sm) {
    // if(valid)
    // then
    return sm.write(os);
}
std::istream& operator>>(std::istream& is, Streamable& sm) {
    return sm.read(is);
}
}  // namespace sdds