#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>   
#include <string>
#include <iostream>


class Library{

    private:
        vector<Book> catalog;

    public:
        Library();

        void addBook(Book b);
        bool removeBook(string isbn);               //gives true or false and removes?
        int findByIsbn(string isbn) const;          //checking therefore const | int to return index?
        void searchByKeyword(string kw) const;      //return nothing, change nothing therefore const, and input keyword
        bool checkoutBook(string isbn);             //changing book status, and giving bool to let us know it worked? input isbn string
        bool returnBook(string isbn);               //similar to checkout
        void sortByTitle();                         //all I know is void return nothing but we're changing a vector by .sort?
        int getCount() const;                       //get the count so don't change, possibly .size | const cuz no change
        void printAll() const;                      //void cuz no return just print, const cuz no change
        void printBorrowCount() const;  //creative final feature
};

#endif