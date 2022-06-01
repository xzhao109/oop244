#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds
{
    bool openFile(const char filename[]);
    void closeFile();
    int noOfRecords();

    int strlen(const char *str);
    void strcpy(char *des, const char *src);
}

#endif // !SDDS_UTILS_H