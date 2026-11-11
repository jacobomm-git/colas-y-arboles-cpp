#include "BSTNode.h"
#include "BSTArbre.h"
#include "Inventari.h"
#include "FoodPackage.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <list>
#include <utility>
#include <chrono>
using namespace std;

int show_menu(vector<string> menu){
    int options;
    cout<<"Escull una opcio: "<<endl;
    for (int i = 0; i < menu.size(); i++){
        cout<< i+1 << ". " << menu[i] << endl;
    }
        
    if (!(cin >> options)) return 8;

    while(options < 1 || menu.size() < options){
        cout<< options << " Es una opcio incorrecte, escull una opcio entre 1 i " << menu.size() << endl;
        if (!(cin >> options)) return 8;
    }
    return options;
}

void queries(Inventari<BSTArbre<string, FoodPackage>>& inventario){
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    ifstream file_obj;
    string newline = "";
    string file_path = "fitxer_de_queries.txt";
    
    file_obj.open(file_path, ios::in);
    if(file_obj.is_open()){
        string date;
        while(getline(file_obj, newline)){
            if (newline.empty()) continue;
            stringstream str(newline);
            getline(str, date, ',');
            pair<string, string> queries;
            queries.first = date;
            queries.second = date;
            cout<<inventario.priceInTimeInterval(queries)<<endl;
        }
        file_obj.close();
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::seconds>(end - begin).count() << " s." << endl;
}

void loadFromFile(string file_path, Inventari<BSTArbre<string, FoodPackage>>& inventario){
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    cout<<"Inserta el directorio del fichero: "<<endl;
    cin>>file_path;
    inventario.loadFromFile(file_path);
    cout<<endl;
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::seconds>(end - begin).count() << " s." << endl;
}

void casDeProva(){

    float iva = 0.21f;
    pair<string, string> dates1;
    pair<string,string> dates2;
    dates1.first = "2022-02-01";
    dates1.second = "2022-02-31";
    dates2.first = "2022-01-01";
    dates2.second = "2022-01-31";
    string product_id = "1";
    Inventari<BSTArbre<string, FoodPackage>> inventario(iva);
    inventario.loadFromFile("transaccions_cas_de_prova.txt");
    cout<<inventario.priceInTotal()<<endl;
    cout<<inventario.priceInTimeInterval(dates1)<<endl;
    cout<<inventario.priceInTimeInterval(dates2)<<endl;
    cout<<inventario.priceInTimeIntervalByProduct(dates2, product_id)<<endl;
}

int main(){

    casDeProva();
    float iva = 0.21f;
    string file_path;
    string product_id;  
    Inventari<BSTArbre<string, FoodPackage>> inventario(iva);
    pair <string,string> dates;

    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};

    vector<string> menu = {"Directorio del fichero", "Print All", 
                    "Print All Reverse", "Total Price", "Total Price In Time Interval", 
                    "Total Price In Time Interval By Product", "Queries", "Exit"};

    int opcion = 0;
    do{
        opcion = show_menu(menu);
        switch(opcion){
            case 1:
                loadFromFile(file_path, inventario);
                break;
            case 2:
                inventario.printAll();
                cout<<endl;
                break;
            case 3:
                inventario.printAllReverse();
                cout<<endl;
                break;
            case 4:
                cout<<inventario.priceInTotal();
                cout<<endl;
                break;
            case 5:
                cout<<"Introduce el intervalo de las fechas: "<<endl;
                cout<<"Fecha 1: "; cin>> dates.first;
                cout<<"Fecha 2: "; cin>> dates.second;
                cout<<inventario.priceInTimeInterval(dates);
                cout<<endl;
                break;
            case 6:
                cout<<"Introduce el id del producto: "; cin>>product_id;
                cout<<"Introduce el intervalo de las fechas: "<<endl;
                cout<<"Fecha 1: "; cin>> dates.first;
                cout<<"Fecha 2: "; cin>> dates.second;
                cout<<inventario.priceInTimeIntervalByProduct(dates, product_id);
                cout<<endl;
                break;
            case 7:
                queries(inventario);
                cout<<endl;
                break;
            case 8:
                cout<<"Adeu!"<<endl;
                break;       
        }
    } while(opcion != 8);
}