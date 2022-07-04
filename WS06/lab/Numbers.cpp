/////////////////////////////////////////////////////////
// WorkSho#6  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 2
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Numbers.h"

#include <cstring>
#include <fstream>
#include <iostream>

#include "Numbers.h"  // intentional
using namespace std;

namespace sdds {
Numbers::Numbers() {
    setEmpty();
    m_isOriginal = false;
}

Numbers::Numbers(const char* filename) {
    setEmpty();
    m_isOriginal = true;
    setFilename(filename);
    m_numCount = numberCount();
    if (m_numCount == 0 || !load()) {
        delete[] m_numbers;
        delete[] m_filename;
        setEmpty();
        m_isOriginal = false;
    } else {
        sort();
    }
}

Numbers::~Numbers() {
    save();
    delete[] m_numbers;
    delete[] m_filename;
}

Numbers::Numbers(const Numbers& numbers) {
    setEmpty();
    m_isOriginal = false;
    operator=(numbers);
}

Numbers& Numbers::operator=(const Numbers& numbers) {
    if (this != &numbers) {
        m_numCount = numbers.m_numCount;
        delete[] m_numbers;
        m_numbers = new double[m_numCount + 1];
        for (int i{0}; i < m_numCount; i++) {
            m_numbers[i] = numbers.m_numbers[i];
        }
    }
    return *this;
}

bool Numbers::isEmpty() const {
    return m_numbers == nullptr;
}

void Numbers::setEmpty() {
    m_numbers = nullptr;
    m_filename = nullptr;
    m_numCount = 0;
}

void Numbers::setFilename(const char* filename) {
    delete[] m_filename;
    m_filename = new char[strlen(filename) + 1];
    strcpy(m_filename, filename);
}

void Numbers::sort() {
    int i, j;
    double temp;
    for (i = m_numCount - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
                temp = m_numbers[j];
                m_numbers[j] = m_numbers[j + 1];
                m_numbers[j + 1] = temp;
            }
        }
    }
}

double Numbers::average() const {
    double aver = 0.0;
    if (!isEmpty()) {
        for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
        aver = aver / m_numCount;
    }
    return aver;
}

double Numbers::min() const {
    double minVal = 0.0;
    if (!isEmpty()) {
        minVal = m_numbers[0];
        for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
    }
    return minVal;
}

double Numbers::max() const {
    double maxVal = 0.0;
    if (!isEmpty()) {
        maxVal = m_numbers[0];
        for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
    }
    return maxVal;
}

int Numbers::numberCount() const {
    int rec{0};
    ifstream inf(m_filename);
    while (inf) {
        if (inf.get() == '\n') {
            ++rec;
        }
    }
    return rec;
}

bool Numbers::load() {
    int rec{0};
    if (m_numCount > 0) {
        m_numbers = new double[m_numCount + 1];
        ifstream inf(m_filename);
        while (inf) {
            inf >> m_numbers[rec];
            if (inf) {
                ++rec;
            }
        }
    }
    return (rec == m_numCount);
}

void Numbers::save() {
    if (m_isOriginal && !isEmpty()) {
        ofstream outf(m_filename);
        if (outf) {
            for (int i{0}; i < m_numCount; i++) {
                outf << m_numbers[i] << endl;
            }
        }
    }
}

Numbers& Numbers::operator+=(const double value) {
    double* temp{};
    temp = new double[m_numCount + 1];
    for (int i{0}; i < m_numCount; i++) {
        temp[i] = m_numbers[i];
    }
    temp[m_numCount] = value;
    delete[] m_numbers;
    m_numbers = temp;
    ++m_numCount;
    sort();
    return *this;
}

std::ostream& Numbers::display(std::ostream& os) const {
    if (isEmpty()) {
        os << "Empty list";
    } else {
        os << "=========================" << endl;
        if (m_isOriginal) {
            os << m_filename << endl;
        } else {
            os << "*** COPY ***" << endl;
        }
        for (int i{0}; i < m_numCount; i++) {
            if (i < m_numCount - 1) {
                os << m_numbers[i] << ", ";
            } else {
                os << m_numbers[i] << endl;
            }
        }
        os << "-------------------------" << endl;
        os << "Total of " << m_numCount << " number(s)" << endl;
        os << "Largest number:  " << max() << endl;
        os << "Smallest number: " << min() << endl;
        os << "Average :        " << average() << endl;
        os << "=========================";
    }
    return os;
}

// helper functions
std::ostream& operator<<(std::ostream& os, const Numbers& N) {
    return N.display(os);
}

std::istream& operator>>(std::istream& is, Numbers& N) {
    double value{};
    is >> value;
    N += value;
    return is;
}

}  // namespace sdds
