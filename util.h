#ifndef UTIL_H
#define UTIL_H

#include <string>
//#include <map>
#include <set>
#include <sstream>

namespace UTIL
{
    bool isIgnoreWord(const std::string& word);
    //std::map<std::string, int> tokenize(const std::string& text);
    std::string formatTextInput(const std::string& text);
}

#endif