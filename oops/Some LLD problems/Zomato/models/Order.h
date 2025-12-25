#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Restaurant.h"
#include "MenuItem.h"
#include "../strategies/PaymentStrategy.h"
#include "../utils/TimeUtils.h"

using namespace std;

class Order {
protected:
    static int nextOrderId;
    int orderId;
    User* user;
    Restaurant* restaurant;
    vector<MenuItem*> items;
    PaymentStrategy* paymentStrategy;
    double total;
    string scheduled;

public:
    Order() {
        user = nullptr;
        restaurant = nullptr;
        paymentStrategy = nullptr;
        total = 0.0;
        scheduled = "";
        orderId = nextOrderId++;
    }

    bool processPayment(){
        // use paymentStraetfy.pay()
    }
    
    // gettes and setters

};

int Order::nextOrderId = 1;