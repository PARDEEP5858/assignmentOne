
#include "Movie.h"
#include <iomanip>
#include <cstdlib>

using namespace std;

movie::movie(string fileName, int maximum)
{
    maxMovies = maximum;
    noMovies = 0;

    // Check whether the maximum is valid
    if (maxMovies < 1 || maxMovies > MAX_MOVIES)
    {
        maxMovies = MAX_MOVIES;
    }

    ifstream input(fileName);

    if (!input.is_open())
    {
        cout << fileName << " file did not open." << endl;
        system("pause");
        exit(-1);
    }

    for (int index = 0; index < maxMovies; index++)
    {
        // Movie ID
        input >> movies[index].movieID;

        if (input.eof())
        {
            break;
        }

        // Movie name and rating
        input >> movies[index].movieName;
        input >> movies[index].rate;

        if (!input)
        {
            break;
        }

        noMovies++;
    }

    input.close();
}

int movie::findMovies(string movieName)
{
    for (int index = 0; index < noMovies; index++)
    {
        if (movies[index].movieName == movieName)
        {
            return index;
        }
    }

    return noMovies;
}

void movie::showMovie(string movieName)
{
    int position = findMovies(movieName);

    if (position == noMovies)
    {
        cout << "Movie was not found." << endl;
    }
    else
    {
        cout << "Movie ID: " << movies[position].movieID << endl;
        cout << "Movie Name: " << movies[position].movieName << endl;
        cout << "Rating: " << movies[position].rate << endl;
    }
}

void movie::addMovie(int movieID, string movieName, double rate)
{
    if (noMovies < maxMovies)
    {
        movies[noMovies].movieID = movieID;
        movies[noMovies].movieName = movieName;
        movies[noMovies].rate = rate;

        noMovies++;
    }
    else
    {
        cout << "Movie collection is full." << endl;
    }
}

void movie::writeMovies(ostream& output)
{
    output << left << setw(15) << "Movie ID"
        << setw(25) << "Movie Name"
        << setw(15) << "Rating" << endl;

    for (int index = 0; index < noMovies; index++)
    {
        output << left << setw(15) << movies[index].movieID
            << setw(25) << movies[index].movieName
            << setw(15) << movies[index].rate << endl;
    }

    output << "Total number of movies: " << noMovies << endl;
}
