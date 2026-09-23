#include "Game.h"
#include <stdexcept>

using namespace std;

Game::Game() 
    :title("Unkown"),
    genre("Unkown"),
    hoursPlayed(0),
    rating(1)
    {
    }

Game::Game(string title, string genre, int hoursPlayed, int rating) {
    setTitle(title);
    setGenre(genre);
    setHoursPlayed(hoursPlayed);
    setRating(rating);
    }

void Game::setTitle(string title) {     //going to use try/catch later
    if (title.empty()) {
        throw ("Title of the game cannot be empty.");
    }
    this->title = title;        //because both are named title we point to the class's private variable named title
}

void Game::setGenre(string genre) {
    if (genre.empty()) {
        throw "Genre cannot be empty";
    }
    this->genre = genre;
}

void Game::setHoursPlayed(int hoursPlayed) {
    if (hoursPlayed < 0) {
        throw invalid_argument("Hours played cannot be negative.");
    }

    this->hoursPlayed = hoursPlayed;
}

void Game::setRating(int rating) {
    if (rating < 1 || rating > 10) {
        throw invalid_argument("Rating must be between 1 and 10.");
    }

    this->rating = rating;
}

string Game::getTitle() const {
    return title;
}

string Game::getGenre() const {
    return genre;
}

int Game::getHoursPlayed() const {
    return hoursPlayed;
}

int Game::getRating() const {
    return rating;
}

string Game::toString() const {
    return title + " | " + genre +
           " | Hours: " + to_string(hoursPlayed) +
           " | Rating: " + to_string(rating) + "/10";
}