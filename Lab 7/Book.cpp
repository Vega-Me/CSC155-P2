#include "Book.h"
#include <algorithm> 
#include <iomanip>

bool Book::containsKeyword(string kw) const {
    string lTitle   = title;
    string lAuthor  = author;
    string lKw      = kw;

    transform(lTitle.begin(), lTitle.end(), lTitle.begin(), ::tolower);
    transform(lAuthor.begin(), lAuthor.end(), lAuthor.begin(), ::tolower);
    transform(lKw.begin(), lKw.end(), lKw.begin(), ::tolower);
    return (lTitle.find(lKw) != string::npos || lAuthor.find(lKw) != string::npos);

}