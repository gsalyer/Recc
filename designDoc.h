/*
* * Design Doc * *
Name:
Garrett Salyer

* Project description:
Given a list of movies from the user, recommend a separate list of new movies.
Assign “weights” to certain movie data such as genre, actors, director, popularity, etc. based on the user’s list of movies.
(e.g. they provide 5 movies that contain the genre “drama”, then “drama” will be weighted 5 “points” when searching for new movies).
This will be done for a few data points, then we can return a small list of movies that “score” the highest based on the weights assigned to each aspect.
Example: user inputs 5 movies, we return the 10 unique movies with the highest total score back.

* Data types used:
vector
map
multimap
set

*Classes:
Movie
Genre

*Subroutine flow:
1. strings of all movies are read in from csv file
2. strings are parsed into Movie objects
3. user enters one movie title
4. movie title is searched for in vector of Movie objects, if not found return to step 3
5. movie is added to user’s list of movies, repeat 3-5 until size of list is 5
6. weights are assigned to each genre based on their frequency in user’s list of movies
7. every Movie object in vector is assigned a score based on the weights assigned to each genre
8. top 10 movies with the highest score are returned in a vector
9. print top 10 movies vector to console


* Algorithms:
//read in movies from json file and store in vector
vector<Movie> readMovies(string filename)
{
    vector<Movie> movies;
    //open csv file
    //create a new Movie object for each row
    //set id, title, tags for each Movie
    //add Movie to vector
    return movies;
}

//search for user's movies by title in the vector of all movies
vector<Movie> searchMovies(vector<Movie> movies, string title)
{
    vector<Movie> searchResults;
    //iterate through movies vector
    //if movie title contains search term, add to searchResults
    return searchResults;
}

//given a vector of user-confirmed movies, calculate the relative weights of each data member

//genre weights
map<Genre, int> genreWeights(vector<Movie> movies)
{
    map<Genre, int> weights;
    //iterate through movies vector
    //for each genre in each movie, add 1 to the weight of that genre
    return weights;
}

//calculate total score of given movie
int calculateScore(Movie movie, map<T1, int> weights)
{
    int score = 0;
    //iterate through movie's data members
    //add matching weights to score
    return score;
}

//given a vector of all movies, return a vector of the top 10 movies based on the total score
mutlimap<int, Movie> recommendMovies(vector<Movie> movies)
{
    multimap<Movie> recommendations;
    //iterate through movies map
    //calculate total score for each movie based on user weights
    //sort movies vector by total score
    //return movies by score in descending order
    return recommendations;
}



**TO DO:
https://github.com/danielaparker/jsoncons/blob/master/doc/ref/csv/csv.md <- maybe use this to parse csv file
*/