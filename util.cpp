#include "util.h"

//return true if word is in ignoreWords
//otherwise return false
bool isIgnoreWord(const std::string& word)
{
    std::set<std::string> ignoreWords{"a", "an", "and", "are", "as", "at", "for", "from", "in", "is", "of", "or", "that", "the", "this", "to"};
    return (ignoreWords.find(word) != ignoreWords.end());
}

// std::map<std::string, int> tokenize(const std::string& text)
// {
// }

//return a string with all ignore words removed
//and remove all non-alphanumeric characters
//and convert all characters to lowercase
std::string formatTextInput(const std::string& text)
{
    std::string formattedText;
    std::string word;
    std::stringstream ss(text);
    while (ss >> word)
    {
        if (!isIgnoreWord(word))
        {
            for (const char& c : word)
            {
                if (isalnum(c))
                {
                    formattedText += tolower(c);
                }
            }
        }
    }
    return formattedText;
}