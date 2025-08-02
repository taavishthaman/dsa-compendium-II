#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Vector {
    //Data Members
    T * arr;
    int cs;
    int ms;
    
    //Constructor, Destructor, Methods
public:
    Vector(int max_size = 1) {
        cs = 0;
        ms = max_size;
        arr = new T[ms];
    }
    
    void push_back(T d) {
        if(cs == ms) {
            T * oldArr = arr;
            ms = 2 * ms;
            arr = new T[ms];
            for(int i=0; i<cs; i++) {
                arr[i] = oldArr[i];
            }
            
            delete [] oldArr;
        }
        arr[cs] = d;
        cs += 1;
    }
    
    bool isEmpty() {
        return cs == 0;
    }
    
    void pop_back() {
        //Avoid doing shrinking
        if(cs > 0) {
           cs--; 
        }
    }
    
    //Constant functions do not modify data members
    T front() const{
        return arr[0];
    }
    
    T back() const{
        return arr[cs-1];
    }
    
    T at(int i) const{
        return arr[i];
    }
    
    int size() const {
        return cs;
    }
    
    int capacity() {
        return ms;
    }
    
    //Define the operator as constant if it does not change
    T operator[](const int i) {
        return arr[i];
    }
};

int main()
{
   Vector<int> v(5);
   v.push_back(1);
   v.push_back(2);
   v.push_back(3);
   v.push_back(4);
   v.push_back(5);
   v.push_back(6);
   v.pop_back();
   v.push_back(16);
   
   cout<<"Size "<<v.size()<<endl;
   cout<<"Capacity "<<v.capacity()<<endl;
   cout<<"Front "<<v.front()<<endl;
   cout<<"Capacity "<<v.back()<<endl;
   cout<<"Element at 2nd index "<<v.at(2)<<endl;
   for(int i=0; i<v.size(); i++) {
       cout<<v[i]<<", ";
   }
   
   Vector<string> strVec;
   
   strVec.push_back("Hello");
   strVec.push_back("World");
   strVec.push_back("Home");
   
   for(int i=0; i<strVec.size(); i++) {
       cout<<strVec[i]<<", ";
   }
}