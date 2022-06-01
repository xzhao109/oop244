#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include "File.h"
#include "Utils.h"
#include <iostream>

using namespace std;
using namespace sdds;

namespace sdds
{
   Student *students{nullptr}; // initialize a pointer to be a null pointer
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
         noOfStudents = noOfRecords();
         students = new Student[noOfStudents]; // dynamically allocate an structure

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
      char name[128]{}; // initialize all elements to zero
      bool ok = false;

      if (read(name))
      {
         ok = true;
         Sd.m_name = new char[strlen(name) + 1]; // dynamically allocate an char
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
      cout << Sd.m_name << ", " << Sd.m_studentNumber << ": " << Sd.m_grade << endl;
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