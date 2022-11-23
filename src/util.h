#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <set>
#include <sstream>

namespace UTIL
{
    bool isIgnoreWord(const std::string& word);
    std::string formatTextInput(const std::string& text);
}

#endif