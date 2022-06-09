#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#define DEBUG

namespace sdds
{
    class Car
    {
    private:
        char* m_type{};
        char* m_brand{}; // << what is Cstring        
        char* m_model{};
        int m_year{};
        int m_code{};
        double m_price{};
        /*
        Valid Car member variable values

        type, not null or empty
        brand, not null or empty
        model, not null or empty
        year >= 1990
        code, three digit integer
        price > 0
        */

        void resetInfo();
        // This method resets the values for all member variables by
        // setting type, brand, and model to nullptr
        // and setting the year, code, and price to 0.

        void deallocate();

    public:
        Car();
        // The default constructor will initialize the member variables by
        // calling the resetInfo() method (the details of this method will be
        // provided in the Private Member section.

        Car(const char* type,
            const char* brand,
            const char* model,
            int year = 2022,
            int code = 100,
            double price = 1.0);
        /*
        This constructor will dynamically keep the values of
        the C-string argument in their corresponding attributes and
        set the rest of the attributes the corresponding argument values
        if they pass validation. Otherwise it will reset the information
         (see void resetInfo())

        When instantiated using this constructor,
        if the year, code or price arguments are not provided
        they will be set to 2022, 100 and 1 using default values for the arguments.
        */

        ~Car();
        // This destructor should deallocate all they dynamically allocated memory.

        Car& setInfo(const char* type,
                     const char* brand,
                     const char* model,
                     int year,
                     int code,
                     double price);
        /*
        This method will first deallocate all the allocated memory
        and then sets the attributes to the corresponding arguments exactly like the 6 argument constructor.
        Note: this function does not have any default values for its arguments.
        In the end, it will return the reference of the current object.
        */

        void printInfo() const;
        // This method prints the values of all the member variables on the screen in following format.
        // Order:
        // TYPE,BRAND,MODEL,YEAR,CODE,PRICE
        // Spacing:
        //| 10  spaces | 16        spaces | 16        spaces | 9999 |  999 | 999999.99 |

        bool isValid() const;
        // This method returns whether all member variables have valid values
        // or not based on the criteria stated at the Private Member Variables.

        bool isSimilarTo(const Car& car) const;
        // This function is to check whether the type, make, brand and year of an object of Car are equal
        // to another object of this class. The function will return true only if all those values match.
    };

    // Global helper functions

    bool has_similar(const Car car[], const int num_cars);
    // Implement a global function in the sdds namespace to check whether
    // there are duplicate entries in the entire inventory.

    /*
    It returns true if it finds two Car objects that have similar information in the car array.
    See below for the function implementation logic:
    {...................................}
    */

    bool has_invalid(const Car car[], const int num_cars);
    // It returns true if it finds an invalid Car in the car array, otherwise it returns false;

    void print(const Car car[], const int num_cars);
    // Implement a global function in the sdds namespace to
    // print and array of valid Cars and ignore the invalid Cars:
}

#endif