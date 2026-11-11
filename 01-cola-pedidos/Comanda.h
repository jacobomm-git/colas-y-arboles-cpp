#ifndef COMANDA_H
#define COMANDA_H
#include <iostream>
#include <string>
using namespace std;

class Comanda{
    public:
        Comanda(string id, string nombre, int cantidad, string hora);
        Comanda(){};
        Comanda(const Comanda& other);
        string toString()const;
        friend std::ostream& operator<<(std::ostream& os, const Comanda& obj); 
    private:
        string id;
        string nombre;
        int cantidad;
        string hora;


};

#endif