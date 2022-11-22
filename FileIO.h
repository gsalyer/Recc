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

std::string CSVtoStr(std::string filename);
std::vector<Movie> parseCSV(std::string filename);
std::vector<Movie> searchMovies(std::vector<Movie> movies, std::string title);


#endif