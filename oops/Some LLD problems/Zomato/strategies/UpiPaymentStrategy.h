#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class UpiPaymentStrategy : public PaymentStategy{
    private:
    string mobile;
    public:
    UpiPaymentStrategy(string& mob){
        mobile = mob;
    }

    void pay(double amount) override {
        cout<<"PAID BY UPI";
    }

};

#endif