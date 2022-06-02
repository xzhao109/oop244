/////////////////////////////////////////////////////////
// WorkSho#2  :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 2
/////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utils.h"
#include "BirthDate.h"
using namespace std;
using namespace sdds;

namespace sdds
{
    FILE *fptr = nullptr;
    Employee *employees{nullptr};
    int noOfMatchedRecs = 0;

    bool beginSearch(const char *filename)
    {
        bool ok = false;
        fptr = fopen(filename, "r");
        if (fptr)
        {
            cout << "Birthdate search program\n";
            ok = true;
        }
        else
        {
            cout << "Data file \"" << filename << "\" not found!";
            ok = false;
        }
        return ok;
    }

    bool readBirthDate(int month)
    {
        int i = 0;
        bool ok = false;
        char name[128]{};
        int d = 0, m = 0, y = 0;

        // calculate matched records
        while (fscanf(fptr, "%[^,],%d/%d/%d\n", name, &m, &d, &y) == 4)
        {
            noOfMatchedRecs += (m == month);
        }
        rewind(fptr);

        // dynamically allocate a struct
        employees = new Employee[noOfMatchedRecs];

        while (fscanf(fptr, "%[^,],%d/%d/%d\n", name, &m, &d, &y) == 4)
        {
            if (m == month)
            {
                ok = true;
                // dynamically allocate a char
                employees[i].name = new char[U.strlen(name) + 1];
                U.strcpy(employees[i].name, name);
                employees[i].month = m;
                employees[i].day = d;
                employees[i].year = y;
                i++;
            }
        }
        rewind(fptr);
        return ok;
    }

    void sort()
    {
        int i, j;
        Employee temp;
        for (i = noOfMatchedRecs - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (employees[j].year > employees[j + 1].year)
                {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    void displayBirthdays()
    {
        cout << noOfMatchedRecs << " birthdates found:\n";

        for (int i = 0; i < noOfMatchedRecs; i++)
        {
            cout << i + 1 << ") " << employees[i].name << ":\n"
                 << employees[i].year << "-"
                 << employees[i].month << "-"
                 << employees[i].day << endl;
            cout << "===================================\n";
        }
    }

    void deallocate()
    {
        for (int i = 0; i < noOfMatchedRecs; i++)
        {
            delete[] employees[i].name;
        }
        delete[] employees;
        employees = nullptr;
    }

    void endSearch()
    {
        // close file
        if (fptr)
            fclose(fptr);
        cout << "Birthdate Search Program Closed.\n";
    }
}