#include "Student.h"

Student::Student(std::string name, float gpa, char sport[], int win[]) : _prio(0)
{
    _name = name;
    _gpa = gpa;
    for (std::size_t i = 0; i < NUMBER_RANKING_SPORTS; ++i)
    {
        _sport[i] = sport[i];
        _win[i] = win[i];
    }
}

std::string Student::getName() const
{
    return _name;
}

float Student::getGPA() const
{
    return _gpa;
}

char Student::getSport(int index) const
{
    if (0 <= index && index < NUMBER_RANKING_SPORTS)
        return _sport[index];
    return '-';
}

int Student::getWin(int index) const
{
    if (0 <= index && index < NUMBER_RANKING_SPORTS)
        return _win[index];
    return -1;
}

bool Student::hashSpecial(char sport) const
{
    for (std::size_t i = 0; i < NUMBER_RANKING_SPORTS; ++i)
        if (_sport[i] == sport && _win[i])
            return true;
    return false;
}

int Student::nextPriority()
{
    return (++_prio) %= NUMBER_RANKING_SPORTS;
}

bool Student::operator<(const Student &other) const
{
    // Sorted by sport name
    if (this->_sport[this->_prio] != other._sport[other._prio])
        return (this->_sport[this->_prio] < other._sport[other._prio]);

    // Sorted by win
    if (this->_win[this->_prio] != other._win[other._prio])
        return (this->_win[this->_prio] < other._win[other._prio]);

    // Sorted by GPA
    return this->_gpa < other._gpa;
}
