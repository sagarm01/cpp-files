#ifndef CART_H
#define CART_H



#include <vector>
#include "Restaurant.h"
#include "MenuItem.h"

using namespace std;

class Cart{
    private:

    Restaurant* restaurant;
    vector<MenuItem> items;


    public:

    Cart(){
        restaurant = nullptr;
    }


    // functions

};


#endif