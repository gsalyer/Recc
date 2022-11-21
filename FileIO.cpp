#include "FileIO.h"

//read csv file into vector of strings
std::vector<std::string> readCSV(std::string filename)
{
    std::ifstream file(filename);
    std::vector<std::string> lines;
    std::string line;
    while (getline(file, line))
    {
        lines.push_back(line);
    }
    return lines;
}

//read csv file into vector of Movie objects
std::vector<Movie> parseCSV(std::string filename)
{
    
}

//search for user's movies by title in the vector of all movies
//use formatTextInput(std::string) to format searchTerm and movie title
std::vector<Movie> searchMovies(std::vector<Movie> movies, std::string searchTerm)
{
    std::vector<Movie> searchResults;
    for (const auto& movie : movies)
    {
        if (formatTextInput(movie.getTitle()).find(formatTextInput(searchTerm)) != std::string::npos)
        {
            searchResults.push_back(movie);
        }
    }
    return searchResults;
}