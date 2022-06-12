/////////////////////////////////////////////////////////
// WorkSho#4  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 9
/////////////////////////////////////////////////////////

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds
{
    class Car
    {
    private:
        char* m_type{};
        char* m_brand{};
        char* m_model{};
        int m_year{};
        int m_code{};
        double m_price{};

        void resetInfo();
        void deallocate();

    public:
        Car();
        Car(const char* type,
            const char* brand,
            const char* model,
            int year = 2022,
            int code = 100,
            double price = 1.0);
        ~Car();

        Car& setInfo(const char* type,
                     const char* brand,
                     const char* model,
                     int year,
                     int code,
                     double price);
        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const Car& car) const;
    };

    // Global helper functions
    bool has_similar(const Car car[], const int num_cars);
    bool has_invalid(const Car car[], const int num_cars);
    void print(const Car car[], const int num_cars);
}

#endif