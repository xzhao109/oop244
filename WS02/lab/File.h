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