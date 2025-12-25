#ifndef USER_H
#define USER_H

#include <string>
#include "Cart.h"

using namespace std;

class User {
    private:

     int userId;
     string name;
     string address;
     Cart* cart;

    public:

    User(int userId,string& name, const string& address){
        this->userId = userId;
        this->name = name;
        this->address = address;
    }

    ~User(){
        delete cart;
    }

    // getters and setters

};


#endif