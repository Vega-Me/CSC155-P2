
#include <iostream>
#include <iomanip> 
#include <array>
#include "Library.h"

using namespace std;

int main() {

Library library;
    Book b1("Dune", "Frank Herbert", "978-0441013593", 1965);
    Book b2("To Kill a Mockingbird", "Harper Lee", "978-0060935467", 1960);
    Book b3("The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565", 1925);
    Book b4("1984", "George Orwell", "978-0451524935", 1949);
    Book b5("The Hobbit", "J.R.R. Tolkien", "978-0547928227", 1937);
    Book b6("Fahrenheit 451", "Ray Bradbury", "978-1451673319", 1953);

    library.addBook(b1);
    library.addBook(b2);
    library.addBook(b3);
    library.addBook(b4);
    library.addBook(b5);
    library.addBook(b6);


cout << "\n\n\n\n\n=== LIBRARY CATALOG SYSTEM ===" << endl;
cout << "Books added: " << library.getCount() << endl;


cout << "\n--- All Books (unsorted) ---\n";
library.printAll();


cout << "\n--- Find Book by ISBN ---\n";
int index = library.findByIsbn("978-0441013593");
cout << "Isbn test if successful was found at: " << index;
//failure test
cout << "\nIsbn index of unsuccesful test should be -1: " << library.findByIsbn("Not real isbn") << endl;


cout << "\n--- Keyword Search: \"herbert\" ---\n";  //learned how to escape""
library.searchByKeyword("herbert");
cout << "\n--- Mixed Keyword Test: \"HeRbErT\" ---\n";
library.searchByKeyword("HeRbErT");
cout << "\n--- No Result Search: \"xyzxyz\" ---\n";
library.searchByKeyword("xyzxyz");


cout << "\n--- Sorting test ---\n";
library.sortByTitle();
library.printAll();


cout << "\n--- Checkout Test: Dune ---\n";
if (library.checkoutBook("978-0441013593")) {
    cout << "Checked out successfully." << endl;
}
else {
    cout << "Checkout failed." << endl;
}
library.printAll();

cout << "\n--- Checkout Test: 1984 ---\n";
if (library.checkoutBook("978-0451524935")) {
    cout << "Checked out successfully." << endl;
}
else {
    cout << "Checkout failed." << endl;
}
library.printAll();


cout << "\n--- Remove test ---\n";
if (library.removeBook("978-1451673319")) {
    cout << "Removed book successfully.";
}
else {
    cout << "Book not found." << endl;
}
cout << "\nBooks Remaining: " << library.getCount() << endl;
if (!library.removeBook("978-1451673319")) {
    cout << "\nSecond removal correctly failed because book is already checked out." << endl;
}


Book defaultBook;
cout << "\n-- Default Constructor Test ---\n";
cout << defaultBook.toString() << endl;


cout << "\n--- Return Test ---\n";
if (library.returnBook("978-0451524935"))
    cout << "Returned 1984 successfully.\n";
else
    cout << "Return failed.\n";


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


//===========================================================================================================
//              = postlab = 
//excercise 1
//did all the checks, remove book, checkout book, and 2nd attempt for checking out a book. They are at the bottom of the functions list.

//excercise 2
// I sorted and it came out in alphabetical order, I added another book and it moved ahead of the other titles.
// Books with identical titles are sorted because of the less than sign in the for loop.
// I don't have a secondary way of sorting in these loops.

// excercise 3
//containsKeyword() is case insensitive, it searches both the author and title field because of the transform tolower begin -> end
//and because of the string::npos checks in the if statement.
