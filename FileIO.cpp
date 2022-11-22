#include "FileIO.h"

//read csv file into vector of strings
std::string CSVtoString(std::string fileName)
{
    std::ifstream file(fileName);
    std::string line;
    std::string csvStr;
    while (getline(file, line))
    {
        csvStr += line + "\n";
    }
    return csvStr;
}

//read csv file into vector of Movie objects
// std::vector<Movie> parseCSV(std::string filename)
// {
    
// }

//search for user's movies by title in the vector of all movies
//use formatTextInput(std::string) to format searchTerm and movie title
std::vector<Movie> searchMovies(std::vector<Movie> movies, std::string searchTerm)
{
    std::vector<Movie> searchResults;
    for (const auto& movie : movies)
    {
        if (UTIL::formatTextInput(movie.getTitle()).find(UTIL::formatTextInput(searchTerm)) != std::string::npos)
        {
            searchResults.push_back(movie);
        }
    }
    return searchResults;
}