#include "StudentManager.h"

StudentManager::StudentManager(const char *fname)
{
    if (readFromFile(fname))
        std::cerr << fname << " was read successfully" << std::endl;
    else
        std::cerr << "Failed to read " << fname << std::endl;
}

int StudentManager::getQueueSize() const
{
    return _backlog.size();
}

Student StudentManager::pop()
{
    Student student = _backlog.front();
    _backlog.pop();
    return student;
}

void StudentManager::prepare(Student student)
{
    _prepare.emplace(student);
}

void StudentManager::pushPrepareToBacklog()
{
    _backlog = std::move(_prepare);
}

bool StudentManager::readFromFile(const char *fname)
{
    std::ifstream fstrm(fname);
    if (!fstrm.is_open())
    {
        std::cerr << "Can not open " << fname << std::endl;
        return false;
    }

    std::string name;
    while (std::getline(fstrm, name) && !name.empty())
    {
        float gpa;
        char sport[NUMBER_RANKING_SPORTS];
        int win[NUMBER_RANKING_SPORTS];

        if (!(fstrm >> gpa))
        {
            std::cerr << "Can not read gpa of " << fname << std::endl;
            return false;
        }

        for (size_t i = 0; i < NUMBER_RANKING_SPORTS; ++i)
        {
            if (!(fstrm >> sport[i]))
            {
                std::cerr << "Can not read sport of " << fname << std::endl;
                return false;
            }
        }

        for (size_t i = 0; i < NUMBER_RANKING_SPORTS; ++i)
        {
            if (!(fstrm >> win[i]))
            {
                std::cerr << "Can not read win of " << fname << std::endl;
                return false;
            }
        }

        // Ingore \n caused by operator<<
        // Assume trailing spaces does not greater than 16
        fstrm.ignore(16, '\n');

        // Add student to queue
        _backlog.emplace(name, gpa, sport, win);
    }

    fstrm.close();
    return true;
}
