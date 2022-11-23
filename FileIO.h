#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Movies.h"
#include "util.h"
#include "jsoncons/json.hpp"
#include "jsoncons_ext/csv/csv.hpp"


namespace FILEIO
{
    std::string CSVtoStr(const std::string& filename);
    std::map<int, Movie> parseCSV(const jsoncons::ojson& j);
    std::vector<Movie> searchMovies(const std::map<int, Movie>& movies, std::string& searchTerm);
    std::vector<NamesIDs> parseNamesIDs(std::string cellStr);
    std::multimap<int, Movie> calcScores(const std::map<int, Movie>& movies, const UserList& user);
}


#endif