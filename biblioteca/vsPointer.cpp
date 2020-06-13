#include"vsPointer.h"
#include<iostream>
#include"garbage.cpp"



using namespace std;

template<class T>
Pointer<T>::Pointer(){

}

/*
Se crea un nuevo puntero
*/


template<class T>
Pointer<T> Pointer<T>::New(){
    Pointer<T> NewPointer;
    return NewPointer;

}

/*
Sobrecarga de operador *
*/

template<class T>
Pointer<T> Pointer<T>::operator*()
{
    return*this
}


 
/*
Sobrecarga de operador =
*/

template<class T>
void Pointer<T>::operator=(T conteiner)
{
    *content = conteiner;
}


/*
Sobrecarga de operador &
*/

template <class T>
T Pointer<T>::operator &()
{
    return *content
}