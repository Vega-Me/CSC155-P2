#ifndef INVALIDTYPE_H
#define INVALIDTYPE_H

using namespace std;
#include <string>

class invalidType {
    private: 
        string message;
    public: 
        invalidType(string msg) 
        : message(msg)
        {
        }

        string what() {
            return message;
        }

};


#endif