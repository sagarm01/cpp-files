#ifndef DeliveryOrder.h
#define DeliveryOrder.h

#include "Order.h"

using namespace std;

class DeliveryOrder : public Order {
    private:

    // where to deliver
    string userAddress;
    public:
    DeliveryOrder(){
        userAddress = "";
    }

    // getters an setters
}


#endif