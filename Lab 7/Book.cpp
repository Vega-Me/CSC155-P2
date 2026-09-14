#include "Book.h"
#include <algorithm> 
#include <iomanip>
#include <cctype>


Book::Book()
    : title("na"),
    author("na"),
    isbn("na"),
    year(0)
{
}


Book::Book(string t, string a, string id, int y)
    : title(t),
    author(a),
    isbn(id),
    year(y)
{
    if (year < 0) {
        year = 0;
    }
}


string Book::getTitle() const {
    return title;
}


string Book::getAuthor() const {
    return author;
}


string Book::getIsbn() const {
    return isbn;
}


int Book::getYear() const {
    return year;
}


bool Book::isCheckedOut() const {
    return checkedOut;
}


bool Book::containsKeyword(string kw) const {
    string lTitle   = title;
    string lAuthor  = author;
    string lKw      = kw;

    transform(lTitle.begin(), lTitle.end(), lTitle.begin(), ::tolower);
    transform(lAuthor.begin(), lAuthor.end(), lAuthor.begin(), ::tolower);
    transform(lKw.begin(), lKw.end(), lKw.begin(), ::tolower);
    return (lTitle.find(lKw) != string::npos || lAuthor.find(lKw) != string::npos);

}


void Book::setCheckedOut(bool status) {
    checkedOut = status;
}


string Book::toString() const {
    string status;

    if (checkedOut) {
        status = "CHECKED OUT";
    }   
    else status = "AVAILABLE";

    return {"[" + isbn + "] " +
        title + " - " +
        author + " (" +
        to_string(year) + ") [" +
        status + "]"};
}