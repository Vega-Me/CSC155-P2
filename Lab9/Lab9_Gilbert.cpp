#include "invalidRange.h"
#include "invalidType.h"
#include "invalidUnit.h"

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>

using namespace std;






void validateReading(char type, double value, string unit, vector<string>& readings);

int main() {

    vector<string> readings;

    int totalAttempts = 0;
    int temperatureCount = 0;
    int humidityCount = 0;
    int pressureCount = 0;

    while (readings.size() < 10) {

        cout << "Reading " << readings.size() << " of 10.\n";
        cout << "Enter type value unit (e.g. T 23.5 C): ";
        char type; double value; string unit;
        cin >> type >> value >> unit;

        totalAttempts++;

        try {
            validateReading(type, value, unit, readings);   
            cout << "Reading accepted.\n";

            if (type == 'T') {                           //increasing counts only if success, if it fails it'll skip to catch.
                temperatureCount++;
            }
            else if (type == 'H') {
                humidityCount++;
            }
            else if (type == 'P') {
                pressureCount++;
            }

        } catch (invalidType e) { cout << "TYPE ERROR: " << e.what() << "\n"; }
          catch (invalidUnit e) { cout << "TYPE ERROR: " << e.what() << "\n"; }
          catch (invalidRange e){ cout << "RANGE ERROR: " << e.what() << "\n";}
    }

    sort(readings.begin(), readings.end()); //sort the vector in ascending order, A to Z because of string.

    for (int i = 0; i < readings.size(); i++) {
        cout << i + 1 << ". "<< readings[i] << endl;
    }

    int totalValid = static_cast<int>(readings.size());
    int totalRejected = totalAttempts - totalValid;

    cout << "\n--- SESSION STATISTICS ---\n";
    cout << "Total attempted: " << totalAttempts << endl;
    cout << "Total valid: " << totalValid << endl;
    cout << "Total rejected: " << totalRejected << endl;
    cout << "Temperature readings: " << temperatureCount << endl;
    cout << "Humidity readings: " << humidityCount << endl;
    cout << "Pressure readings: " << pressureCount << endl;

    
}











// =================
// Endomorphic

void validateReading(char type, double value, string unit, vector<string>& readings) {  //char type is T H or P, value=value, unit is measurement, pass by reference readings vector declared
    if (type != 'T' && type != 'H' && type != 'P') {                    //tip validator
        throw invalidType("Invalid sensor type: " + string(1, type));
    }
    if (type == 'T') {
        if (unit != "C" && unit != "F" && unit != "K") {
            throw invalidUnit("Invalid unit for temperature, valid units must be \"C\", \"F\", or \"K\".");
        }
    }
    else if (type == 'H') {
        if (unit != "PCT") {
            throw invalidUnit("Invalid unit for humidity, valid unit must be \"PCT\".");
        }
    }
    else if (type == 'P') {
        if (unit != "HPA" && unit != "PSI" && unit != "ATM") {
            throw invalidUnit("Invalid unit for pressure, valid units must be \"HPA\", \"PSI\", or \"ATM\".");
        }
    }
    if (type == 'T') {
        if (value < -50.0 || value > 150.0) {
            throw invalidRange("invalidRange: " + to_string(value) + " is outside the Temperature range of -50.0 to 150.0.");
        }
    }
    if (type == 'H') {
        if (value < 0.0 || value > 100.0) {
            throw invalidRange("invalidRange: " + to_string(value) + " is outside the Humidity range of 0.0 to 100.0.");
        }
    }
    if (type == 'P') {
        if (value < 800.0 || value > 1100.0) {
            "invalidRange: " + to_string(value) + " is outside the Pressure range of 800.0 to 1100.0.";
        }
    }

    double rounded_value = round((value * 10) / 10);                //was bothering me that value was large
    readings.push_back(string(1, type) + " " + to_string(rounded_value) + unit);
}




// T	Temperature	−50.0 to 150.0	C, F, K
// H	Humidity	0.0 to 100.0	PCT
// P	Pressure	800.0 to 1100.0	HPA, PSI, ATM

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



// ========
// POST LAB

//Excercise 1
// Reading 0 of 10.
// Enter type value unit (e.g. T 23.5 C): X 25.0 C
// TYPE ERROR: Invalid sensor type: X
// Reading 0 of 10.
// Enter type value unit (e.g. T 23.5 C): T 25.0 KELVIN
// TYPE ERROR: Invalid unit for temperature, valid units must be "C", "F", or "K".
// Reading 0 of 10.
// Enter type value unit (e.g. T 23.5 C): T 999.0 C
// RANGE ERROR: invalidRange: 999.000000 is outside the Temperature range of -50.0 to 150.0.
// Reading 0 of 10.
// Enter type value unit (e.g. T 23.5 C): P 950 HPA
// Reading accepted.
// Reading 1 of 10.
// Enter type value unit (e.g. T 23.5 C): T 30 C
// Reading accepted.
// Reading 2 of 10.
// Enter type value unit (e.g. T 23.5 C): H 60 PCT
// Reading accepted.
// Reading 3 of 10.

//Excercise 2
//TYPE ERROR: Invalid sensor type: X
// Moving my range validation before type validation did not change the result 
// because each range rule depends on the sensor type. 
// Since X is not T, H, or P, none of the range checks execute. 
// The program eventually reaches the type validation and throws invalidType.

//Exc 3
//removing it causes the program to terminate 
//
// I temporarily removed the catch block for invalidUnit.
// Test input:
// T 25.0 KELVIN
//
// Stack unwinding is when C++ exits the active function calls
// while searching for a matching catch block. When the exception
// was thrown, validateReading() stopped immediately. If no
// matching catch is found, the program terminates.