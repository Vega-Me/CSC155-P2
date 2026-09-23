#ifndef GAME_H
#define GAME_H

#include <string>

using namespace std;

class Game {
private:
    string title;
    string genre;
    int hoursPlayed;
    int rating;

public:
    Game();
    Game(string title, string genre, int hoursPlayed, int rating);

    void setTitle(string title);
    void setGenre(string genre);
    void setHoursPlayed(int hoursPlayed);
    void setRating(int rating);

    string getTitle() const;
    string getGenre() const;
    int getHoursPlayed() const;
    int getRating() const;

    string toString() const;
};

#endif