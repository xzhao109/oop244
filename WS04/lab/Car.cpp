/////////////////////////////////////////////////////////
// WorkSho#4  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 9
/////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace sdds
{
    Car::Car()
    {
        resetInfo();
    }

    Car::Car(const char* type,
             const char* brand,
             const char* model,
             int year,
             int code,
             double price)
    {
        setInfo(type, brand, model, year, code, price);
    }

    Car::~Car()
    {
        deallocate();
    }

    void Car::resetInfo()
    {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0;
    }

    void Car::deallocate()
    {
        delete[] m_type;
        m_type = nullptr;
        delete[] m_brand;
        m_brand = nullptr;
        delete[] m_model;
        m_model = nullptr;
    }

    Car& Car::setInfo(const char* type,
                      const char* brand,
                      const char* model,
                      int year,
                      int code,
                      double price)
    {
        deallocate();

        if (type && type[0] && brand && brand[0] && model && model[0] &&
            year >= 1990 && (code >= 100 && code <= 999) && price > 0)
        {
            m_type = new char[strlen(type) + 1];
            strcpy(m_type, type);
            m_brand = new char[strlen(brand) + 1];
            strcpy(m_brand, brand);
            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);
            m_year = year;
            m_code = code;
            m_price = price;
        }
        else
        {
            resetInfo();
        }
        return *this;
    }

    void Car::printInfo() const
    {
        if (isValid())
        {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(11);
            cout.fill(' ');
            cout << m_type;

            cout << "| ";
            cout.setf(ios::left);
            cout.width(17);
            cout.fill(' ');
            cout << m_brand;

            cout << "| ";
            cout.setf(ios::left);
            cout.width(16);
            cout.fill(' ');
            cout << m_model;

            cout.unsetf(ios::left);

            cout << " |";
            cout.width(5);
            cout.fill(' ');
            cout << m_year;

            cout << " |";
            cout.width(5);
            cout.fill(' ');
            cout << m_code;

            cout << " |";
            cout.width(10);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << m_price << " |" << endl;
        }
    }

    bool Car::isValid() const
    {
        return (m_type && m_type[0] && m_brand && m_brand[0] && m_model && m_model[0] &&
                m_year >= 1990 && (m_code >= 100 && m_code <= 999) && m_price > 0);
    }

    bool Car::isSimilarTo(const Car& car) const
    {
        return (car.m_type == this->m_type && car.m_brand == this->m_brand &&
                car.m_model == this->m_model && car.m_year == this->m_year);
    }

    // Global helper functions
    bool has_similar(const Car car[], const int num_cars)
    {
        bool match = false;
        for (int i = 0; !match && i < num_cars; i++)
        {
            for (int j = i + 1; !match && j < num_cars; j++)
            {
                if (car[i].isSimilarTo(car[j]))
                {
                    match = true;
                }
            }
        }
        return match;
    }

    bool has_invalid(const Car car[], const int num_cars)
    {
        bool match = false;
        for (int i = 0; !match && i < num_cars; i++)
        {
            if (!car[i].isValid())
            {
                match = true;
            }
        }
        return match;
    }

    void print(const Car car[], const int num_cars)
    {
        for (int i = 0; i < num_cars; i++)
        {
            if (car[i].isValid())
            {
                car[i].printInfo();
            }
        }
    }
}