#include"vsPointer.h"
#include<iostream>
#include"garbage.cpp"



using namespace std;

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
    return *this;
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

template<class T>
Pointer<T>::Pointer(){
    this->content = new T;

    if (typeid(T)== typeid(string)){
        this->type = "string";

    }
    else if(typeid(T)== typeid(int)){
        this->type = "int";

    }
    else if(typeid(T)== typeid(double)){
        this->type = "double";

    }
    else if(typeid(T)== typeid(char)){
        this->type = "char";

    }
    else if(typeid(T)== typeid(bool)){
        this->type = "bool";

    }
    else if(typeid(T)== typeid(float)){
        this->type = "float";

    }
    else if(typeid(T)== typeid(short)){
        this->type = "short";

    }
    else if(typeid(T)== typeid(unsigned)){
        this->type = "unsigned";

    }
}

  template <class T>
Pointer<T>::~Pointer<T>(){

    garbage::clear(this,content);

}

template <class T>
void Pointer<T>::operator = (Pointer<T>* firstPointer){

    content = firstPointer->content;
    garbage::newPointer((Pointer<void*>*)this,content,nativeTypes);
    id = firstPointer->id;

}

