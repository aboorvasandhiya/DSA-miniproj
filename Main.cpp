#include "EEEAllocator.h"

int main(/* const int argc, const char** argv */)
{
    Vacancy vacancy("Vacancy.txt");
    StudentManager studentMgr("Student.txt");
    EEEAllocator allocator(vacancy, studentMgr);

    allocator.round1();
    allocator.round2();
    allocator.round3();
    allocator.round4();
    allocator.round5();

    return EXIT_SUCCESS;
}
