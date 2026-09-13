#include <iostream>
#include <iomanip> 
#include <array>

using namespace std;

main() {

}



//===========================================================================================================
//              = prelab = 

// 1. 
// A data member is the variable withing the class that we control and a member function is a function that we use to control or touch 
// those data members. Data members are usually private because we want the entire class throughout the cpp files to use those 
// variables without changing them. Versus the function we keep public usually 
// to be able to access the data members without changing them.

//2.
// When you write those two different objects under the two different constructors what happens is one of them uses 
// predefined arguments and the parameterized takes the arguments given to it. All it does it allow us to create different kinds
// of objects, one that has predefined variables and the other that has variables given to it to describe what's inside our object.
// The compolier knows which one to call based on wether or not you gave it arguments matching the constructer or no arguments.

//3.
// include garud just makes sure the compiler doesn't complain if we define the same class in different cpp files. 
// #ifndef LIBRARY_H
// #define LIBRARY_H
//
// code
//
// #endif

//4.
//  class Patron() {
//  
//  private:
//      string name;
//      double cardNumber;
//      int maxBooks;
//      vector<string> checkedISBN;
//  
//  }

//everything should be written as a private as we don't want any otuside code to affect these yet. The only possibilities
//I can think of as exceptions would be the name.

//5.
// getTitle() should be a const because we don't expect to change anything about the variables, 
//     we're just trying to find what the information is
// setCheckedOut(bool) should not be a const because we are changing the inside members
// containsKeyword(string) is just checking so we can make it a const
// toString() I'm assuming would change something so we wouldn't make it const. The reasong I'm assuming is becasue of the "to".

//6.
//  int Library::getCount() const {
//      return count;
//  }


