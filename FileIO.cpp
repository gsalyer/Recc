#include "FileIO.h"

namespace FILEIO
{
    //read csv file into vector of strings
    std::string CSVtoStr(std::string fileName)
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

    //read ojson object into map of Movie objects
    //key is movie id, value is Movie object
    std::map<int, Movie> parseCSV(const jsoncons::ojson& j)
    {
        std::map<int, Movie> movies;
        for (const auto& row : j.array_range())
        {
            Movie movie;
            movie.setId(row["id"].as<int>());
            movie.setTitle(row["title"].as<std::string>());
            movie.addGenreMulti(parseNamesIDs(row["genres"].as<std::string>()));
            movies.insert(std::pair<int, Movie>(movie.getId(), movie));
        }
        return movies;
    }

    //search for user's movies by title in the map of all movies
    //use formatTextInput(std::string) to format searchTerm and movie title
    std::vector<Movie> searchMovies(const std::map<int, Movie>& movies, std::string& searchTerm)
    {
        std::vector<Movie> searchResults;
        for (const auto& movie : movies)
        {
            //if the formatted movie title contains the formatted search term, add it to the search results
            if (UTIL::formatTextInput(movie.second.getTitle()).find(UTIL::formatTextInput(searchTerm)) != std::string::npos)
            {
                searchResults.push_back(movie.second);
            }
        }
        return searchResults;
    }

    //parse string from CSV cell into vector of NamesIDs objects
    //string pattern is "[{'id': <int>, 'name': '<string>'}, ...]"
    std::vector<NamesIDs> parseNamesIDs(std::string cellStr)
    {
        std::vector<NamesIDs> namesIDs;
        std::string idStr;
        std::string nameStr;
        std::string tempStr;
        int id;
        std::string name;
        bool idFlag = false;
        bool nameFlag = false;
        for (const char& c : cellStr)
        {
            if (c == '{')
            {
                continue;
            }
            else if (c == '}')
            {
                id = std::stoi(idStr);
                name = nameStr;
                NamesIDs namesID{id, name};
                namesIDs.push_back(namesID);
                idStr = "";
                nameStr = "";
                idFlag = false;
                nameFlag = false;
            }
            else if (c == ':')
            {
                if (idFlag)
                {
                    idFlag = false;
                    nameFlag = true;
                }
                else if (nameFlag)
                {
                    nameFlag = false;
                }
                else
                {
                    idFlag = true;
                }
            }
            else if (c == '\"')
            {
                continue;
            }
            else if (idFlag)
            {
                idStr += c;
            }
            else if (nameFlag)
            {
                nameStr += c;
            }
        }
        return namesIDs;
    }

    //compare the map of all movies to the map of userGenreWeights
    //calculate the score for each movie in the map by adding all of the userGenreWeights that match the movie's genres
    //return the score in descending order as a multimap
    std::multimap<int, Movie> calcScores(const std::map<int, Movie>& movies, const UserList& user)
    {
        std::multimap<int, Movie> scores;
        for (const auto& movie : movies)
        {
            int score = 0;
            //score genres
            for (const auto& genre : movie.second.getGenres())
            {
                //add all weights to score, weight will be 0 if not in userGenreWeights
                score += user.getUserGenreWeight(genre.id);
            }
            //TODO: score others
            scores.insert(std::pair<int, Movie>(score, movie.second));
        }
        return scores;
    }   
}