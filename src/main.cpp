#include "FileIO.h"
#include "Movies.h"
#include "util.h"
#include "jsoncons/json.hpp"
#include "jsoncons_ext/csv/csv.hpp"

int main()
{
    const std::string filename = "../data/tmdb_5000_movies.csv";
    const std::string csvStr = FILEIO::CSVtoStr(filename);
    UserList user;

    jsoncons::csv::csv_options options;
    options.assume_header(true); //first row is header
    const jsoncons::ojson j = jsoncons::csv::decode_csv<jsoncons::ojson>(csvStr, options); //convert csvStr to json object

    const std::map<int, Movie> movies = FILEIO::parseCSV(j); //parse json object into map of Movie objects

    std::cout << "*Movie Recommender 1000*" << std::endl;
    for (int i = 0; i < 5;)
    {
        std::cout << "Search for a movie title to add to your list: " << std::endl;

        std::string searchTerm = "";
        std::cin.ignore();
        std::getline(std::cin, searchTerm);
        std::vector<Movie> searchResults = FILEIO::searchMovies(movies, searchTerm); //search for user's movies by title in the map of all movies
        int resultNum = 1;
        for (const auto& resultMovie : searchResults)
        {
            std::cout << resultNum << ". " << resultMovie.getTitle() << std::endl;
            resultNum++;
        }
        std::cout << "Enter the number of the movie you want to add to your list:" << std::endl;
        std::cout << "Enter 0 if none are correct." << std::endl;
        int choice;
        std::cin >> choice;
        if (choice == 0)
        {
            continue;
        }
        else
        {
            user.addMovie(searchResults.at(choice - 1));
            std::cout << "(" << i + 1 << "/5) " << "Added \"" << searchResults[choice - 1].getTitle() << "\" to your list." << std::endl;
            i++;
        }
    }
    user.calcWeights();
    std::cout << "How many movies would you like to see recommended?" << std::endl;
    int numRecs;
    std::cin >> numRecs;
    std::multimap<int, Movie> recommendations = FILEIO::calcScores(movies, user); //given a map of all movies, return a map of the top n movies based on the total score
    std::cout << "Here are your top " << numRecs << " recommendations:" << std::endl;
    auto itr = recommendations.rbegin();
    for (int i = 0; i < numRecs; i++)
    {
        //point to the current highest score and print the movie title
        std::cout << i + 1 << ". " << itr->second.getTitle() << std::endl;
        //point to the next highest score
        itr = std::next(itr);
    }

    return 0;
}