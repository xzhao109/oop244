/////////////////////////////////////////////////////////
// WorkSho#6  :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 3
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Basket.h"

#include <cstring>
#include <fstream>
#include <iostream>

#include "Basket.h"  // intentional
using namespace std;

namespace sdds {
Basket::Basket() {
    setEmpty();
}

Basket::Basket(const Fruit* fruit, const int cnt, const double price) {
    setEmpty();
    set(fruit, cnt, price);
}

Basket::Basket(const Basket& basket) {
    setEmpty();
    operator=(basket);
}

Basket& Basket::operator=(const Basket& basket) {
    if (this != &basket) {
        // shallow copy
        m_cnt = basket.m_cnt;
        m_price = basket.m_price;
        // deep copy
        delete[] m_fruits;
        m_fruits = new Fruit[m_cnt + 1];
        for (int i{0}; i < m_cnt; i++) {
            m_fruits[i] = basket.m_fruits[i];
        }
    }
    return *this;
}

Basket::~Basket() {
    delete[] m_fruits;
}

bool Basket::isEmpty() const {
    return !(m_fruits && m_cnt && m_price);
}

void Basket::setEmpty() {
    m_fruits = nullptr;
    m_cnt = 0;
    m_price = 0;
}

Basket& Basket::set(const Fruit* fruit, const int cnt, const double price) {
    if (fruit && cnt > 0) {
        m_cnt = cnt;
        m_price = price;
        delete[] m_fruits;
        m_fruits = new Fruit[m_cnt + 1];
        for (int i{0}; i < m_cnt; i++) {
            m_fruits[i] = fruit[i];
        }
    } else {
        setEmpty();
    }
    return *this;
}

void Basket::setPrice(double price) {
    m_price = price;
}

Basket::operator bool() const {
    return (m_fruits && m_cnt > 0);
}

Basket& Basket::operator+=(Fruit& fruit) {
    Fruit* temp{};
    temp = new Fruit[m_cnt + 1];
    for (int i{0}; i < m_cnt; i++) {
        temp[i] = m_fruits[i];
    }
    temp[m_cnt] = fruit;
    delete[] m_fruits;
    m_fruits = temp;
    ++m_cnt;
    return *this;
}

std::ostream& Basket::display(std::ostream& os) const {
    if (isEmpty()) {
        os << "The basket is empty!" << endl;
    } else {
        os << "Basket Content:" << endl;
        os.setf(ios::fixed);
        os.precision(2);
        for (int i{0}; i < m_cnt; i++) {
            os.width(10);
            os << m_fruits[i].m_name << ": "
               << m_fruits[i].m_qty << "kg" << endl;
        }
        os << "Price: " << m_price << endl;
    }
    return os;
}

// helper functions
std::ostream& operator<<(std::ostream& os, const Basket& basket) {
    return basket.display(os);
}

}  // namespace sdds