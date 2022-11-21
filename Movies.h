#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <vector>
#include <map>

class UserList
{
public:
    UserList();
    UserList(std::vector<Movie> userMovies);
    std::vector<Movie> getUserMovies() const;
    void addMovie(Movie movie);
private:
    std::vector<Movie> userMovies;
};

class Movie
{
public:
    Movie();
    Movie(int id);
    int getId() const;
    std::string getTitle() const;
    std::vector<Genre> getGenres() const;
    void setId(int id);
    void setTitle(std::string title);
    void addGenre(Genre genre);
    void printGenres() const;
private:
    int id{0};
    //int csvRowNum{0};
    std::string title{"N/A"};
    std::vector<Genre> genres;
};

struct Genre
{
    int id{0};
    std::string name{"N/A"};
};

#endif