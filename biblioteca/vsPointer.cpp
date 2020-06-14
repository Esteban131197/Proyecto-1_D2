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

template <class T>
void Pointer<T>::init(){

    id = garbage::generateid();
    garbage::newPointer((Pointer<void*>*)this,content,nativeTypes);
}

/*
Sobrecarga de operador *
*/

template<class T>
Pointer<T> Pointer<T>::operator*()
{
    return*this
}

template<class T>
int Pointer<T>::getid()
{
    return id;
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

template <class T>
Pointer<T>::~Pointer<T>(){

    garbage::clear(this,content);

}

template <class T>
void Pointer<T>::operator = (Pointer<T>* firstPointer){

    content = firstPointer->content;
    garbage::newPointer((Pointer<void*>*)this,content,nativeTypes);


}