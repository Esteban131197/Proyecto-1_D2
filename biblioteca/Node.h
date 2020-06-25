
#pragma once
/**
 * @file Node.h
 * @date 28/05/20
 * @author Brayan Solano
 * @brief Define un tipo ed variable para almacenar datos
 * 
*/

using namespace std;
/**
 * @brief nodo
 * 
 * @tparam T tipo del nodo
 */
template <typename T>
class Node {
private:
    T* data;
    Node<T>* next;
    int id;
    string dataType;
    int references = 1;

public:
    /**
     * @brief getData Obtiene dato almacenado en atributo T*
     * @return Dato generico almacenado en puntero 
    */
    T getData();
    /**
     * @brief getMemDir Obtiene el puntero T*
     * @return Puntero
    */
    T* getMemDir();
    /**
     * @brief getNext Obtiene el nodo de tipo puntero el cual apunta a un dato de otro nodo
     * @param Puntero nodo
    */
    Node* getNext();
    /**
     * @brief setData Asigna un nuevo dato al puntero T*
     * @param newData Data que es asignado
    */
    void setData(T* newData);
    /**
     * @brief setNext Asigna el nuevo puntero al cual se va a referenciar
     * @param next puntero al cual se va a apuntar
    */
    void setNext(Node* next);
    /**
     * @brief setID  Asigna un nuevo int id al nodo
     * @param newID int el cual sera el id del nuevo nodo
    */
    void setID(int newID);
    /**
     * @brief getID
     * @return int que representa un identificador de cada nodo
    */
    int getID();
    /**
     * @brief setDataType asigna un string que indica el tipo de dato almacenado en puntero T*
     * @param newDataType  string que indica si es int, string o bool
     * 
    */
    void setDataType(string newDataType);
    /**
     * @brief getDataType Obtiene string que indica el tipo de dato almacenado
     * @return string del tipo de dato
    */
    string getDataType();
    /**
     * @brief getReferences Obtiene int de la cantidad de referencias que posee cada nodo
     * @return int cantidad de referencias
    */
    int getReferences();
    /**
     * @brief setReferences Asigna la cantidad de referencias que posee cada nodo
     * @param newRef int que indica cantidad de referencias
    */
    void setReferences(int newRef);

};


template <typename T>
T Node<T>::getData() {
    return (*this->data);
}

template <typename T>
T* Node<T>::getMemDir() {
    return (this->data);
}

template <typename T>
Node<T>* Node<T>::getNext() {
    return this->next;
}

template <typename T>
void Node<T>::setData(T* newData) {
    this->data = newData;
}

template <typename T>
void Node<T>::setNext(Node *next) {
    this->next = next;
}

template <typename T>
int Node<T>::getID() {
    return this->id;
}

template <typename T>
void Node<T>::setID(int newID) {
    this->id = newID;
}

template <typename T>
void Node<T>::setDataType(string newDataType) {
    this->dataType = newDataType;
}

template <typename T>
string Node<T>::getDataType()  {
    return this->dataType;
}

template <typename T>
void Node<T>::setReferences(int newRef) {
    this->references = newRef;
}

template <typename T>
int Node<T>::getReferences() {
    return this->references;
}
