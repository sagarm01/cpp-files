#include "OrderFactory.h"
#include "DeliveryOrder.h"
#include "PickupOrder.h"
#include "../models/User.h"
#include "../models/Restaurant.h"
#include "../models/MenuItem.h"
#include "../models/Cart.h"
#include "../strategies/PaymentStrategy.h"
#include "../utils/TimeUtils.h"
#include <string>
#include <vector>

using namespace std;

class NowOrderFactory : public OrderFactory {
public:
    Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem*>& menuItems,
                      PaymentStrategy* paymentStrategy, const string& orderType) override {
        Order* order = nullptr;
        if (orderType == "Delivery") {
            auto deliveryOrder = new DeliveryOrder();
            deliveryOrder->setUserAddress(user->getAddress());
            order = deliveryOrder;
        }
        else {
            auto pickupOrder = new PickupOrder();
            pickupOrder->setRestaurantAddress(restaurant->getLocation());
            order = pickupOrder;
        }
        order->setUser(user);
        order->setRestaurant(restaurant);
        order->setItems(menuItems);
        order->setPaymentStrategy(paymentStrategy);
        order->setScheduled(TimeUtils::getCurrentTime());
        order->setTotal(cart->getTotalCost());
        return order;
    }
};