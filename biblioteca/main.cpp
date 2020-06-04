#include<iostream>
#include "VSPointer.h"
#include "GarbageCollector.h"

using namespace std;


int main(){

    puntero *VSptr= new puntero();
    *VSptr=5;
    cout << VSptr->data;
    return 0;
}






