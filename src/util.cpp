#include "util.h"

namespace UTIL
{
    //return true if word is in ignoreWords
    //otherwise return false
    bool isIgnoreWord(const std::string& word)
    {
        //common words to remove from search query
        std::set<std::string> ignoreWords{"a", "an", "and", "are", "as", "at", "for", "from", "in", "is", "of", "or", "that", "the", "this", "to"};
        return (ignoreWords.find(word) != ignoreWords.end()); //return true if word is in ignoreWords, otherwise return false
    }

    std::string formatTextInput(const std::string& text)
    {
        std::string formattedText;
        std::string word;
        std::stringstream ss(text);
        while (ss >> word)
        {
            if (!isIgnoreWord(word)) //ignore common words
            {
                for (const char& c : word)
                {
                    if (isalnum(c)) //ignore non-alphanumeric characters
                    {
                        formattedText += tolower(c);
                    }
                }
            }
        }
        return formattedText; //resulting string is all lowercase and contains no common words or non-alphanumeric characters
    }

    
}