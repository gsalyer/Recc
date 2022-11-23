#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
// #include <boost/multi_index_container.hpp>
// #include <boost/multi_index/ordered_index.hpp>
// #include <boost/multi_index/identity.hpp>
// #include <boost/multi_index/member.hpp>
// #include <boost/multi_index/mem_fun.hpp>
#include "util.h"

// using namespace ::boost;
// using namespace ::boost::multi_index;

// struct IndexByID {};
// struct IndexByTitle {};

// typedef multi_index_container<
//     Movie,
//     indexed_by<
//     ordered_unique<tag<IndexByID>, const_mem_fun<Movie, int, &Movie::getId>>,
//     ordered_non_unique<tag<IndexByTitle>, const_mem_fun<Movie, std::string, &Movie::getTitle>>
//     >
// > MovieContainer;

bool operator==(const Movie& lhs, const Movie& rhs);
bool operator==(const Movie& movie, const int& id);
bool operator==(const int& id, const Movie& movie);

struct NamesIDs
{
    int id{0};
    std::string name{"N/A"};
};

class Movie
{
public:
    Movie();
    Movie(int id);
    int getId() const;
    int getUserScore() const;
    std::string getTitle() const;
    std::vector<NamesIDs> getGenres() const;
    void setId(int id);
    void setUserScore(int score);
    void setTitle(std::string title);
    void addGenre(NamesIDs& genre);
    void addGenreMulti(std::vector<NamesIDs> genres);
    void printGenres() const;
private:
    int id{0};
    int userScore{0};
    std::string title{"N/A"};
    std::vector<NamesIDs> genres;
};

class UserList
{
public:
    UserList();
    UserList(std::vector<Movie> userMovies);
    std::vector<Movie> getUserMovies() const;
    void addMovie(Movie& movie);
    void calcWeights();
    int getUserGenreWeight(int id) const;
private:
    std::map<int, int> calcUserGenreWeights();
    std::vector<Movie> userMovies;
    std::map<int, int> userGenreWeights;
};


#endif