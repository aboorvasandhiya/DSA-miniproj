#ifndef VACANCY_H
#define VACANCY_H

#include "Student.h"
#include <fstream>
#include <iostream>
#include <list>

#define NUMBER_SPORTS 6
#define SPECIAL_SPORT 6

#define INVALID(value) (value < 0)

const std::list<Student>::iterator INVALID_ITERATOR;

class Vacancy
{
public:
    Vacancy(const char *fname);

    /// Get number of slots by first letter
    /// @return number of slots (-1 if can not find the given sport)
    int getNumberFreeSlots(char sport) const;

    /// Special sport
    char getSpecialSport() const;

    /// Add a student to program
    std::list<Student>::iterator addStudent(char prog, Student student);

    /// Add a student to program by ID
    std::list<Student>::iterator addStudentByID(int id, Student student);

    /// Remove a student from program
    void removeStudent(char program, std::list<Student>::iterator& iter);

private:
    /// Read number of slots and special sport from file
    /// @return true when read successful, false otherwise
    bool readFromFile(const char *fname);

private:
    char _specialSport;
    int _numberOfSlots[NUMBER_SPORTS];
    std::list<Student> _students[NUMBER_SPORTS];
};

#endif // VACANCY_H
