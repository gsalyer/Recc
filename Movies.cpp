#include "Movies.h"

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

//prinnt grenre names separated by commas
void Movie::printGenres() const
{
    for (const auto& genre : genres)
    {
        std::cout << genre.name << " ";
    }
    std::cout << std::endl;
}
