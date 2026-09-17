#include "CheckoutSystem.h"
#include <iostream> 

using namespace std;

CheckoutSystem::CheckoutSystem(Library &lib)
    : lib(lib)          //basically calling checkoutsystem class to make the constructor checkoutsystem
    {                   //then passing reference lib instead of creating a new one
    }                   //then saying that the variable inside the constructor called lib is going to use the ref

void CheckoutSystem::addPatron(Patron p) {
    patrons.push_back(p);
}

int CheckoutSystem::findPatron(string cardNum) const {
    for (int i = 0; i < patrons.size(); i++ ) {
       if (patrons[i].getCardNumber() == cardNum) {
        return i;
       }
    }
    return -1;
}

bool CheckoutSystem::checkout(string cardNum, string isbn) {
    int patronIndex = findPatron(cardNum);

    if (patronIndex == -1) {
    cout << "Patron not found." << endl;
    return false;
    }
    if (!patrons[patronIndex].canCheckOut()) {
        cout << "Patron at limit." << endl;
        return false;
    }
    int bookIndex = lib.findByIsbn(isbn);
    if (bookIndex == -1) {
        cout << "Book not found" << endl;
        return false;
    }
    if (!lib.checkoutBook(isbn)) {
        cout << "Book already checked out." << endl;
        return false;
    }

    patrons[patronIndex].incrementCount();
    return true;
}

bool CheckoutSystem::returnItem(string cardNumb, string isbn) {
    int patronIndex = findPatron(cardNumb);
    if (patronIndex == -1) {
        cout << "Patron not found." << endl;
        return false;
    }
    int bookIndex = lib.findByIsbn(isbn);
    if (bookIndex == -1) {
        cout << "Could not find book." << endl;
        return false;
    }
    if (!lib.returnBook(isbn)) {
        cout << "Book is not checked out." << endl;
        return false;
    }
    patrons[patronIndex].decrementCount();
    return true;
}

void CheckoutSystem::printPatronActivity(string cardNumb) const {
    int patronIndex = findPatron(cardNumb);
    if (patronIndex == -1) {
        cout << "Patron not found.";
        return;
    }
    cout << patrons[patronIndex].toString() << endl;
}

void CheckoutSystem::printSystemReport() const {
    int patronBooksCheckedOut = 0;
    for (int i = 0; i < patrons.size(); i++) {
        patronBooksCheckedOut += patrons[i].getCheckedOutCount();
    }
    cout << "Total library books : " << lib.getCount() << endl;
    cout << "Total patrons: " << patrons.size() << endl;
    cout << "Total books checked out: " << patronBooksCheckedOut << endl;
}