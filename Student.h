#ifndef STUDENT_H
#define STUDENT_H

#include <fstream>
#include <iostream>

#define NUMBER_RANKING_SPORTS 3

class Student
{
public:
    Student(std::string name, float gpa, char sport[], int win[]);

    std::string getName() const;

    float getGPA() const;

    char getSport(int index) const;

    int getWin(int index) const;

    bool hashSpecial(char sport) const;

    int nextPriority();

    bool operator<(const Student& other) const;

private:
    std::string _name;
    float _gpa;
    char _sport[NUMBER_RANKING_SPORTS];
    int _win[NUMBER_RANKING_SPORTS];
    int _prio;
};

#endif // STUDENT_H
