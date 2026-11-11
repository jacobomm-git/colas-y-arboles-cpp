//comentarios BSTArbol en el ejercicio 1
#ifndef BSTARBRE_H
#define BSTARBRE_H
#include "BSTNode.h"
using namespace std;

template <class K, class V> 
class BSTArbre {
    public:
        BSTArbre();
        BSTArbre(const BSTArbre<K, V>& orig);
        virtual ~BSTArbre();
        bool empty() const{return root == nullptr;};
        int size() const;
        int height() const;
        BSTNode<K,V>* insert(const K& k, const V& value);
        const list<V>& valuesOf(const K& k) const;
        void printPreorder(const BSTNode<K,V>* n = nullptr) const;
        void printInorder(const BSTNode<K,V>* n = nullptr) const;
        void printPostorder(const BSTNode<K,V>* n = nullptr) const;
        const list<BSTNode<K, V>*> getLeafNodes() const;
        void printSecondLargestKey() const;
        void mirrorTree(); 
    protected:
        BSTNode<K,V>* root;
        BSTNode<K,V>* search(const K& k) const;
    private:
        int _size;
    /* Mètodes auxiliars definiu aquí els que necessiteu */
        BSTNode<K, V>* search_aux(const K& k, BSTNode<K, V>*& n);
        void mirrorTree_aux(BSTNode<K, V>* n) const;
        void leafs_aux(list<BSTNode<K, V>>& l, BSTNode<K, V>* n);
        BSTNode<K, V>* secondLargetsKey_aux(const BSTNode<K, V>* n) const;


        
};

template<class K, class V>
BSTArbre<K, V>::BSTArbre(){
    root = nullptr;
    this->_size = 0;
    cout<<"Arbre binari creat"<<endl;
}

template<class K, class V>
BSTArbre<K, V>::BSTArbre(const BSTArbre<K, V>& orig){
    this->root = new BSTNode<K, V>(*orig.root);
    this->_size = orig._size;
}

template<class K, class V>
BSTArbre<K, V>::~BSTArbre(){
    delete root;
    cout<<"Arbre binari destruit"<<endl;
    cout<<endl;
}

template<class K, class V>
BSTNode<K, V>* BSTArbre<K, V>::search(const K& k) const{
    BSTNode<K, V>* padre = nullptr;
    return search_aux(k, padre);
}

template<class K, class V>
BSTNode<K, V>* BSTArbre<K, V>::search_aux(const K& k, BSTNode<K, V>*& n){
    BSTNode<K, V>* puntero = root;
    bool aux = true;
    while(aux){
        if(puntero == nullptr){
            
            return nullptr;
        }
        if(k == puntero->getKey()){
            
            return puntero;
        }

        n = puntero;

        if(puntero->getKey() > k){
            
            puntero = puntero->getLeft();
        } else {
            
            puntero = puntero->getRight();
        }
    }
    return puntero;
}

template<class K, class V>
int BSTArbre<K, V>::size() const{
    
    if(empty()){
        throw new invalid_argument("Arbre buit");
        return 0;
    } else {
        return _size;
    }
    
}

template<class K, class V>
int BSTArbre<K, V>::height() const{
    if(empty()){
        throw new invalid_argument("Arbre buit");
        return 0;
    } else {
        return root->height();
    }
}
template<class K, class V>
BSTNode<K, V>* BSTArbre<K, V>::insert(const K& k, const V& value){
    cout<<"insertado el nodo: "<<k<<endl;
    BSTNode<K, V>* puntero = nullptr;
    BSTNode<K, V>* puntero_aux = search_aux(k, puntero);
    if(puntero_aux != nullptr){
        cout<<"Insertar elemento"<<endl;
        puntero_aux->insertValue(value);
    } else {
        BSTNode<K, V>* nuevo = new BSTNode<K, V>(k);
        _size++;
        cout<<"Insertar elemento"<<endl;
        nuevo->insertValue(value);

        if(root == nullptr){
            root = nuevo;
        } else {
            if(k < puntero->getKey()){
                puntero->setLeft(nuevo);
            } else if (k > puntero->getKey()){
                puntero->setRight(nuevo);
            }
        }
        return nuevo;
    }
    return puntero_aux;
}

template<class K, class V>
const list<V>& BSTArbre<K, V>::valuesOf(const K& k) const{
    if(search(k) == nullptr){
        throw new out_of_range("No existeix aquest element");
    } else {
        return search(k)->getValues();
    }

}

template<class K, class V>
void BSTArbre<K,V>::printPreorder(const BSTNode<K,V>* n) const{ // O(n)
    
    if(empty()){
        throw new out_of_range("Arbre buit");
    }
    if(n == nullptr){
        return printPreorder(root);
    } else {
        cout<<n->getKey()<<" ; ";
        if(n->hasLeft()){
            printPreorder(n->getLeft());
        }
        if(n->hasRight()){
            printPreorder(n->getRight());
        }
        
    }
}

template<class K, class V>
void BSTArbre<K,V>::printInorder(const BSTNode<K,V>* n) const{
    
    if(empty()){
        throw new out_of_range("Arbre buit");
    }
    if(n==nullptr){
        
        return printInorder(root);
    } else {
        
        if(n->hasLeft()) printInorder(n->getLeft());
            cout<<n->getKey()<<" ; ";
        if(n->hasRight()) printInorder(n->getRight());
    }
    
}

template<class K, class V>
void BSTArbre<K,V>::printPostorder(const BSTNode<K,V>* n) const{
    
    if(empty()){
        throw new out_of_range("Arbre buit");
    }
    if(n == nullptr){
        return printPostorder(root);
    } else {
        if(n->hasLeft()) printPostorder(n->getLeft());
        if(n->hasRight()) printPostorder(n->getRight());
            cout<<n->getKey()<<" ; ";
    }
}

template<class K, class V>
void BSTArbre<K, V>::printSecondLargestKey() const{
    if(empty()){
        throw new out_of_range("Arbre buit");
    }
    cout<<"La segona ,,key,, mes gran es: "<<secondLargetsKey_aux(root)->getKey()<<endl;
}

template<class K, class V>
BSTNode<K, V>* BSTArbre<K, V>::secondLargetsKey_aux(const BSTNode<K, V>* n) const{
    if(n->hasRight() == false){
        if(n->hasLeft()) return n->getLeft();
            return n->getPadre();
    }
    return secondLargetsKey_aux(n->getRight());
}

template<class K, class V>
const list<BSTNode<K, V>*> BSTArbre<K,V>::getLeafNodes() const{
    list<BSTNode<K, V>*> lista_aux;
    leafs_aux(lista_aux, root);
    return lista_aux;
}

template<class K, class V>
void BSTArbre<K, V>::leafs_aux(list<BSTNode<K, V>>& l, BSTNode<K, V>* n){
    if(n == nullptr){
        return;
    }
    leafs_aux(l, n->getLeft());
    if(n->isExternal()){
        l.push_back(n);
    }
    leafs_aux(l, n->getRight());
}

#endif