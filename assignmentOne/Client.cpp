
#include "Movie.h"

using namespace std;

int main()
{
    movie movie1("movie.data");
    movie movie2("movie2.data");

    // Testing findMovies()
    int position = movie1.findMovies("Titanic");

    cout << "Movie is at position " << position << endl;

    position = movie1.findMovies("Frozen");

    if (position == movie1.getNoMovies())
    {
        cout << "Movie was not found." << endl;
    }

    position = movie2.findMovies("Avatar");

    cout << "Movie is at position " << position << endl;

    // Testing showMovie()
    movie1.showMovie("Titanic");
    movie1.showMovie("Avatar");
    movie1.showMovie("Frozen");

    movie2.showMovie("Avatar");

    // Writing movies to the screen
    cout << endl << "MOVIE COLLECTION 1" << endl;
    movie1.writeMovies(cout);

    cout << endl << "MOVIE COLLECTION 2" << endl;
    movie2.writeMovies(cout);

    // Writing movies to a file
    ofstream output("output.txt");

    if (output.is_open())
    {
        movie1.writeMovies(output);
        movie2.writeMovies(output);

        output.close();

        cout << "Output file created successfully." << endl;
    }
    else
    {
        cout << "Output file could not be opened." << endl;
    }

    system("pause");

    return 0;
}



/*Output
* 
* 
* Movie ID: 101
Movie Name: Titanic
Rating: 4.5
Movie was not found.
Movie ID: 105
Movie Name: Frozen
Rating: 3.9
Movie ID: 201
Movie Name: Avatar
Rating: 4.8

MOVIE COLLECTION 1
Movie ID       Movie Name               Rating
101            Titanic                  4.5
102            StarWars                 4.8
103            Hook                     4.2
104            Batman                   4
105            Frozen                   3.9
Total number of movies: 5

MOVIE COLLECTION 2
Movie ID       Movie Name               Rating
201            Avatar                   4.8
202            Inception                4.7
203            Titanic                  4.9
204            Superman                 4.1
205            Spiderman                4.3
Total number of movies: 5
Output file created successfully.
Press any key to continue . . .


*/
