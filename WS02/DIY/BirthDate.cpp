#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"
#include "BirthDate.h"
#include <iostream>
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

        if (fopen(filename, "r"))
        {
            cout << "BirthDate Search Program\n";
            ok = true;
        }
        else
        {
            cout << "Data file \"" << filename << "\" not found!";
            ok = false;
        }
        // close file
        if (fptr)
            fclose(fptr);
        return ok;
    }

    bool readBirthDate(int month)
    {
        /// calculate total records
        char ch;
        int noOfFileRecs = 0;
        while (fscanf(fptr, "%c", &ch) == 1)
        {
            noOfFileRecs += (ch == '\n');
        }
        rewind(fptr);

        employees = new Employee[noOfFileRecs];

        // match input month
        int i = 0;
        bool ok = false;
        char name[128]{};
        int d = 0, m = 0, y = 0;
        while (fscanf(fptr, "%[^,],%d/%d/%d\n", name, &m, &d, &y) == 4)
        {
            if (m == month)
            {
                i++;
                ok = true;
                noOfMatchedRecs++;

                employees[i].name = new char[strlen(name) + 1];
                strcpy(employees[i].name, name);
                employees[i].month = m;
                employees[i].day = d;
                employees[i].year = y;
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
                else if (employees[j].year == employees[j + 1].year)
                {

                    if (employees[j].month > employees[j + 1].month)
                    {
                        temp = employees[j];
                        employees[j] = employees[j + 1];
                        employees[j + 1] = temp;
                    }
                    else if (employees[j].month == employees[j + 1].month)
                    {
                        if (employees[j].day > employees[j + 1].day)
                        {
                            temp = employees[j];
                            employees[j] = employees[j + 1];
                            employees[j + 1] = temp;
                        }
                        else if (employees[j].day == employees[j + 1].day)
                        {
                            temp = employees[j];
                            employees[j] = employees[j + 1];
                            employees[j + 1] = temp;
                        }
                    }
                }
            }
        }
    }

    void displayBirthdays()
    {
        cout << noOfMatchedRecs << " birthdates found: \n";

        for (int i = 0; i < noOfMatchedRecs; i++)
        {
            cout << i + 1 << ") " << employees[i].name << ":\n"
                 << employees[i].day << "-"
                 << employees[i].month << "-"
                 << employees[i].year << endl;
            cout << "===========================================\n";
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
        if (fptr)
            fclose(fptr);
        cout << "Birthdate Search Program Closed.\n";
    }
}