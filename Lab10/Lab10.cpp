// CSC 155 - Lab 10 Open-Ended Integration Project
// Student: Marcos Gilbert
// Project title: Game 

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <cctype>

using namespace std;

#include "Game.h"

void displayMenu();
void displayGames(const vector<Game>& games);
void loadGames(const string& fileName, vector<Game>& games);
void searchGames(const vector<Game>& games, string keyword);
void saveGames(const string& fileName, const vector<Game>& games);

void displayStats(const vector<Game>& games);


int main() {
    vector<Game> games;

    try {
        loadGames("games.txt", games);
    } catch (const exception& e) {
        cout << "Error" << e.what() << endl;
        return 0;
    }

    int choice;
    string keyword;
    do {
        displayMenu();
        cin >> choice;
        if (cin.fail()) {cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid input.";}
        if (choice == 1) displayGames(games);
        if (choice == 2) {string keyword; cout << "Enter title keyword: "; getline(cin, keyword); searchGames(games, keyword);}
        if (choice == 3) { 
            string inputTitle; string inputGenre; int inputHours; int inputRating;
            cout << "Enter title: "; getline(cin, inputTitle); getline(cin, inputGenre); cin >> inputHours; cin >> inputRating;
            try {
                Game newGame(inputTitle, inputGenre, inputHours, inputRating);
                games.push_back(newGame);
                cout << "Successfully added game." << endl;
            }
            catch (const exception& e) {
                cout << "Could not add game." << e.what() << endl;
            }
        }
        if (choice == 4) {
            try {
                saveGames("games.txt", games);
            }
            catch (const exception& e) {
                cout << "Save failed." << e.what() << endl;
            }
        }
        if (choice == 5) {
            displayStats(games);
        }
    } while (choice != 0);

    return 0;
}



void displayMenu() {
    cout << "\nGAME BACKLOG TRACKER\n";
    cout << "1. Display all games\n";
    cout << "2. Search games\n";
    cout << "3. Add a game\n";
    cout << "4. Save games\n";
    cout << "5. View Game Statistics\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}


void displayGames(const vector<Game>& games) {
    cout << endl;
    if (games.empty()) {
        cout << "No games are currently loaded" << endl;
        return;
    }
    for (int i = 0; i < games.size(); i++) {
        cout << i + 1 << ". " << games[i].toString() << endl;
    }
}


void loadGames(const string& filename, vector<Game>& games) {
    ifstream inputFile(filename);

    if (!inputFile) throw runtime_error("Could not open file" + filename);

    string line;
    while(getline(inputFile, line)) {
        stringstream ss(line);
        string title; 
        string genre;
        string hoursText;
        string ratingText;

        getline(ss, title, '|');
        getline(ss, genre, '|');
        getline(ss, hoursText, '|');
        getline(ss, ratingText);

        try {
            int hours = stoi(hoursText);
            int rating = stoi(ratingText);

            Game game(title, genre, hours, rating);

            games.push_back(game);
        } catch (const exception& e) {
            cout << "Stopping invalid: " << line << endl;
            cout << "Reason: " << e.what();
        }

    }
    inputFile.close();
}


void searchGames(const vector<Game>& games, string keyword) {
    for (char& ch : keyword) {  //takes in keyword, goes through every character with a pass
        ch = tolower(ch);         // by ref because we want to change to lowercase
    }
    for (int i = 0; i < games.size(); i++) {    
        string title = games[i].getTitle();
        for (char& ch : title) {        //goes through each char of title and tolowers it to match to keyword
                ch = tolower(ch);
        }
        if (title.find(keyword) != string::npos) {
            cout << games[i].toString() << endl;
            return;
        }
    }
    cout << "No matching game found.";
}


void saveGames(const string& fileName, const vector<Game>& games) {
    ofstream outputFile(fileName);

    if (!outputFile) {
        throw runtime_error("Could not open output file.");
    }

    for (int i = 0; i < games.size(); i++) {
        outputFile << games[i].getTitle() << '|' << games[i].getGenre() 
        << '|' << games[i].getHoursPlayed() << '|' << games[i].getRating() << "\n";
    }
}

void displayStats(const vector<Game>& games) {
    if (games.empty()) {
        cout << "No games to display.";
        return;
    }

    int totalHours = 0;
    int totalRating = 0;
    int highestRating = 0;
    double averageRating;

    for (int i = 0; i < games.size(); i++) {
        totalHours += games[i].getHoursPlayed();
        totalRating += games[i].getRating();
        if (games[i].getRating() > highestRating) {
            highestRating = games[i].getRating();
        }
        averageRating = static_cast<double>(totalRating) / games.size();
    }
    cout << "\n--- GAME STATISTICS ---\n";
    cout << "Total games: " << games.size() << endl;
    cout << "Total hours played: " << totalHours << endl;
    cout << "Average rating: " << averageRating << endl;
    cout << "Highest rated game: "
         << games[highestRating].getTitle()
         << " (" << games[highestRating].getRating()
         << "/10)" << endl;
}

// LAB 10 CREATIVE FEATURE TEST EVIDENCE

// Creative Feature:
// Added a Game Statistics option that summarizes the games currently loaded in the program.

// Test Data:
// Minecraft|Sandbox|250|10
// Hades|Action|45|9
// Portal 2|Puzzle|18|10
// Dark Souls|RPG|80|9

// Expected Results:
// Total games: 4
// Total hours played: 393
// Average rating: 9.5
// Highest rated game: Minecraft (10/10)

// Verification:
// 250 + 45 + 18 + 80 = 393 total hours.

// 10 + 9 + 10 + 9 = 38 total rating points.
// 38 / 4 = 9.5 average rating.

// The highest rating is 10. Minecraft is the first game encountered with that rating.

// The program produced the expected statistics, so the creative feature was verified.

//DOCUMENTATION:
//I added a Game Statistics menu option to Lab 10. 
// It displays the number of games, total hours played, average rating, and the highest-rated game. 
// I chose this feature because the original program could store and display individual games, 
// but it did not summarize the collection as a whole. The statistics feature makes the game backlog 
// more useful by giving the user an overview of their library.