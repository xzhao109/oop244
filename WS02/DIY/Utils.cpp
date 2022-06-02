#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"

namespace sdds
{
    int strlen(const char *str)
    {
        int len = 0;
        while (str[len])
        {
            len++;
        }
        return len;
    }

    void strcpy(char *des, const char *src)
    {
        int i;
        for (i = 0; src[i]; i++)
        {
            des[i] = src[i];
        }
        des[i] = 0; // null
    }
}