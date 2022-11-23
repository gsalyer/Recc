#include "Movies.h"

//operator overloading
bool operator==(const Movie& lhs, const Movie& rhs)
{
    return (lhs.getId() == rhs.getId());
}
bool operator==(const Movie& movie, const int& id)
{
    return (movie.getId() == id);
}
bool operator==(const int& id, const Movie& movie)
{
    return (id == movie.getId());
}

//class Movie
//constructors
Movie::Movie() {}
Movie::Movie(int id)
{
    this->id = id;
}

//accessors
int Movie::getId() const
{
    return id;
}

int Movie::getUserScore() const
{
    return userScore;
}

std::string Movie::getTitle() const
{
    return title;
}

std::vector<NamesIDs> Movie::getGenres() const
{
    return genres;
}

//mutators
void Movie::setId(int id)
{
    this->id = id;
}

void Movie::setUserScore(int userScore)
{
    this->userScore = userScore;
}

void Movie::setTitle(std::string title)
{
    this->title = title;
}

//add genre to movie
void Movie::addGenre(NamesIDs& genre)
{
    genres.push_back(genre);
}

//add multiple genres to movie
void Movie::addGenreMulti(std::vector<NamesIDs> genres)
{
    this->genres = genres;
}

//print grenre names separated by commas
void Movie::printGenres() const
{
    for (const auto& genre : genres)
    {
        std::cout << genre.name << " ";
    }
    std::cout << std::endl;
}

//class UserList
//constrcutors
UserList::UserList() {}
UserList::UserList(std::vector<Movie> userMovies)
{
    this->userMovies = userMovies;
}

//accessors
std::vector<Movie> UserList::getUserMovies() const
{
    return userMovies;
}

//add movie to user's list
void UserList::addMovie(Movie& movie)
{
    userMovies.push_back(movie);
}

//call each private function to store weights for each category
void UserList::calcWeights()
{
    userGenreWeights = this->calcUserGenreWeights();
    //TODO: add more weights
}

//calculate weights for each genre and store in map
//weights are calculated by adding the frequency of each genre in the user's list of movies
//weights are stored in a map with the genre id as the key and the weight as the value
std::map<int, int> UserList::calcUserGenreWeights()
{
    std::map<int, int> genreWeights;
    for (const auto& movie : userMovies)
    {
        for (const auto& genre : movie.getGenres())
        {
            //if not found, insert new key-value pair
            if (genreWeights.find(genre.id) == genreWeights.end())
            {
                genreWeights[genre.id] = 1;
            }
            else
            {
                genreWeights[genre.id]++;
            }
        }
    }
    return genreWeights;
}

//return the userGenreWeight for the given genre id
//if not found, return 0
int UserList::getUserGenreWeight(int id) const
{
    auto it = userGenreWeights.find(id);
    if (it != userGenreWeights.end())
    {
        return it->second;
    }
    else
    {
        return 0;
    }
}