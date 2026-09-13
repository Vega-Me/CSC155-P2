#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

class Book {

    private:
        string title;
        string author;
        string isbn;
        int    year;
        bool   checkedOut;
    
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

};

#endif