#include "Patron.h"

Patron::Patron()
      : name("Unknown"),
      cardNumber("000000"),
      maxBooks(3),
      checkedOutCount(0)
      {
      }


Patron::Patron(string name, string cardNum, int maxBooks) 
      : name(name),
      cardNumber(cardNum),
      maxBooks(maxBooks),
      checkedOutCount(0)
      {
      }


string Patron::getName() const {
    return name;
}


string Patron::getCardNumber() const {
    return cardNumber;
}


int Patron::getCheckedOutCount() const {
    return checkedOutCount;
}


bool Patron::canCheckOut() const {
    return checkedOutCount < maxBooks;
}


void Patron::incrementCount() {
    checkedOutCount++;
}


void Patron::decrementCount() {
    if (checkedOutCount > 0) {
        checkedOutCount--;
    }
}


string Patron::toString() const {
    return name + " [" + cardNumber + "] - " + to_string(checkedOutCount) + " / " + to_string(maxBooks) + " books checked out.";
}
