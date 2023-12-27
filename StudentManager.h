#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Student.h"
#include <queue>

class StudentManager
{
public:
    StudentManager(const char *fname);

    int getQueueSize() const;

    /// Remove student from the queue
    /// @return The student has just been removed
    Student pop();

    void prepare(Student student);

    void pushPrepareToBacklog();

private:
    bool readFromFile(const char *fname);

private:
    std::queue<Student> _backlog;
    std::queue<Student> _prepare;
};

#endif // STUDENT_MANAGER_H
