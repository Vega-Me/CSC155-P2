#ifndef CHECKOUTSYSTEM_H
#define CHECKOUTSYSTEM_H

#include "Library.h"
#include "Patron.h"
#include <vector>
#include <string>

using namespace std;

class CheckoutSystem {
private:
    Library &lib;
    vector<Patron> patrons;

public: 
    CheckoutSystem(Library &lib);

    void addPatron(Patron p);
    int findPatron(string cardNum) const;

    bool checkout(string cardNum, string isbn);
    bool returnItem(string cardNum, string isbn);

    void printPatronActivity(string cardNumb) const;
    void printSystemReport() const;
};


#endif