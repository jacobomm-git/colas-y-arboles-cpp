#ifndef FoodPackage_H
#define FoodPackage_H
#include <iostream>
using namespace std;

class FoodPackage{
    public:
        FoodPackage(string date_time, string profuct_id, int amount, float price);
        FoodPackage(const FoodPackage& orig);

        string getDate() const{return this->date_time;};
        string getID() const{return this->product_id;};
        int getAmount() const{return this->amount;};
        float getPrice() const{return this->price;};

        void setData(string date){this->date_time = date;};
        void setID(string product_id){this->product_id = product_id;};
        void setAmount(int amount){this->amount = amount;};
        void setPrice(float price){this->price = price;};

        void print() const;
        string toString() const;

    private:
        string date_time;
        string product_id;
        int amount;
        float price;
};

//comstructor de FoodPackage
FoodPackage::FoodPackage(string _date_time, string _product_id, int _amount, float _price){
    
    this->date_time = _date_time;
    this->product_id = _product_id;
    this->amount = _amount;
    this->price = _price;
}

//constructor copia de FoodPackage
FoodPackage::FoodPackage(const FoodPackage& orig){
    this->date_time = orig.date_time;
    this->product_id = orig.product_id;
    this->amount = orig.amount;
    this->price = orig.price;
}

//print de los atributos de foodpackage
void FoodPackage::print() const{
    cout<<this->date_time<<", "<<this->product_id<<", "<<this->amount<<", "<<this->price<<endl;
}

//metodo toString devuelve un string de los atributos de FoodPackage
string FoodPackage::toString() const{

    string m = "(Data: "+ this->date_time+", Id dels producte: "+this->product_id+
               ", Quantitat: "+to_string(this->amount)+", Preu del producte: "+to_string(this->price)+")";
    cout<<endl;
    
    return m;
}

//operator
std::ostream& operator<<(std::ostream& os, const FoodPackage obj){
    os <<obj.toString();
    return os;
}
#endif