#include "Helper.h"
#include "Vacancy.h"

int Helper::GetSportID(const std::string &name)
{
    if (name == "Special:")
        return SPECIAL_SPORT;

    // First letter of sport name
    return GetSportID(name[0]);
}

int Helper::GetSportID(const char letter)
{
    switch (letter)
    {
    case 'C':
        return 0;
    case 'D':
        return 1;
    case 'G':
        return 2;
    case 'R':
        return 3;
    case 'S':
        return 4;
    case 'T':
        return 5;
    }

    return -1;
}

const char *Helper::GetSportName(char sport)
{
    switch (sport)
    {
    case 'C':
        return "Chess";
    case 'D':
        return "Dancing";
    case 'G':
        return "Gaming";
    case 'R':
        return "Running";
    case 'S':
        return "Swimming";
    case 'T':
        return "Tenis";
    default:
        return "Miscellaneous";
    }
}
