#ifndef INVALIDUNIT_H
#define INVALIDUNIT_H

using namespace std;
#include <string>

class invalidUnit {
    private:
        string message;

    public:
        invalidUnit(string msg) 
            : message(msg)
            {
            }
        string what() {
            return message;
        }
};


#endif