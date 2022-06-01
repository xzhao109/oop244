#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include "File.h"
#include <cstdio>

namespace sdds
{
   FILE *fptr;
   bool openFile(const char filename[])
   {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords()
   {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1)
      {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile()
   {
      if (fptr)
         fclose(fptr);
   }

   bool read(char studentName[])
   {
      int ok = 0;
      if (fscanf(fptr, "%[^,],", studentName) == 1)
      {
         ok = 1;
      }
      return ok;
   }
   bool read(int &studentNumber)
   {
      int ok = 0;
      if (fscanf(fptr, "%d,", &studentNumber) == 1)
      {
         ok = 1;
      }
      return ok;
   }
   bool read(char &studentGrade)
   {
      int ok = 0;
      if (fscanf(fptr, "%c\n", &studentGrade) == 1)
      {
         ok = 1;
      }
      return ok;
   }
}