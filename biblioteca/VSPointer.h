
#include <iostream>

using namespace std;

#ifndef VSPOINTER_VSPOINTER_H

#define VSPOINTER_VSPOINTER_H

template <class T>



class VsPtr {

private:

    T* data;

    VsPtr();

    string type;

public:

   static VsPtr<T> New();

    VsPtr& operator=(VsPtr<T> newData);

    VsPtr& operator=(T newData);

   T& operator*();

   T operator&();

   T getData();

   string getType();

};

//Constructor de la clase 

template <class T>

VsPtr<T> VsPtr<T>::New() {

    return VsPrt();
}

//Mediante new asigna memoria para el dato T* 

template <class T>

VsPtr<T>::VsPtr() {

    this->data = new T;

    if (typeid(T)== typeid(string)){

        this->type = "string";

    }

    else if (typeid(T)== typeid(int)){

        this->type = "int";

    }

    else if (typeid(T)== typeid(bool)){

        this->type = "bool";

    }

    else if (typeid(T)== typeid(char)){

        this->type = "char";

    }

}

//Se realiza la sobrecarga del operador *

template <class T>

T& VsPtr<T>::operator*() {

    return *data;

}

template <class T>

T VsPtr<T>::operator&() {

    return *data;
}

//Se realiza sobrecarga del operador =

template <class T>

VsPtr<T>& VsPtr<T>::operator=(VsPtr<T> newData) {

    this->data = newData.data;

}

template <class T>

VsPtr<T>& VsPtr<T>::operator=(T newData) {

    *this->data = newData;

}

//Da return del dato T*

template <class T>

T VsPtr<T>::getData() {

    return *this->data;

}


template <class T>

string VsPtr<T>::getType() {

    return this->type;
}

#endif 