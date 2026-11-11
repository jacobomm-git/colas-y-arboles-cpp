//comentarios BSTNode en el ejercicio 1
#ifndef BSTNODE_H
#define BSTNODE_H
#include<iostream>
#include<vector>
#include<list>
using namespace std;

template <class K, class V> 
class BSTNode {
    public:
        BSTNode(const K& key);
        BSTNode(const BSTNode<K, V>& orig);
        virtual ~BSTNode();

/* Modificadors */
// Declareu-hi aquí els modificadors (setters) dels atributs que manquen
        void setRight(BSTNode<K, V>* key){this->right = key; right->setPadre(this);};
        void setLeft(BSTNode<K, V>* key){this->left = key; left->setPadre(this);};
        void setPadre(BSTNode<K, V>* key){this->padre = key;};
/* Consultors */
        const K& getKey() const{return this->key;};
        const list<V>& getValues() const{return this->values;};
// Declareu-hi aquí els consultors (getters) dels atributs que manquen
        BSTNode<K, V> *getRight() const{return this->right;};
        BSTNode<K, V> *getLeft() const{return this->left;};
        BSTNode<K, V> *getPadre() const{return this->padre;};


/* Operacions */
        bool isRoot() const{return this->padre == nullptr;};
        bool hasLeft() const{return left!=nullptr;};
        bool hasRight() const{return right!=nullptr;};
        bool isExternal() const{return !hasLeft() && !hasRight();};//hasleft , hasright -> false.
        void insertValue(const V& v){values.push_back(v);};
        int depth() const;
        int height() const;
        bool operator==(const BSTNode<K,V>& node) const;

    private:
        K key;
        list<V> values;
// Afegiu-hi aquí els atributs que manquen
        BSTNode<K, V> *left;
        BSTNode<K, V> *right;
        BSTNode<K, V> *padre;
};

template<class K, class V>
BSTNode<K, V>::BSTNode(const K& key){
        
        this->key = key;
        this->padre = nullptr;
        this->right = nullptr;
        this->left = nullptr;
}

template<class K, class V>
BSTNode<K, V>::BSTNode(const BSTNode<K, V>& orig){

    this->key = orig.key;
    this->values = orig.values;
    if(orig.hasLeft()){
            this->setLeft(new BSTNode<K,V>(*orig.left));
    } 
    if(orig.hasRight()){ 
        this->setRight(new BSTNode<K,V>(*orig.right));
    }
}
template<class K, class V>
BSTNode<K, V>::~BSTNode(){
        delete right;
        delete left;
}

template<class K,class V>
int BSTNode<K, V>::depth() const{
        if(isRoot()){
                return 0;
        } else {
                return 1 + padre->depth();
        }             
}

template<class K, class V>
int BSTNode<K, V>::height() const{
        
        if(this->isExternal()){
                return 1;
        } else if(right == nullptr){
                return height(this->left) + 1;
        } else if(left == nullptr){
                return height(this->left) + 1;
        } else{
                return max(height(this->left(), height(this->right))) + 1;
        }
}

template<class K, class V>
bool BSTNode<K, V>::operator==(const BSTNode<K,V>& node) const{
        return(node.getKey() == this->key) && (node.getValues() == this->values);
}

#endif