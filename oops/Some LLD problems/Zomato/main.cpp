#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>


using namespace std;

// LINK TO THE FULL CODE
// https://github.com/adityatandon15/LLD/tree/main/Lecture%2011/C%2B%2B%20Code/Tomato

int main() {
    // Create TomatoApp facade
    TomatoApp* tomato = new TomatoApp();

    // Simulate a user coming in (Happy Flow)
    User* user = new User(101, "Aditya", "Delhi");
    cout << "User: " << user->getName() << " is active." << endl;

    // User searches for restaurants by location
    vector<Restaurant*> restaurantList = tomato->searchRestaurants("Delhi");

    if (restaurantList.empty()) {
        cout << "No restaurants found!" << endl;
        return 0;
    }

    cout << "Found Restaurants:" << endl;
    for (auto restaurant : restaurantList) {
        cout << " - " << restaurant->getName() << endl;
    }

    // User selects a restaurant
    tomato->selectRestaurant(user, restaurantList[0]);

    cout << "Selected restaurant: " << restaurantList[0]->getName() << endl;
}