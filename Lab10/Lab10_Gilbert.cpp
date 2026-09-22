#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

const int ROWS = 20;
const int COLS = 20;



void cpGrid(int (&board)[ROWS][COLS]);
bool isCorner(int i, int j, int rows, int cols);
bool isEdge(int i, int j, int rows, int cols);
bool isPeakMax(int board[][COLS], int i, int j, int rows, int cols);
bool isPeakMin(int board[][COLS], int i, int j, int rows, int cols);






int main() {
    int board[ROWS][COLS];          //our 20 x 20 array, learned can add more dimensions but 4th is usually where people stop

    int maxTotal = 0; int minTotal = 0;
    int maxCorner = 0; int maxEdge = 0; int maxInterior = 0;
    int minCorner = 0; int minEdge = 0; int minInterior = 0;

    srand(time(0));         //part of ctime, time() takes current calender time, srand() turns that into a specific seed, later rand() will take that 

    cout << "\n" << right << setw(48) << "TERRAIN GRID\n\n";       
    cpGrid(board);
    cout << "\n" << right << setw(60) << "--- TERRAIN PEAK ANALYSIS REPORT ---\n";
    cout << "\n" << right << setw(48) << "LOCAL MAXIMA:\n";


    for (int i = 0; i < ROWS; i++) {                        //category filter
        for (int j = 0; j < COLS; j++) {

            if (isPeakMax(board, i, j, ROWS, COLS)) {
                string category;

                if (isCorner(i, j, ROWS, COLS)) {           
                    category = "CORNER";
                    maxCorner++;
                }
                else if (isEdge(i, j, ROWS, COLS)) {
                    category = "EDGE";
                    maxEdge++;
                }
                else {
                    category = "INTERIOR";
                    maxInterior++;
                }

                maxTotal++;

                cout << " [" << i << "][" << j << "]" << " value=" << board[i][j] << " " << category << endl;
            }
        }
    }
        cout << "\nLOCAL MINIMA:\n";

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (isPeakMin(board, i, j, ROWS, COLS))
            {
                string category;

                if (isCorner(i, j, ROWS, COLS))
                {
                    category = "CORNER";
                    minCorner++;
                }
                else if (isEdge(i, j, ROWS, COLS))
                {
                    category = "EDGE";
                    minEdge++;
                }
                else
                {
                    category = "INTERIOR";
                    minInterior++;
                }

                minTotal++;

                cout << " [" << i << "][" << j << "]"
                     << " value=" << board[i][j]
                     << " " << category << endl;
            }
        }
    }

    cout << "\nSUMMARY:\n";
    cout << " Total local maxima: " << maxTotal << " (corner: " << maxCorner << ", edge: " << maxEdge << ", interior: " << maxInterior << ")" << endl;
    cout << " Total local minima: " << minTotal << " (corner: " << minCorner << ", edge: " << minEdge << ", interior: " << minInterior << ")" << endl;
    cout << " Total peaks found: " << maxTotal + minTotal << endl;

}







void cpGrid(int (&board)[ROWS][COLS]) {     //create / print grid                       pass by reference is different for array, we want the & to be on the array not the []
    for (int i = 0; i < COLS; i++) {
        cout << setw(4) << i + 1;
    }
    cout << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = (rand() % 100) +1;        //equate the current column and row to, rand() which gives a 'random' seed, divide by 100 and use the remainder, then add 1 to exclude 0 and to include 100
            cout << setw(4) << board[i][j];
        }
        cout << endl;
    }
}

bool isCorner(int i, int j, int rows, int cols) {
    if ((i == 0 || i == rows - 1) && (j == 0 || j == cols - 1)) {
        
    }
}

bool isEdge(int i, int j, int rows, int cols) {

}

bool isPeakMax(int board[][COLS], int i, int j, int rows, int cols) {

}

bool isPeakMin(int board[][COLS], int i, int j, int rows, int cols) {

}