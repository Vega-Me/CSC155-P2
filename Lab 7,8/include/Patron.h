#ifndef PATRON_H
#define PATRON_H

#include <string>
#include <iostream>     //includes cin and cout 
#include <iomanip>      //includes things that manipulate like setw or fixed or precision
#include <vector>       

using namespace std;

class Patron {
private:
    string name;
    string cardNumber;
    int maxBooks;
    int checkedOutCount;

public: 
    Patron();
    Patron(string name, string cardNumber, int maxBooks);    
    
    string getName() const;
    string getCardNumber() const;
    int getCheckedOutCount() const;

    bool canCheckOut() const;

    void incrementCount();
    void decrementCount();

    string toString() const;
};






#endif
