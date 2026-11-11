#include "Comanda.h"
#include <iostream>
using namespace std;

Comanda::Comanda(string _id, string _nombre, int _cantidad, string _hora){
    this->id = _id;
    this->nombre = _nombre;
    this->cantidad = _cantidad;
    this->hora = _hora;

}

Comanda::Comanda(const Comanda& other){
    this->id = other.id;
    this->nombre = other.nombre;
    this->cantidad = other.cantidad;
    this->hora = other.hora;

}

string Comanda::toString() const{
    string comand = "[Id; "+ this->id+ ", nombre; "+this->nombre+ " cantidad; "+to_string(this->cantidad)+ ", hora; "+this->hora;
    return comand;
}

std::ostream& operator<<(std::ostream& os, const Comanda& obj){
    os << obj.toString();
    return os;
}