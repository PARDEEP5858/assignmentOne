
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_MOVIES = 83;

struct MovieInfo
{
    int movieID;
    string movieName;
    double rate;
};

class movie
{
private:
    int maxMovies;
    int noMovies;
    MovieInfo movies[MAX_MOVIES];

public:

    void showMovie(string movieName);

    int getNoMovies() { return noMovies; }

    int findMovies(string movieName);

    movie(string fileName, int maximum = MAX_MOVIES);

    // movieID: movie ID
    // movieName: movie name
    // rate: movie rating
    void addMovie(int movieID, string movieName, double rate);

    void writeMovies(ostream& output);
};
