#include "invalidRange.h"
#include "invalidType.h"
#include "invalidUnit.h"

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>

using namespace std;


int main() {

}

// =================
//      PRE LAB
//q1 & q2: the function stops during the second try and throws upward until it hits the catch(string e) in this case e can be anything, then it cout's a error, and cout's done.
//q3: c++ needs to know which catch can handle the error. We can have multiple catches for a try so being specific is necessary. The program will just terminate if it's cathc(invalidType e)
//q4: 
// invalidType: X is not a recognized sensor type. Valid types are T, H, and P.
// invalidUnit: KELVIN is not a valid unit for Temperature. Valid units are C, F, and K.
// invalidRange: 999 is outside the valid Temperature range of -50.0 to 150.0.
//q5: it has 5 neighbors
//q6:bool isCorner(int i, int j, int rows, int cols);

// bool isEdge(int i, int j, int rows, int cols);

// bool isPeakMax(int board[][COLS],
//                int i, int j,
//                int rows, int cols);

// bool isPeakMin(int board[][COLS],
//                int i, int j,
//                int rows, int cols);