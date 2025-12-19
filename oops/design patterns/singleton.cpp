#include<iostream>

using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;
    
    Singleton() {
        cout << "Singleton Constructor called. New Object created." << endl;
    }
    
public:
    static Singleton* getInstance() {
        if(instance == nullptr){
         lock_guard<mutex> lock(mtx); // lock the block for thread safety in case of parallel processing
         if(instance == nullptr){
          instance = new Singleton();
         }
        }
        return instance;
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    
    cout << (s1 == s2) << endl;
    
    return 0;
}