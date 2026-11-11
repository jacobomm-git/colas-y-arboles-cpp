#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;


template<class T>
class Node{
    public:
        Node(T t);
        Node(const Node<T>& key);
        const T& getElement()const{return _element;};
        Node<T> *getNext(){return next;};
        void setNext(Node<T> *t){next = t;};
        Node(){next = nullptr;};
    private:
        T _element;
        Node<T> *next;
};

template<class T>
Node<T>::Node(T t){
    this->next = nullptr;
    this->_element = t;
}

template<class T>
Node<T>::Node(const Node<T>& key){
    this->next = nullptr;
    this->_element = key._element;
}

#endif   