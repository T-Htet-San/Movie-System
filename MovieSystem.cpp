#include <iostream>
#include <vector>
#include <algorithm> // For sort
#include <string>

using namespace std;

// Complex Abstract Data Type: Movie struct
struct Movie {
    string title;
    string genre;
    double rating;
    int releaseYear;
};

// Function to display a list of movies
void displayMovies(const vector<Movie>& movies) {
    for (const auto& movie : movies) {
        cout << "Title: " << movie.title
             << " | Genre: " << movie.genre
             << " | Rating: " << movie.rating
             << " | Release Year: " << movie.releaseYear << endl;
    }
    cout << endl;
}

// Bubble Sort Algorithm to sort movies by rating (descending order)
void bubbleSortByRating(vector<Movie>& movies) {
    int n = movies.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                swap(movies[j], movies[j + 1]);
            }
        }
    }
}

// Binary Search Algorithm to find a movie by title (case-sensitive)
int binarySearchByTitle(const vector<Movie>& movies, const string& target) {
    int low = 0, high = movies.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (movies[mid].title == target) {
            return mid;  // Movie found
        } else if (movies[mid].title < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;  // Movie not found
}

int main() {
    // Initialize some movie data manually using push_back
    vector<Movie> movieList;

    movieList.push_back({"Inception", "Sci-Fi", 8.8, 2010});
    movieList.push_back({"The Godfather", "Crime", 9.2, 1972});
    movieList.push_back({"The Dark Knight", "Action", 9.0, 2008});
    movieList.push_back({"Schindler's List", "Biography", 8.9, 1993});
    movieList.push_back({"The Shawshank Redemption", "Drama", 9.3, 1994});


    // Sort movies by rating using Bubble Sort
    bubbleSortByRating(movieList);

    cout << "Movies after sorting by rating:" << endl;
    displayMovies(movieList);

    // Search for a movie by title using Binary Search in a loop
    string searchTitle;
    while (true) {
        cout << "Enter the movie title to search (or type 'exit' to quit): ";
        getline(cin, searchTitle);

        if (searchTitle == "exit") {
            cout << "Exiting search." << endl;
            break;
        }

        int index = binarySearchByTitle(movieList, searchTitle);
        if (index != -1) {
            cout << "Movie found: " << movieList[index].title
                 << " | Rating: " << movieList[index].rating << endl;
        } else {
            cout << "Movie not found." << endl;
        }
    }

    return 0;
}

