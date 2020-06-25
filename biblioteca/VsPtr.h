/**
 * @file VsPtr.h
 * @date 03/06/2020
 * @author Brayan Solano
 * @brief Clase que define un nuevo tipo de puntero para almacenar datos mediante sobrecarga de operadores
 * 
 * */

#include <iostream>
#include"GarbageCollector.h"



using namespace std;



template <class T>

class VsPtr {

private:
    
    T* data;

public:
    /**
     * @brief New es un metodo estatico para instanciar nuevos VsPtrs
     * @return VsPtr
     * 
    */

    static VsPtr<T> New();

    /**
     * @brief Sobrecarga de operador "=", copia la direccion de memoria
     * @param newData VsPtr<T> el cual es copiado
     * @return direccion de memoria del VsPtr
     * 
    */

    VsPtr& operator=(VsPtr<T> newData);
    /**
     * @brief  Sobrecarga de operador = para asignar un  nuevo dato
     * @param newData  Dato el cual es asigando
     * @return direccion de memoria del VsPtr
    */

    VsPtr& operator=(T newData);
    /**
     * @brief Sobrecarga del operador * para asignar un nuevo dato
     * @return direccion de memoria de T generico
    */

    T& operator*();
    /**
     * @brief Sobrecarga de operador & para asiganar un nuevo dato
     * @return dato guardado en el VsPtr
    */

    T operator&();
    /**
     * @brief VsPtr Constructor de la clase VsPtr
     * 
    */

    VsPtr();
    /**
     * @brief VsPtr Destructor de la clase VsPtr
     * 
    */
    
    ~VsPtr();
    /**
     * @brief getTdata se utiliza para obtener dato guardado generico guardado en el puntero
     *@return Puntero generico que almacena dato 
    */

    T* getTdata();

};


template <class T>
VsPtr<T> VsPtr<T>::New() {

    return VsPrt(); 

}

template <class T>
VsPtr<T>::VsPtr() {
    this->data = new T;
    GarbageCollector* gbC = GarbageCollector::getInstance();
    gbC->addToList(this->data);

}

template <class T>
T& VsPtr<T>::operator*() {
    return *data;
}

template <typename T>
T VsPtr<T>::operator&() {
    return *data;
}

template <class T>
VsPtr<T>& VsPtr<T>::operator=(VsPtr<T> newData) {
    GarbageCollector* gbC = GarbageCollector::getInstance();
    gbC->copyRef(newData.data, this->data);
    this->data = newData.data;

}

template <class T>
VsPtr<T>& VsPtr<T>::operator=(T newData) {
    *this->data = newData;
}

template <typename T>
VsPtr<T>::~VsPtr() {
    GarbageCollector* gbC = GarbageCollector::getInstance();
    gbC->deleteData(this->data);

}

template <typename T>
T* VsPtr<T>::getTdata() {
    return this->data;
}




