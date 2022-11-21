#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Movies.h"
#include "util.h"

std::vector<std::string> readCSV(std::string filename);
std::vector<Movie> parseCSV(std::string filename);
std::vector<Movie> searchMovies(std::vector<Movie> movies, std::string title);


#endif