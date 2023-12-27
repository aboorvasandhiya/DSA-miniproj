#include "Vacancy.h"
#include "Helper.h"

Vacancy::Vacancy(const char *fname)
{
    if (readFromFile(fname))
        std::cerr << fname << " was read successfully" << std::endl;
    else
        std::cerr << "Failed to read " << fname << std::endl;
}

int Vacancy::getNumberFreeSlots(char sport) const
{
    int sportID = Helper::GetSportID(sport);
    if (INVALID(sportID))
        return -1;
    return _numberOfSlots[sportID] - _students[sportID].size();
}

char Vacancy::getSpecialSport() const
{
    return _specialSport;
}

std::list<Student>::iterator Vacancy::addStudent(char prog, Student student)
{
    int sportID = Helper::GetSportID(prog);
    if (INVALID(sportID))
    {
        std::cerr << "Invalid program: " << prog << std::endl;
        return INVALID_ITERATOR;
    }

    return addStudentByID(sportID, student);
}

std::list<Student>::iterator Vacancy::addStudentByID(int id, Student student)
{
    if (INVALID(id))
    {
        std::cerr << "Invalid ID: " << id << std::endl;
        return INVALID_ITERATOR;
    }

    return _students[id].insert(_students[id].end(), student);
}

void Vacancy::removeStudent(char program, std::list<Student>::iterator &iter)
{
    int sportID = Helper::GetSportID(program);
    if (INVALID(sportID))
    {
        std::cerr << "Invalid program: " << program << std::endl;
        return (void)false;
    }

    _students[sportID].erase(iter);
}

bool Vacancy::readFromFile(const char *fname)
{
    std::ifstream fstrm(fname);
    if (!fstrm.is_open())
    {
        std::cerr << "Can not open " << fname << std::endl;
        return false;
    }

    std::string sport;
    while (fstrm >> sport)
    {
        int sportId = Helper::GetSportID(sport);
        if (sportId != SPECIAL_SPORT)
        {
            fstrm >> _numberOfSlots[sportId];
            if (INVALID(_numberOfSlots[sportId]))
            {
                std::cerr << "Invalid number of slots" << std::endl;
                return false;
            }
        }
        else
        {
            // Deal with special sport
            fstrm >> _specialSport;
            if (INVALID(Helper::GetSportID(_specialSport)))
            {
                std::cerr << "Invalid special sport" << std::endl;
                return false;
            }
        }
    }

    fstrm.close();
    return true;
}
