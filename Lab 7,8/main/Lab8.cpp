#include <iostream>
#include "Book.h"
#include "Library.h"
#include "CheckoutSystem.h"
#include "Patron.h"

using namespace std;

int main() {
Library library;        //create a object called library from the library class

Book b1("Dune", "Frank Herbert", "978-0441013593", 1965);       //create these books from the book class
Book b2("To Kill a Mockingbird", "Harper Lee", "978-0060935467", 1960);
Book b3("The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565", 1925);
Book b4("1984", "George Orwell", "978-0451524935", 1949);
Book b5("The Hobbit", "J.R.R. Tolkien", "978-0547928227", 1937);
Book b6("Fahrenheit 451", "Ray Bradbury", "978-1451673319", 1953);

library.addBook(b1);            //add books to the vector library
library.addBook(b2);
library.addBook(b3);
library.addBook(b4);
library.addBook(b5);
library.addBook(b6);

CheckoutSystem system(library);

Patron p1("Marcos", "100001", 2);
Patron p2("Alice", "100002", 3);
Patron p3("Bob", "100003", 3);

system.addPatron(p1);
system.addPatron(p2);
system.addPatron(p3);

//Step 1
cout << "\n\n\n\n\n=== LAB 8 CHECKOUT SYSTEM ===" << endl;

cout << "\n--- Initial System Report ---" << endl;
system.printSystemReport();

//Step 2
cout << "\n--- Successful Checkout #1 ---" << endl;

if (system.checkout("100001", "978-0441013593")) {
    cout << "Dune checked out successfully." << endl;
}
system.printPatronActivity("100001");

//Step 3
cout << "\n--- Successful Checkout #2 ---" << endl;

if (system.checkout("100001", "978-0743273565")) {
    cout << "The Great Gatsby checked out successfully." << endl;
}

//Step 4 denials
system.printPatronActivity("100001");

cout << "\n--- Checkout Denied: Patron At Limit ---" << endl;

if (!system.checkout("100001", "978-0547928227")) {
    cout << "Checkout denied as expected." << endl;
}
system.printPatronActivity("100001");

cout << "\n--- Checkout Denied: Book Unavailable ---" << endl;

if (!system.checkout("100002", "978-0441013593")) {
    cout << "Checkout denied as expected." << endl;
}

//Step 5 returning book
cout << "\n--- Successful Return ---" << endl;

if (system.returnItem("100001", "978-0743273565")) {
    cout << "The Great Gatsby returned successfully." << endl;
}

system.printPatronActivity("100001");

//Step 6 report for original books and the system change
cout << "\n--- Original Library Status ---" << endl;
library.printAll();
cout << "\n--- Final System Report ---" << endl;
system.printSystemReport();




//CREATIVE FINAL FEATURE
cout << "\n--- Borrow Count Test ---\n";

system.checkout("100001", "978-0451524935");
system.returnItem("100001", "978-0451524935");

system.checkout("100001", "978-0451524935");
system.returnItem("100001", "978-0451524935");

library.printBorrowCount();
}

//                      Post lab excercises
// Exercise 1:
// I created a patron with my own name that had max books of two,
//  then I attempted to checkout more books than the limit and 
//  it successfully didn't work. Printed activity after each step to check.


// Exercise 2:
//CheckoutSystem stores a ref to original library
//we created the object that belongs to system, and then
//pass by referenced it through the constructor. If we didn't
//pass by reference then the library copy in system would change but
//not the actual library object.


// Exercise 3:
// I tested this and the returnBook() worked like normal.


//                                     Creative final feature questions
// What function or extension did you add? Write its complete signature and describe what it does.
//void printBorrowCount(string isbn) const;
//I added print borrow count and I added incremental borrow counts when checking out a book and I added a borrow count
//starting at 0 for each book. The print borrow count does a for loop and prints all the borrow counts for each 
//book by retrieving the titles via the book class with getTitle().

// What design principle from the AI conversation shaped how you decided what belongs in this 
// function versus what already existed in the class?
//I specifically was thinking about bloat and wanted to avoid bloat in code I decided to use a pre-existing
//class instead of creating a new one, I used library to handle the book's private variable of 
//borrowed count and then accessed it via the public functions thanks to the help of ai showing me 
//that bloat usually comes from adding to many new functions without purpose that intertwine with 
//each other too much.
//
// Question 3:
//I added it to both the book and library class, the book class recieved the borrowed count which starts 
//at 0 automatically. 
//
// What would you add next to make this library system more 
// complete — and which class would that addition belong to?
//I would probably add a function that displays only the borrow count for a specific book 
//and then I would also maybe make a menu for inputs via cin.