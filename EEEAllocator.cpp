#include "EEEAllocator.h"
#include "Helper.h"

EEEAllocator::EEEAllocator(Vacancy &vacancy, StudentManager &studentMgr)
    : _vacancy(vacancy), _studentMgr(studentMgr)
{
    //
}

void EEEAllocator::round1()
{
    // Float number format: 0.0
    std::cout << std::fixed << std::setprecision(1);

    std::cout << "Round 1" << std::endl;
    std::cout << "=======" << std::endl;
    normalChoice(0);
    std::cout << std::endl;
}

void EEEAllocator::round2()
{
    std::cout << "Round 2" << std::endl;
    std::cout << "=======" << std::endl;

    char specSportName = _vacancy.getSpecialSport();
    for (auto &iter : _specials)
    {
        int avaiable = _vacancy.getNumberFreeSlots(specSportName) + SPECIAL_SLOTS;
        if (avaiable > 0)
        {
            Student student = *iter;
            _vacancy.removeStudent(iter->getSport(0), iter);
            _vacancy.addStudent(specSportName, student);

            std::cout << student.getName() << ' ';
            std::cout << student.getGPA() << ' ';
            std::cout << "stolen from "
                      << Helper::GetSportName(student.getSport(0))
                      << " to " << Helper::GetSportName(specSportName)
                      << std::endl;
        }
    }

    std::cout << std::endl;
}

void EEEAllocator::round3()
{
    std::cout << "Round 3" << std::endl;
    std::cout << "=======" << std::endl;
    _studentMgr.pushPrepareToBacklog();
    normalChoice(1);
    std::cout << std::endl;
}

void EEEAllocator::round4()
{
    std::cout << "Round 4" << std::endl;
    std::cout << "=======" << std::endl;
    _studentMgr.pushPrepareToBacklog();
    normalChoice(2);
    std::cout << std::endl;
}

void EEEAllocator::round5()
{
    std::cout << "Final Round" << std::endl;
    std::cout << "===========" << std::endl;

    for (int id = 0; id < NUMBER_SPORTS; ++id)
        while (_studentMgr.getQueueSize() && _vacancy.getNumberFreeSlots(id) > 0)
            _vacancy.addStudentByID(id, _studentMgr.pop());

    std::cout << std::endl;
}

void EEEAllocator::normalChoice(int choice)
{
    int opChoice = choice + 1;
    while (_studentMgr.getQueueSize())
    {
        Student student = _studentMgr.pop();

        char sport = student.getSport(choice);
        if (_vacancy.getNumberFreeSlots(sport) <= 0)
        {
            _studentMgr.prepare(student);
            continue;
        }

        std::list<Student>::iterator iter;
        iter = _vacancy.addStudent(sport, student);
        if (iter->hashSpecial(_vacancy.getSpecialSport()))
            _specials.push_back(iter);

        std::cout << Helper::GetSportName(sport) << std::endl;
        std::cout << student.getName() << ' ';
        std::cout << student.getGPA() << ' ';
        std::cout << "choice " << opChoice << '\n';
    }
}
