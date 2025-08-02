#include <bits/stdc++.h>
using namespace std;

class Product {
    int id;
    char * name;
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
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    
    //Copy Constructor
    Product(Product & X) {
        id = X.id;
        mrp = X.mrp;
        selling_price = X.selling_price;
        //Creating a deep copy for the name
        name = new char[strlen(X.name) + 1];
        strcpy(this->name, X.name);
    }
    
    void operator=(Product & X) {
        cout<<"Inside copy assignment operator"<<endl;
         id = X.id;
        mrp = X.mrp;
        selling_price = X.selling_price;
        //Creating a deep copy for the name
        name = new char[strlen(X.name) + 1];
        strcpy(this->name, X.name);
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
    
    void setName(char * name) {
        strcpy(this->name, name);
    }
    
    void showDetails() {
        cout<<"Id is "<<id<<endl;
        cout<<"Name is "<<name<<endl;
        cout<<"Selling Price is "<<selling_price<<endl;
        cout<<"MRP is "<<mrp<<endl;
        cout<<"------------------------"<<endl;
    }
    
    ~Product() {
        cout<<"Deleting "<<name<<endl;
        
        if(name != NULL) {
            delete [] name;
            name = NULL;
        }
    }
};

int main()
{
    Product camera(101, "GoPro Hero 8", 28000, 26500);
    
    Product old_camera = camera; //Copy Assignment operator
    old_camera.setName("GoPro7");
    camera.showDetails();
    old_camera.showDetails();
    
    //Product handycam = camera;
    //Object will take up some space in memory.
    //cout<<"Object Size "<<sizeof(camera)<<" Bytes"<<endl;
    // camera.setMrp(200);
    // camera.setSellingPrice(300);
    
    // cout<<"MRP is "<<camera.getMrp()<<endl;
    // cout<<"Selling Price is "<<camera.getSellingPrice()<<endl;
    
    // webcam.showDetails();
    // handycam.showDetails();
    
    
    return 0;
}