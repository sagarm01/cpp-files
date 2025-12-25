#ifndef RESTRAURANT_H
#define RESTRAURANT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

#include "MenuItem.h"

using namespace std;

class Restaurant
{
private:
    static int nextRestaurantId;
    int restaurantId;
    string name;
    string location;
    vector<MenuItem> menu;

public:
    Restaurant(string &name, string &location)
    {
        this->name = name;
        this->location = location;
        this->restaurantId = ++nextRestaurantId;
    }

    ~Restaurant(){
        menu.clear();
    }

    // gettes and setters
    string getLocation(){
        return this->location;
    }
};

int Restaurant:: nextRestaurantId = 0;

#endif
