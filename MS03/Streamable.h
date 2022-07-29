#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>

#include "Publication.h"

namespace sdds {
class Streamable {
   public:
    virtual ~Streamable(){};

    virtual std::ostream& write(std::ostream& os = std::cout) const;
    virtual std::istream& read(std::istream& is = std::cin);
    virtual bool conIO(ios& io) const;
    virtual operator bool() const;
};
std::ostream& operator<<(std::ostream& os, const Streamable& sm);
std::istream& operator>>(std::istream& is, Streamable& sm);
}  // namespace sdds

#endif