/////////////////////////////////////////////////////////
// WorkSho#2  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 2
/////////////////////////////////////////////////////////

/* --------------------------------------------Í----------
Workshop 2 part 1
Module: N/A
Filename: gradeReport.cpp
  in submission this file will be replaced with main_prof.cpp
  that loads "simpsons.csv" instead
Version 1
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#include "Student.h"
using namespace sdds;

int main()
{
   if (load("students.csv"))
   {
      display();
   }
   deallocateMemory();
   return 0;
}