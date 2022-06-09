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
        m_price = 0.0;
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

        if (isValid())
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
            cout << "|";
            // cout.setf(ios::left);
            cout.width(12);
            cout << m_type;

            cout << "|";
            // cout.setf(ios::left);
            cout.width(18);
            cout << m_brand;

            cout << "|";
            // cout.setf(ios::left);
            cout.width(18);
            cout << m_model;

            cout << "|" << m_year;
            // cout.setf(ios::right);
            cout.width(3);

            cout << "|" << m_code;
            // cout.setf(ios::right);
            cout.width(4);

            cout << "|";
            // cout.setf(ios::right);
            cout.width(11);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << m_price << "|" << endl;
        }
    }

    bool Car::isValid() const
    {
       return (m_type && m_type[0] && m_brand && m_brand[0] && m_model && m_model[0] &&
          m_year >= 1900 && (m_code >= 100 && m_code <= 999) && m_price > 0);
    }

    bool Car::isSimilarTo(const Car& car) const
    {
       return (strcmp(car.m_type, this->m_type) == 0 && car.m_brand == this->m_brand &&
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
        bool found = false;
        for (int i = 0; !found && i < num_cars; i++)
        {
            if (!car[i].isValid())
            {
                found = true;
            }
        }
        return found;
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
