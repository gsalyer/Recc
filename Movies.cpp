#include "Movies.h"

//class UserList
//overloaded constrcutor
UserList::UserList(std::vector<Movie> userMovies)
{
    this->userMovies = userMovies;
}

//get user movies
std::vector<Movie> UserList::getUserMovies() const
{
    return userMovies;
}

//add movie to user list
void UserList::addMovie(Movie movie)
{
    userMovies.push_back(movie);
}