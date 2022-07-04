/////////////////////////////////////////////////////////
// WorkSho#6  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 2
/////////////////////////////////////////////////////////
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>

namespace sdds {
class Numbers {
    double* m_numbers;
    char* m_filename;
    bool m_isOriginal;
    int m_numCount;

    bool isEmpty() const;
    void setEmpty();
    void setFilename(const char* filename);
    void sort();

   public:
    Numbers();
    Numbers(const char* filename);
    ~Numbers();

    Numbers(const Numbers& numbers);
    Numbers& operator=(const Numbers& numbers);

    double average() const;
    double max() const;
    double min() const;

    int numberCount() const;
    bool load();
    void save();
    Numbers& operator+=(const double value);
    std::ostream& display(std::ostream& os = std::cout) const;
};

// helper functions
std::ostream& operator<<(std::ostream& os, const Numbers& N);
std::istream& operator>>(std::istream& is, Numbers& N);

}  // namespace sdds
#endif  // !SDDS_NUMBERS_H_
