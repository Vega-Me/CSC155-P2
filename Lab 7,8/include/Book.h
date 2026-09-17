#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <ostream>
using namespace std;

class Book {

    private:
        string title;
        string author;
        string isbn;
        int    year;
        bool   checkedOut;
        
        int borrowedCount; //creative final feature
    
    public:
        Book();
        Book(string t, string a, string id, int y);
        
        string getTitle() const;
        string getAuthor() const;
        string getIsbn() const;
        int getYear() const;
        bool isCheckedOut() const;
        void setCheckedOut(bool status);
        bool containsKeyword(string kw) const;          
        string toString() const;

        int getBorrowedCount() const;
        void incrementBorrowedCount();

};

#endif