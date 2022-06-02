/////////////////////////////////////////////////////////
// WorkSho#2  :  Part 1
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 2
/////////////////////////////////////////////////////////

#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

namespace sdds
{
    // declare structure
    struct Student
    {
        char *m_name;
        int m_studentNumber;
        char m_grade;
    };

    void sort();
    bool load(const char filename[]);
    bool load(Student &St);
    void display(const Student &St);
    void display();
    void deallocateMemory();

    // declare global variables
    extern int noOfStudents;
    extern Student *students;
}
#endif // !SDDS_FILE_H_