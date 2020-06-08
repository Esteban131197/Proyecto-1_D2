#include <iostream>
#include "Node.h"
using namespace std;

template <class T> class CustomLinkedList
{
    Node<T> *head, *tail;

public:

    CustomLinkedList()
    {
        head = NULL;
        tail = NULL; 
    }

    ~CustomLinkedList()
    {

    }

    //Metodo que agrega informacion al final de la lista 
    void add(T info)
    {
        if(head == NULL) //Si la lista esta actualmente vacia 
        {
            head = new Node<T>; //Crea un nuevo nodo de tipo T
            head->setData(info);
            tail = head;
        }
        else //Si no esta vacia agrega al final y mueve la cola
        {
            Node* temp = new Node<T>;
            temp->setData(info);
            temp->setNextNull();
            tail->setNext(temp);
            tail = tail->getNext();
        }
    }

    
};