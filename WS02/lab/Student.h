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