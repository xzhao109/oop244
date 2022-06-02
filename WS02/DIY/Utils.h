#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
//#define DEBUG
namespace sdds
{ 
   class Utils {
   public:
      int strlen(const char* str);
      void strcpy(char* des, const char* src);
   };
   extern Utils U;
}

#endif // !SDDS_UTILS_H