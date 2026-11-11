#ifndef CUAENCADENADA_H
#define CUAENCADENADA_H
#include "Node.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <utility>
using namespace std; 

template<class T>
class CuaEncadenada{
    public:
        CuaEncadenada();
        CuaEncadenada(const CuaEncadenada<T>& q);
        ~CuaEncadenada();
        CuaEncadenada<T>& operator=(CuaEncadenada<T> other) {
            std::swap(_front, other._front);
            std::swap(_rear, other._rear);
            return *this;
        }
        bool isEmpty();
        void print();
        void enqueue(const T key);
        void dequeue();
        const T getFront();

    private:
        Node<T>* _front; 
        Node<T>* _rear;

};

template<class T>
CuaEncadenada<T>::CuaEncadenada(){
    Node<T> *sent = new Node<T>();
    _front = sent;
    _rear = sent;
}

template<class T>
CuaEncadenada<T>::CuaEncadenada(const CuaEncadenada<T>& q){
    Node<T> *sent2 = new Node<T>();
    _front = sent2;
    _rear = sent2;
    for (Node<T>* node = q._front->getNext(); node != nullptr; node = node->getNext()){
        enqueue(node->getElement());
    }
}

template<class T>
CuaEncadenada<T>::~CuaEncadenada(){
    while(!isEmpty()){
        dequeue();
    }
    delete _front;
}

template<class T>
bool CuaEncadenada<T>::isEmpty(){
    if(_front == _rear){
        return true;
    } else {
        return false;
    }
}

template<class T>
void CuaEncadenada<T>::enqueue(const T key){
    _rear->setNext(new Node<T>(key));
    _rear = _rear->getNext();
}

template<class T>
void CuaEncadenada<T>::dequeue(){
    if(isEmpty() == true){
        throw out_of_range("EXECEPTION: La cola esta vacia");
    } else {
        Node<T> *aux = _front->getNext();
        if(aux->getNext() == nullptr){
            _rear = _front;
        }
        _front->setNext(aux->getNext());
        delete aux;
    }
}

template<class T>
void CuaEncadenada<T>::print(){
    Node<T> *x = _front->getNext();
    cout<<"[--";
    while(x != nullptr){
        cout<<x->getElement() <<"--";
        x = x->getNext();
    }
    cout<<"]"<<endl;
}

template<class T>
const T CuaEncadenada<T>::getFront(){
    if(isEmpty() == true){
        throw out_of_range("EXCEPTION: La cola esta vacia");
    }
    return _front->getNext()->getElement();
}

#endif //COMANDA  