/////////////////////////////////////////////////////////
// WorkSho#2  :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 2
/////////////////////////////////////////////////////////

#ifndef SDDS_BIRTHDATE_H
#define SDDS_BIRTHDATE_H

namespace sdds
{
    struct Employee
    {
        char *name;
        int month;
        int day;
        int year;
    };

    bool beginSearch(const char *filename);
    bool readBirthDate(int month);
    void sort();
    void displayBirthdays();
    void deallocate();
    void endSearch();

    extern Employee *employees;
    extern int noOfMatchedRecs;
}

#endif // !SDDS_BIRTHDATE_H