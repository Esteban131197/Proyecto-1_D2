
#include <iostream>

using namespace std;

//#ifndef VSPOINTER_VSPOINTER_H

#define VSPOINTER_VSPOINTER_H

template <class T> 
class Pointer {



public:

    

    void operator=(T content);

    T& operator*();

    T operator&(); 

    T getData();

    void init():

    string getType();

    Pointer<T> operator*()

    static Pointer<T> New();

    Pointer();

    ~Pointer<T>();

    void operator= (Pointer<T> *firstPointer);

private:

T *content;


};
