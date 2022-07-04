/////////////////////////////////////////////////////////
// WorkSho#6  :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 3
/////////////////////////////////////////////////////////
#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H
#include <iostream>

namespace sdds {
struct Fruit {
    char m_name[30 + 1];
    double m_qty;
};

class Basket {
    Fruit* m_fruits{};
    int m_cnt{};
    double m_price{};

   public:
    Basket();
    Basket(const Fruit* fruit, const int cnt, const double price);
    Basket(const Basket& basket);
    Basket& operator=(const Basket& basket);
    ~Basket();

    bool isEmpty() const;
    void setEmpty();
    Basket& set(const Fruit* fruit, const int cnt, const double price);
    void setPrice(double price);

    operator bool() const;
    Basket& operator+=(Fruit& fruit);
    std::ostream& display(std::ostream& os) const;
};

// helper functions
std::ostream& operator<<(std::ostream& os, const Basket& basket);

}  // namespace sdds

#endif