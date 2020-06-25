

/**
 * 
 * @file LinkedList.h
 * @date 02/06/20
 * @author Brayan Solano
 * @brief Estructura dinamica que utiliza nodo para almacenar datos
 * 
*/


#include "Node.h"

#include<string>

using namespace std;

template <typename T>
/**
 * @brief clase que identifica la lista enlazada
 * 
 */
class LinkedList {


private:
    Node<T> *head,*tail;
    int size;
    int ids[1000];
public:
    /**
     * @brief constructor de la clase LinkedList
     * 
    */
    LinkedList();
    /**
     * @brief addNode agrega un nuevo nodo a la lista
     * @param n  Puntero con  dato  generico
    */
    void addNode(T* n);
    /**
     * @brief display imprime los datos de la lista
     * 
    */
    void display();
    /**
     * Getter
     * @brief getSize Muestra el tamano de la lista
     * @return int tamano de la lista
    */
    int getSize();
    /**
     * @brief generateID Genera un int aleatorio que no se repite  
     * @return int aleatorio 
    */
    int generateID();
    /**
     * @brief copyData Cambia los datos de un nodo especifico, el nodo que tenga guardado en puntero *oldData es sustituido por *newData
     * @param newData Nuevo puntero que se asigna
     * @param oldData Viejo puntero el cual es remplazado
     * 
    */
    void copyData(T* newData, T* oldData);
    /**
     * @brief deleteRef elimina el nodo que tenga el puntero T*
     * @param removeData Puntero para identificar el nodo a eliminar
    */
    void deleteRef(T* removeData);
    /**
     * @brief freeMemory libera todos los espacios de memoria que no se estan utilizando
     * 
    */
    void freeMemory();
    /**
     * @brief getDataID retorna id del nodo que posea en puntero T*
     * @param data puntero para encontrar el nodo deseado
     * @return int que indica el id
    */
    int getDataID(T* data);
    /**
     * @brief getNodeID Obtiene un nodo mediante un int que es un identificador de dicho nodo
     * @param id int que indica el identificador
     * @return Node que posea el int id ingresado  
    */
    Node<T> getNodeID(int id);
    /**
     * @brief searchID Regresa un bool que indica si alguno de los nodos posee el id ingresado
     * @param id int que indica el identificador del nodo a buscar
     * @return bool que indica si se encuentra el nodo
    */
    bool searchID(int id);

};

/**
 * Constructor de la lista
 * 
*/
template <typename T>
LinkedList<T>::LinkedList() {
    //inicializa los datos de la lista
    head = nullptr;
    tail = nullptr;
    size = 0;
}
/**
 * Agrega un nodo a la lista
 * 
*/
template <typename T>
void LinkedList<T>::addNode(T* n) {
    //crea un nodo temporal
    auto *temp = new Node<T>;
    //asigna el tipo del nodo
    if (typeid(T)== typeid(string)){
        temp->setDataType("string");
    }
    else if (typeid(T)== typeid(int)){
        temp->setDataType("int");
    }
    else if (typeid(T)== typeid(bool)){
        temp->setDataType("boolean");
    }
    //asigna el id, dato y siguiente del nodo
    temp->setID(this->generateID());
    temp->setData(n);
    temp->setNext(nullptr);
    //si la lista esta vacia lo usa como padre
    if (head == nullptr){
        head = temp;
        tail = temp;
    }
    //caso contrario lo agrega al final
    else{
        tail->setNext(temp);
        tail = tail->getNext();
    }
    //le aumenta 1 al tamaño
    size++;
}


template <typename T>
void LinkedList<T>::display(){
    //crea un nodo para recorrer la lista
    Node<T>* temp = head;
    //recorre e imprime la lista
    while(temp != nullptr){
        temp = temp->getNext();
    }
}
/**
 * Obtiene el largo de la lista
 * @return int
*/

template <typename T>
int LinkedList<T>::getSize(){
    //devuelve el tamaño
    return this->size;
}


template <typename T>
int LinkedList<T>::generateID(){
    int i = 0;
    int num = rand()%100;
    while(ids[i]!=0){
        if(ids[i]==num) {
            num = rand() % 1000;
        }
        else{
            i++;
        }
    }
    ids[i]=num;
    return num;
}
/**
 * 
 * 
 * 
*/
template <typename T>
void LinkedList<T>::copyData(T* newData, T* oldData){
    Node<T>* temp = head;
    //crea 2 nodos temporales
    Node<T>* temp2 = head;
    while(temp != nullptr){
        // si el nodo temporal 1 es el nuevo dato
        if(temp->getMemDir() == newData){
            // recorre la lsita con el nodo temporal 2 hasta llegar al dato viejo
            while(temp2->getMemDir()!=oldData){
                temp2 = temp2->getNext();
            }
            //aumenta las referencias
            temp->setReferences(temp->getReferences()+1);
            //si la referencia es mayor a 1, le resta la referencia
            if(temp2->getReferences()>1){
                temp->setReferences(temp->getReferences()-1);
            }
            else{
                temp2->setReferences(-1);
            }
            // borra la referencia del dato viejo
            deleteRef(oldData);
            return;
        }
        temp = temp->getNext();
    }
}


template <typename T>
void LinkedList<T>::deleteRef(T* removeData){
    //crea un puntero a un nodo temporal
    auto* temp = new Node<T>;
    temp = this->head;
    //recorre la list
    while(temp!=nullptr){
        //si es lo que se buscaba borramos el dato
        if(temp->getMemDir() == removeData && temp->getReferences()>=1){
            temp->setReferences(temp->getReferences()-1);
            return;
        }
        temp = temp->getNext();
    }
    temp = this->head;
    //si el dato es la cabez, elimina por medio de la cabeza
    if(temp->getMemDir()==removeData){
        temp = temp->getNext();
        head = temp;
    }
    else {
        //recorre la lista
        while (temp != nullptr) {
            //si es la cola elimina la cola
            if (temp->getNext() == this->tail && temp->getNext()->getMemDir() == removeData) {
                this->tail = temp;
                tail->setNext(temp->getNext()->getNext());
                break;
            }
            //si es el dato a borrar lo borra
            if (temp->getNext()->getMemDir() == removeData) {
                temp->setNext(temp->getNext()->getNext());
                break;
            }
            temp = temp->getNext();
        }
    }
    size--;
}

template <typename T>
void LinkedList<T>::freeMemory(){
    //crea un nodo temporal
    Node<T>* temp = head;
    if(temp->getReferences()==0){
        delete (temp->getMemDir());
        head = temp->getNext();
        size--;
    }
    else {
        while (temp->getNext()!= nullptr) {
            if (temp->getNext()->getReferences() == 0) {
                delete (temp->getNext()->getMemDir());
                temp->setNext(temp->getNext()->getNext());
                size--;
                break;
            }
            temp = temp->getNext();
        }
    }
}

template <typename T>
int LinkedList<T>::getDataID(T* data){
    Node<T>* temp = head;
    //consigue el id del dato
    while(temp!= nullptr){
        if(temp->getMemDir() == data){
            return temp->getID();
        }
        temp = temp->getNext();
    }
}

template <typename T>
Node<T> LinkedList<T>::getNodeID(int id){
    Node<T>* temp = head;
    while(temp!= nullptr){
        if(temp->getID() == id){
            return temp;
        }
        temp = temp->getNext();
    }
}

template <typename T>
bool LinkedList<T>::searchID(int id){
    Node<T>* temp = head;
    while(temp!= nullptr){
        if(temp->getID() == id){
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}





