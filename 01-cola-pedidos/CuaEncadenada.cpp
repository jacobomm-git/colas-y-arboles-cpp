/*
#include <iostream>
#include <vector>
#include "CuaEncadenada.h"
#include "Node.h"
using namespace std; 

template<class T>
CuaEncadenada<T>::CuaEncadenada(){
    Node<T> *sent = new Node<T>(0);
    _front = sent;
    _rear = sent;
}

template<class T>
CuaEncadenada<T>::CuaEncadenada(const CuaEncadenada<T>& q){
    Node<T> *sent2 = new Node<T>;
    _front = sent2;
    _rear = sent2;
    while(q != nullptr){
        _front->enqueue(q->getElement());
        q = q->getNext();
    }
}

template<class T>
CuaEncadenada<T>::~CuaEncadenada(){
    while(_front->getNext()!= nullptr){
        dequeue();
    }
}

template<class T>
bool CuaEncadenada<T>::isEmpty(){
    if(_rear == nullptr){
        return true;
    } else {
        return false;
    }
}

template<class T>
void CuaEncadenada<T>::enqueue(const T key){
    _rear ->setNext(new Node<T>(key));
    _rear = _rear->getNext();
}

template<class T>
void CuaEncadenada<T>::dequeue(){
    if(isEmpty() = true){
        throw out_of_range("EXECEPTION: La cola esta vacia");
    } else {
        Node<T> *aux = _front->getNext();
        _front->setNext()(aux->getNext());
        delete aux;
    }
}

template<class T> 
void CuaEncadenada<T>::print(){
    Node<T> *x = _front->getNext();
    cout<<"[";
    while(x != nullptr){
        cout<<x->getElement() <<" ";
        x = x->getNext();
    }
    cout<<"]"<<endl;
}

template<class T>
const T CuaEncadenada<T>::getFront(){
    if(isEmpty() = true){
        throw out_of_range("EXCEPTION: La cola esta vacia");
    }
    return _front->getNext()->getElement();
}
*/ 