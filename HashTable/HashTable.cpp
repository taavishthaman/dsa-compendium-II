#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
    string key;
    T value;
    Node * next;
    
    Node(string key, T value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    
    ~Node() {
        if(next != NULL) {
            delete next;
        }
    }
};

template <typename T>
class HashTable {
    int cs;
    int ts;
    Node<T> ** table;
    
    int hashFn(string key) {
        int idx = 0;
        int power = 1;
        
        for(char ch : key) {
            idx = (idx + power * ch) % ts;
            power = (power * 29) % ts;
        }
        
        return idx;
    }
    
    void rehash() {
        Node<T> ** oldTable = table;
        int oldSize = ts;
        //Create an odd number for the table size
        cs = 0;
        ts = 2 * ts + 1;
        table = new Node<T>*[ts];
        
        for(int i=0; i<ts; i++) {
            table[i] = NULL;
        }
        
        for(int i=0; i<oldSize; i++) {
            Node<T> * temp = oldTable[i];
            
            while(temp != NULL) {
                string key = temp->key;
                T val = temp->value;
                insert(key, val);
                temp = temp->next;
            }
            
            if(oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }
        
        delete [] oldTable;
    }
    
public:
    HashTable(int default_size = 7) {
        cs = 0;
        ts = default_size;
        table = new Node<T>*[ts];
        
        for(int i=0; i<ts; i++) {
            table[i] = NULL;
        }
    }
    
    void insert(string key, T val) {
        int idx = hashFn(key);
        
        //Create a new Node
        Node<T> * n = new Node<T>(key, val);
        
        //Insertion at head of the linked list
        n->next = table[idx];
        table[idx] = n;
        cs++;
        
        float loadFactor = cs / ts;
        if(loadFactor > 0.7) {
            rehash();
        }
    }
    
    T * search(string key) {
        int idx = hashFn(key);
        Node<T> * temp = table[idx];
        
        while(temp != NULL) {
            if(temp->key == key) {
                return &temp->value;
            }
            temp = temp->next;
        }
        
        return NULL;
    }
    
    void erase(string key) {
        int idx = hashFn(key);
        
        Node<T> * temp = table[idx];
        
        if(temp->key == key) {
            //Delete the head
            table[idx] = temp->next;
            temp->next = NULL;
            delete temp;
            return;
        } 
        
        while(temp->next != NULL && temp->next->key != key) {
            temp = temp->next;
        }
        
        Node<T> * n = temp->next;
        temp->next = temp->next->next;
        n->next = NULL;
        delete n;
    }
    
    T& operator[](string key) {
        T * valueFound = search(key);
        if(valueFound == NULL) {
            T object;
            insert(key, object);
            valueFound = search(key);
        }
        
        return *valueFound;
    }
    
    void print() {
        for(int i=0; i<ts; i++) {
            Node<T> * temp = table[i];
            cout<<"Bucket "<<i<<"---";
            while(temp != NULL) {
                cout<<temp->key<<"->";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};

int main()
{
    HashTable<int> h;
    h.insert("Mango", 100);
    h.insert("Apple", 80);
    h.insert("Banana", 50);
    h.insert("Orange", 200);
    h.insert("Kiwi", 300);
    h.insert("Papaya", 120);
    h.insert("Plum", 230);
    h.print();
    
    string key;
    cin>>key;
    
    int * val = h.search(key);
    if(val != NULL) {
        cout<<"Value is "<<*val<<endl;
    } else {
        cout<<"No value found"<<endl;
    }
    
    h.erase("Orange");
    h.erase("Kiwi");
    h.print();
    
    h["Grapes"] = 300;
    cout<<"Price of grapes "<<h["Grapes"]<<endl;
    h["Grapes"] += 20;
    cout<<"New price of grapes "<<h["Grapes"]<<endl;
    return 0;
}