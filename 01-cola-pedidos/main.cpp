#include<iostream>
#include <vector>
#include "CuaEncadenada.h"
#include "Comanda.h"
#include "Node.h"
using namespace std;
#include <fstream>
#include<sstream>

int option_menu;
int key;
string id;
string nombre;
int cantidad;
string hora;
string cant;
string newline = "";

ifstream fichero("fichero.txt");


int show_menu(vector<string> menu){
    int options;
    for (int i = 0; i < menu.size(); i++){
        cout<< i+1 << ". " << menu[i] << endl;
    }
        
    if (!(cin >> options)) return 5;

    while(options < 1 || menu.size() < options){
        cout<< options << " Es una opcio incorrecte, escull una opcio entre 1 i " << menu.size() << endl;
        if (!(cin >> options)) return 5;
    }
    return options;
}

void menu_fichero(CuaEncadenada<Comanda> *cua, ifstream &fichero){

    if (!fichero.is_open()) {
        fichero.clear();
        fichero.open("fichero.txt");
    }
    if (!fichero) {
        cerr << "No es pot obrir fichero.txt" << endl;
        return;
    }
    while(getline(fichero, newline)){
        if (newline.empty()) continue;
        stringstream str(newline);
        
        getline(str, id, ',');
        getline(str, nombre, ',');
        getline(str, cant, ',');
        getline(str, hora, ',');

        Comanda com(id, nombre, stoi(cant), hora);
        cua->enqueue(com);
    }
    fichero.close();
}

void pedido(CuaEncadenada<Comanda>* cua){

    cout<<"Id: "<<endl;
    cin>>id;
    cout<<"nombre: "<<endl;
    cin>>nombre;
    cout<<"nº de platos:"<<endl;
    cin>>cantidad;
    cout<<"Hora de regitro del pedido: "<<endl;
    cin>>hora;

    Comanda com(id, nombre, cantidad, hora);
    cua->enqueue(com);

}

CuaEncadenada<Comanda> *cua = new CuaEncadenada<Comanda>();


int main(){
    
    vector<string> menu = {"Llegir el menu amb les entrades de las comandes", "Eliminar una comanda", "Inserir n entrades de comandes (0 per finalitzar)", "Imprimir el contingut de la Cua de comandes", "Sortir"};

    do{
        cout<<"Escull una opcio: "<<endl;
        option_menu = show_menu(menu);
        switch(option_menu){
            case 1:
                cout<<"El menu es:"<<endl;
                menu_fichero(cua, fichero);
                break;
            case 2:
            cout<<"Eliminiem una comanda"<<endl;
                try{cua->dequeue();
                } catch(out_of_range error){cout <<"La cola esta vacia"<<endl;};
                break;
            case 3:
                cout<<"Inserita n entrades de comandes: "<<endl;
                cin>>key;
                for(int i = key; i>0;i--){
                   pedido(cua);
                }
                break;
            case 4:
                cout<<"Els valors de la cua de comandes son: "<<endl;                
                cua->print();
                break;
            case 5:
                cout<<"Fins un altre cop!";
                delete cua;
        }
    }while(option_menu != 5);

}


