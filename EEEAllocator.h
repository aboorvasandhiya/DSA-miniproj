#ifndef EEE_ALLOCATOR_H
#define EEE_ALLOCATOR_H

#include "Vacancy.h"
#include "StudentManager.h"
#include <iomanip>

#define SPECIAL_SLOTS 3

class EEEAllocator
{
public:
    EEEAllocator(Vacancy &vacancy, StudentManager &studentMgr);

    void round1();
    void round2();
    void round3();
    void round4();
    void round5();

private:
    void normalChoice(int choice);

private:
    Vacancy &_vacancy;
    StudentManager &_studentMgr;
    std::vector<std::list<Student>::iterator> _specials;
};

#endif // EEE_ALLOCATOR_H
