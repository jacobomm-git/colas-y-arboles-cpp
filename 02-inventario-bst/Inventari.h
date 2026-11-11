#ifndef Inventari_H
#define Inventari_H
using namespace std;
#include <fstream>
#include <sstream>
#include "FoodPackage.h"
#include "BSTNode.h"
#include "BSTArbre.h"
#include <iostream>
#include <vector>
#include <list>
#include <utility>
    
    template <class T>
    class Inventari : protected T {
        public:
            Inventari(float iva){this->iva = iva;};
            Inventari(float iva, string file_path);
            Inventari(const Inventari<T>& orig);
            virtual ~Inventari(); 
            void loadFromFile(string file_path);
            void printAll() const;
            void printAllReverse() const;
            float priceInTotal() const;
            float priceInTimeInterval(pair<string, string> ival) const;
            float priceInTimeIntervalByProduct(pair<string, string> ival, string pid) const; 
            int size() const{return this->size();};
            int height() const{return this->height();}; 
        private:
            float iva;
            /* Metodes auxiliars, definiu-los aquí sota */
            BSTNode<string, FoodPackage>* printAll_aux(BSTNode<string, FoodPackage>* node) const;
            BSTNode<string, FoodPackage>* printAllReverse_aux(BSTNode<string, FoodPackage>* node) const;
            float priceInTotal_aux(BSTNode<string, FoodPackage>* node, float &precio) const;
            void priceInTimeInterval_aux(BSTNode<string, FoodPackage>* node, pair<string,string> ival, float &precio) const;
            float priceInTimeIntervalByProduct_aux(BSTNode<string, FoodPackage>* node, string pid, pair<string, string>& ival, float &precio) const;

};

//Constructor de Inventari
template<class T>
Inventari<T>::Inventari(float iva, string file_path){
    this->iva = iva;
    loadFromFile(file_path);
}

//Constructor copia de inventari
template<class T>
Inventari<T>::Inventari(const Inventari<T>& orig){
    this->iva = orig.iva;
}

//destructo de inventari
template<class T>
Inventari<T>::~Inventari(){
}

//Metodo loadfromfile extrae la informacion del archivo seleccionado y crea un objeto
//de tipo FoodPackage de todos los atributos de cada fila del archivo en el
//oreden respectivo.
template<class T>
void Inventari<T>::loadFromFile(string file_path){
    ifstream file_obj;
    string newline = "";
    
    file_obj.open(file_path, ios::in);
    if(file_obj.is_open()){
        string date;
        string id;
        string amount;
        string price;
        getline(file_obj, newline);
        while(!file_obj.eof()){
            getline(file_obj, newline);
            stringstream str(newline);

            getline(str, date, ',');
            getline(str, id, ',');
            getline(str, amount, ',');
            getline(str, price);

            FoodPackage obj(date, id, stoi(amount), stof(price));
            this->insert(date, obj); 
        }
        file_obj.close();
    }
}

//Metodo printall imprime todos los objetos de tipo FoodPackage con el metodo
//toString de este del archivo cargado anteriormente
template<class T>
void Inventari<T>::printAll() const{
    if(this->empty()){
        throw new out_of_range("No hi ha res");
    } else {
        printAll_aux(T::root);
    }
}

//auxiliar de printall
template<class T>
BSTNode<string, FoodPackage>* Inventari<T>::printAll_aux(BSTNode<string, FoodPackage>* node) const{
    if(node->hasLeft()){
        printAll_aux(node->getLeft());
    }
    list<FoodPackage> lista1 = node->getValues();
    for(list<FoodPackage>::iterator iterador=lista1.begin(); iterador != lista1.end(); iterador++){
        cout<<iterador->toString();
    }
    if(node->hasRight()){
        printAll_aux(node->getRight());
    }
    return node;
}

//Metodo printallreverse tiene el mismo objetivo que el printall
//solo que los imprime empezando por el ultimo y acabando con el primero
template<class T>
void Inventari<T>::printAllReverse() const{

    if(this->empty()){
        throw new out_of_range("No hi ha res");
    } else {
        BSTNode<string, FoodPackage>* ultimo = T::root;
        printAllReverse_aux(ultimo);

    }

}

//auxiliar de printallreverse
template<class T>
BSTNode<string, FoodPackage>* Inventari<T>::printAllReverse_aux(BSTNode<string, FoodPackage>* node) const{

    if(node->hasRight()){
        printAllReverse_aux(node->getRight());
    }
    list<FoodPackage> lista2 = node->getValues();
    for(list<FoodPackage>::const_reverse_iterator iterador=lista2.rbegin(); iterador != lista2.rend(); iterador++){
        cout<<iterador->toString();
    }
    if(node->hasLeft()){
        printAllReverse_aux(node->getLeft());
    }
    return node;
}

//Metodo priceintotal devuelve el precio total del archivo cargado anteriormente
//siguiendo las instrucciones del enunciado, que seria multiplicar el precio del
//producto por la cantidad que hay de este y por el iva + 1
template<class T>
float Inventari<T>::priceInTotal() const{
    if(this->empty()){
        throw new out_of_range("No hi ha res");
    } else {
        float precio = 0.0;
        BSTNode<string, FoodPackage>* nodoP = this->root;
        return(priceInTotal_aux(nodoP, precio));
    }
}

//auxiliar de priceintotal
template<class T>
float Inventari<T>::priceInTotal_aux(BSTNode<string, FoodPackage>* node, float &precio)const{
    if(node->hasLeft()){
        priceInTotal_aux(node->getLeft(), precio);
    }
    
    list<FoodPackage> listaPT = node->getValues();
    for(list<FoodPackage>::iterator iterador=listaPT.begin(); iterador != listaPT.end(); iterador++){
        precio += (iterador->getPrice()*iterador->getAmount()*(1+iva));
    }
    if(node->hasRight()){
        priceInTotal_aux(node->getRight(), precio);
    }
    return precio;
}

//priceintimeinterval hace lo mismo que el priceintotal pero solo calcula el precio a partir de un intervalo
//de tiempo introducido.
template<class T>
float Inventari<T>::priceInTimeInterval(pair<string, string> ival) const{
        float precio = 0.0f;
        BSTNode<string, FoodPackage>* node = T::root;
        priceInTimeInterval_aux(node, ival, precio);
        return precio;
}

//auxiliar de priceintimeinterval
template<class T>
void Inventari<T>::priceInTimeInterval_aux(BSTNode<string, FoodPackage>* node, pair<string, string> ival, float &precio) const{
    if(node->hasLeft()){
        priceInTimeInterval_aux(node->getLeft(), ival, precio);
    }
    if(node->getKey() >= ival.first && node->getKey() <= ival.second){
        list<FoodPackage> lista = node->getValues();
        for(list<FoodPackage>::iterator iterador=lista.begin(); iterador != lista.end(); iterador++){
            precio += (iterador->getPrice()*iterador->getAmount()*(1+iva));
        } 
    }
    if(node->hasRight()){
        priceInTimeInterval_aux(node->getRight(), ival, precio);
    }
}

//metodo priceintimeintervalbyproduct hace lo mismo que hace priceintimeinterval solo que ahora
//tambien calcula el precio de los productos que tengan el mismo id.
template<class T>
float Inventari<T>::priceInTimeIntervalByProduct(pair<string, string> ival, string pid) const{
    float precio = 0.0f;
    if(this->empty()){
        throw new out_of_range("no hi ha res");
    } else {
        BSTNode<string, FoodPackage>* node = this->root;
        priceInTimeIntervalByProduct_aux(node, pid, ival, precio);
    }
    return precio;
    
}

//auxiliar de priceintimeinterval
template<class T>
float Inventari<T>::priceInTimeIntervalByProduct_aux(BSTNode<string, FoodPackage>* node, string pid, pair<string, string>& ival, float &precio) const{
    if(node->hasLeft()){
        priceInTimeIntervalByProduct_aux(node->getLeft(), pid, ival, precio);
    }
    if(node->getKey() >= ival.first && node->getKey() <= ival.second){
        list<FoodPackage> lista = node->getValues();
        for(list<FoodPackage>::iterator iterador=lista.begin();iterador != lista.end();iterador++){
            if(iterador->getID() == pid){
                precio += (iterador->getPrice()*iterador->getAmount()*(1+iva));
            }
        }
    }
    if(node->hasRight()){
        priceInTimeIntervalByProduct_aux(node->getRight(), pid, ival, precio);
    }
    return precio;
}
#endif