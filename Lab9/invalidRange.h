#ifndef INVALIDRANGE_H
#define INVALIDRANGE_H

#include <string> 
using namespace std;

class invalidRange {
    private: 
        string message;

    public: 
        invalidRange(string msg)        //creates a function with initialized string message msg
            : message(msg)
            {
            }
        string what() {                 //is a function that returns our private message
            return message;
        }
};



#endif