#include "split.h"
#include "string"

std::vector<std::string> split(const std::string& str, char delim)
{
    std::vector<std::string> tokens;

    if (!str.empty())
    {
        size_t start = 0, end;
        do {
            end = str.find(delim, start);
            tokens.push_back(str.substr(start, (end - start)));
            start = end + 1;
        } while (end != std::string::npos);
    }

    return tokens;
}
