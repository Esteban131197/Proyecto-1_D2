#include <iostream>
#include <thread> 
#include <unistd.h>
#include "GarbageCollector.h"


using namespace std;

void run();
GarbageCollector* GarbageCollector::instance = 0;

GarbageCollector::GarbageCollector(){
    //inicia las variables
    this->flag = true;
    this->thrd = thread(run);
}
/**
 * @brief getInstance Funcion para retornar la instancia del singleton
 * 
*/
GarbageCollector* GarbageCollector::getInstance(){
    //singleton
    if (instance == 0)
    {
        instance = new GarbageCollector();

    }
    return instance;
}


void GarbageCollector::addToList(int* data) {
    //agrega un dato a la lista de ints
    this->intList.addNode(data);
}

void GarbageCollector::addToList(string* data) {
    //agrega un dato a la lista de strings
    this->stringList.addNode(data);
}

void GarbageCollector::addToList(bool* data) {
    //agrega un dato a la lista de booleanos
    this->boolList.addNode(data);
}

void GarbageCollector::copyRef(int* newData, int* oldData) {
    this->intList.copyData(newData,oldData);
}
void GarbageCollector::copyRef(string* newData, string* oldData) {
    this->stringList.copyData(newData,oldData);
}
void GarbageCollector::copyRef(bool* newData, bool* oldData) {
    this->boolList.copyData(newData,oldData);
}

void GarbageCollector::deleteData(int* removeData) {
    this->intList.deleteRef(removeData);
}

void GarbageCollector::deleteData(string* removeData) {
    this->stringList.deleteRef(removeData);
}

void GarbageCollector::deleteData(bool* removeData) {
    this->boolList.deleteRef(removeData);
}


void run() {
    GarbageCollector *gbc = GarbageCollector::getInstance();
    //elimina de la lista segun el flag
    while (gbc->flag) {
        if (gbc->stringList.getSize()!= 0) {
            gbc->stringList.freeMemory();
        }
        if(gbc->intList.getSize()!=0){
            gbc->intList.freeMemory();
        }
        if(gbc->boolList.getSize()!=0){
            gbc->boolList.freeMemory();
        }
        //cout<<"liberando memoria"<<endl;
        //un sleep(0)
        sleep(static_cast<unsigned int>(0.3));
    }
}


int GarbageCollector::getDataID(bool* data) {
    return this->boolList.getDataID(data);
}

int GarbageCollector::getDataID(string* data) {
    return this->stringList.getDataID(data);
}

int GarbageCollector::getDataID(int* data) {
    return this->intList.getDataID(data);
}