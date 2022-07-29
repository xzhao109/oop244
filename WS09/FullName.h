#define SDDS_FULLNAME_H
#include "Name.h"

namespace sdds {
class FullName : public Name {
    char* m_value{};

   public:
    FullName(const char* name = nullptr, const char* lastname = nullptr);
    // Rule of three goes here:
    FullName(const FullName& fullname);
    FullName& operator=(const FullName& fullname);
    virtual ~FullName();

    operator const char*() const;
    virtual operator bool() const;
    virtual std::ostream& display(std::ostream& ostr = std::cout) const;
    virtual std::istream& read(std::istream& istr = std::cin);
};
std::ostream& operator<<(std::ostream& ostr, const FullName& fullname);
std::istream& operator>>(std::istream& istr, FullName& fullname);
}  // namespace sdds

#endif