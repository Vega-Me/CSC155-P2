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



int main() {
    vector<Game> games;

    try {
        loadGames("games.txt", games);
    } catch (const exception& e) {
        cout << "Error" << e.what() << endl;
    }

    int choice;
    string keyword;
    do {
        void displayMenu();
        cin >> choice;
        if (cin.fail()) {cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid input.";}
        if (choice == 1) displayGames(games);
        if (choice == 2) searchGames(games, keyword);
    } while (choice != 0);

    return 0;
}



void displayMenu() {
    cout << "\nGAME BACKLOG TRACKER\n";
    cout << "1. Display all games\n";
    cout << "2. Search games\n";
    cout << "3. Add a game\n";
    cout << "4. Save games\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}


void displayGames(const vector<Game>& games) {
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