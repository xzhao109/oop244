/////////////////////////////////////////////////////////
// WorkSho#2  :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 2
/////////////////////////////////////////////////////////

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
//#define DEBUG
namespace sdds
<<<<<<< HEAD
{
    // declare class
    class Utils
    {
    public:
        int strlen(const char *str);
        void strcpy(char *des, const char *src);
    };

    // declare global Utils object "U"
    extern Utils U;
=======
{ 
   class Utils {
   public:
      int strlen(const char* str);
      void strcpy(char* des, const char* src);
   };
   extern Utils U;
>>>>>>> d1765f5a53f7f75439193e9aa74d52a345a6af8c
}

#endif // !SDDS_UTILS_H