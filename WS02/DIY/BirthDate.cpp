#define _CRT_SECURE_NO_WARNINGS
#include "BirthDate.h"
#include "Utils.h"
#include <iostream>
using namespace std;
using namespace sdds;

namespace sdds
{
    // FILE *fptr = nullptr;
    Employee *employees{nullptr};
    int noOfEmployees = 0;
    int noOfRecs = 0;

    bool beginSearch(const char *filename)
    {
        bool ok = false;

        if (openFile(filename))
        {
            cout << "BirthDate Search Program\n";
            ok = true;
        }
        else
        {
            cout << "Data file \"" << filename << "\" not found!";
            ok = false;
        }
        closeFile();
        return ok;
    }

    bool readBirthDate(int month)
    {
        int i = 0;
        bool ok = false;
        Employee temp{};

        noOfEmployees = noOfRecords();
        employees = new Employee[noOfEmployees];

        if (noOfEmployees > 0)
        {
            while (i < noOfEmployees && fscanf(fptr, "%[^,],%d/%d/%d\n",
                                               temp.name, &temp.month, &temp.day, &temp.year) == 4)
            {
                i++;
                ok = true;

                if (temp.month == month)
                {
                    noOfRecs++;

                    employees[i].name = new char[strlen(temp.name) + 1];
                    strcpy(employees[i].name, temp.name);
                    employees[i].month = temp.month;
                    employees[i].day = temp.day;
                    employees[i].year = temp.year;
                }
            }
            rewind(fptr);
        }
        return ok;
    }

    void sort()
    {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--)
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
        cout << noOfRecs << " birthdates found: \n";

        for (int i = 0; i < noOfRecs; i++)
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
        for (int i = 0; i < noOfEmployees; i++)
        {
            delete[] employees[i].name;
        }
        delete[] employees;
        employees = nullptr;
        noOfEmployees = 0;
    }

    void endSearch()
    {
        closeFile();
        cout << "Birthdate Search Program Closed.\n";
    }
}