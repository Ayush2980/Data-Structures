#ifndef ERROR_H
#define ERROR_H
#include <exception>

class OutOfBounds{
    public :
    const char* what(){
        return "Array Index Out of bounds !!"; 
    }
};



#endif