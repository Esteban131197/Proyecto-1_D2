#include<iostream>
#include "GarbageCollector.h"
#include "VsPtr.h"
#include "Node.h"
using namespace std;

//funcion para probar que se borran los punteros y datos guradados en este
int aux() {
    VsPtr<int> ptr7 = VsPtr<int>::New();
    ptr7 = 9;
    cout << "cantidad de datos en intList dentro de aux: " << gc->intList.getSize() << endl;

}
int main(){
    
    //se inicia el Garbage Collector
    GarbageCollector* gc = GarbageCollector::getInstance();
    cout << "cantidad de datos en stringList al inicio: " << gc->stringList.getSize()<<endl;
    cout << "cantidad de datos en intList al inicio: " << gc->intList.getSize()<<endl;
    cout << "cantidad de datos en boolList al inicio: " << gc->boolList.getSize()<<endl;
    
    //se crean los ptrs con los tipos soportados por el GC, bool, int, string
    VsPtr<int> ptr = VsPtr<int>::New(); //se crea un puntero con tipo int 
    VsPtr<string> ptr2 = VsPtr<string>::New(); //se crea un puntero con tipo string
    VsPtr<bool> ptr3 = VsPtr<bool>::New();// se crea un puntero con tipo bool
    VsPtr<int> ptr4 = VsPtr<int>::New();//se crea un segundo puntero con tipo int 
    cout << "ahora la cantidad de datos en stringList: " << gc->stringList.getSize()<<endl;
    cout << "ahora la cantidad de datos en intList: " << gc->intList.getSize()<<endl;
    cout << "ahora la cantidad de datos en boolList: " << gc->boolList.getSize()<<endl;

    //asignacion de valores
    ptr = 1;
    ptr2 = "hola mundo";
    ptr3 = true;
    ptr4 = 3;

    cout << "dato en ptr: " << &ptr << endl;
    cout << "dato en ptr2: " << &ptr2 << endl;
    cout << "dato en ptr3: "  << &ptr3 << endl;
    cout << "dato en ptr4: " << &ptr4 << endl;
    
    //se crea una funcion auxiliar para que el stack sea el que crea y elimina el puntero dentro de la funcion
    cout << "cantidad de datos en intList antes de aux: " << gc->intList.getSize() << endl;
    aux();
    sleep(static_cast<unsigned int>(0.4));
    cout << "cantidad de datos en intList despues de aux: " << gc->intList.getSize() << endl;
    
    //valor asignado de un VsPtr a otro VsPtr
    cout << "dato en ptr antes de asignar ptr4: " << &ptr << endl;
    ptr = ptr4;
    cout << "dato en ptr despues de asignar ptr4: " << &ptr << endl;
    return 0;
}

