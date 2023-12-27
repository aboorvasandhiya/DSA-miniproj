#ifndef HELPER_H
#define HELPER_H

#include <string>

class Helper
{
public:
    /// Get sport ID by name
    static int GetSportID(const std::string &name);

    /// Get sport ID by first letter
    static int GetSportID(const char letter);

    /// Get sport name by first letter
    static const char *GetSportName(char sport);
};

#endif // HELPER_H
