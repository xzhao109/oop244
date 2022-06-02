/////////////////////////////////////////////////////////
// WorkSho#2  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 2
/////////////////////////////////////////////////////////

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds
{
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   bool read(char studentName[]);
   bool read(int &studentNumber);
   bool read(char &studentGrade);
}

#endif // !SDDS_FILE_H_