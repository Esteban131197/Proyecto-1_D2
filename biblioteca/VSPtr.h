#include <iostream>

using namespace std;



template <class T>

class VsPtr {

private;
    
    T* data;

public;

    static VsPtr<T> New();

    VsPtr& operator=(VsPtr<T> newData);

    VsPtr& operator=(T newData);

    T& operator*();

    T operator&();

    VsPtr();
    
    ~VsPtr();

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




