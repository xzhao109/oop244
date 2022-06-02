/////////////////////////////////////////////////////////
// WorkSho#2  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 2
/////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"
#include "File.h"
#include "Utils.h"

using namespace std;
using namespace sdds;

namespace sdds
{
   Student *students{nullptr};
   int noOfStudents = 0;

   void sort()
   {
      int i, j;
      Student temp;
      for (i = noOfStudents - 1; i > 0; i--)
      {
         for (j = 0; j < i; j++)
         {
            if (students[j].m_grade > students[j + 1].m_grade)
            {
               temp = students[j];
               students[j] = students[j + 1];
               students[j + 1] = temp;
            }
         }
      }
   }

   bool load(const char filename[])
   {
      int rec = 0;
      bool ok = false;
      if (openFile(filename))
      {
         // dynamically allocate a struct
         noOfStudents = noOfRecords();
         students = new Student[noOfStudents];

         while (rec < noOfStudents && load(students[rec]))
         {
            rec++;
         }
         if (rec == noOfStudents)
         {
            ok = true;
         }
         else
         {
            cout << "Error: incorrect number of records read; "
                    "the data is possibly corrupted."
                 << endl;
         }
         closeFile();
      }
      return ok;
   }

   bool load(Student &Sd)
   {
      char name[128]{};
      bool ok = false;

      if (read(name))
      {
         ok = true;
         // dynamically allocate a char
         Sd.m_name = new char[strlen(name) + 1];
         strcpy(Sd.m_name, name);
         read(Sd.m_studentNumber);
         read(Sd.m_grade);
      }
      else
      {
         Sd.m_name = NULL;
      }
      return ok;
   }

   void display(const Student &Sd)
   {
      cout << Sd.m_name << ", "
           << Sd.m_studentNumber << ": "
           << Sd.m_grade << endl;
   }

   void display()
   {
      sort();
      for (int i = 0; i < noOfStudents; i++)
      {
         cout << (i + 1) << ": ";
         display(students[i]);
      }
   }

   void deallocateMemory()
   {
      for (int i = 0; i < noOfStudents; i++)
      {
         delete[] students[i].m_name;
      }
      delete[] students;
      students = nullptr;
   }
}