#include "Library.h"
#include <vector> 
#include <iostream>
#include <string> 


    Library::Library() {
    }


    void Library::addBook(Book b){
        catalog.push_back(b);
    }


    bool Library::removeBook(string isbn) {


        int index = findByIsbn(isbn);

        if (index == -1) {
        return false;
        }

        catalog.erase(catalog.begin() + 2 );
        return true;

    }


    int Library::findByIsbn(string isbn) const {

        for (int i = 0; i < catalog.size(); i++ ) {

            if (catalog[i].getIsbn() == isbn) {
                return i;
            }
        }

        return -1;

    }

    void Library::searchByKeyword(string kw) const {
        bool found = false;

        for (int i = 0; i < catalog.size(); i++)

            if (catalog[i].containsKeyword(kw)) {
                cout << catalog[i].toString() << endl;
                found = true;
            }   
        
        if (!found) {
            cout << "No book found." << endl;
        }

    }

    bool Library::checkoutBook(string isbn) {
        int index = findByIsbn(isbn);           //gives index of vector catalog

        if (index == -1) {                      //error value due to wrong isbn
            cout << "Could not checkout book because wrong isbn.";
            return false;
        }

        if (catalog[index].isCheckedOut()) {
            return false;
        }

        catalog[index].setCheckedOut(true);
        return true;
    }


    bool Library::returnBook(string isbn) {
        int index = findByIsbn(isbn);

        if (index == -1) {
            cout << "Couldn't find book name.";
            return false;
        }

        if (!catalog[index].isCheckedOut()) {
            return false;
        }

        catalog[index].setCheckedOut(false);
        return true;
    }

    
    void Library::sortByTitle() {

        for (int i = 0; i < catalog.size() - 1; i++) {

            int mindex = i;

            for (int j = i + 1; j < catalog.size(); j++) {

                if (catalog[j].getTitle() < catalog[mindex].getTitle()) {
                    mindex = j;
                }
            }

            Book temp = catalog[i];
            catalog[i] = catalog[mindex];
            catalog[mindex] = temp;
            // swap(catalog[mindex], catalog[i]); new way

        }
    }


    int Library::getCount() const {

        return static_cast<int>(catalog.size());

    }


    void Library::printAll() const {
        for (int i = 0; i < catalog.size(); i++) {
            cout << i + 1 << ". " << catalog[i].toString() << endl;
        }
    }










    // void sortByTitle();                         //all I know is void return nothing but we're changing a vector by .sort?
                    
    // void printAll() const;