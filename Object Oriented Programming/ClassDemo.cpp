#include <bits/stdc++.h>
using namespace std;

class Product {
    int id;
    char name[100];
    int mrp;
    int selling_price;
    
public:
    //Constructor
    Product() {
        cout<<"Inside Constructor"<<endl;
    }
    
    Product(int id, char * n, int mrp, int selling_price) {
        this->id = id;
        this->mrp = mrp;
        this->selling_price = selling_price;
        strcpy(name, n);
    }
    
    //Copy Constructor
    Product(Product & X) {
        id = X.id;
        mrp = X.mrp;
        selling_price = X.selling_price;
        strcpy(name, X.name);
    }
    
    //Setters
    void setMrp(int price) {
        if(price > 0) {
            mrp = price;
        }
    }
    
    void setSellingPrice(int price) {
        if(price > mrp) setSellingPrice(mrp);
        selling_price = price;
    }
    
    //Getters
    int getMrp() {
        return mrp;
    }
    
    int getSellingPrice() {
        return selling_price;
    }
    
    void showDetails() {
        cout<<"Id is "<<id<<endl;
        cout<<"Name is "<<name<<endl;
        cout<<"Selling Price is "<<selling_price<<endl;
        cout<<"MRP is "<<mrp<<endl;
        cout<<"------------------------"<<endl;
    }
};

int main()
{
    Product camera(101, "GoPro Hero 8", 28000, 26500);
    
    //Copy is made using special constructor called copy constructor
    Product webcam(camera);
    
    Product handycam = camera;
    //Object will take up some space in memory.
    cout<<"Object Size "<<sizeof(camera)<<" Bytes"<<endl;
    // camera.setMrp(200);
    // camera.setSellingPrice(300);
    
    cout<<"MRP is "<<camera.getMrp()<<endl;
    cout<<"Selling Price is "<<camera.getSellingPrice()<<endl;
    
    webcam.showDetails();
    handycam.showDetails();
    return 0;
}