#include <iostream>
#include "TomatoApp.h"
using namespace std;

int main(){
    TomatoApp* tomato=new TomatoApp();

    User * user=new User(101,"Salman","Banglore");
    cout << "User: " << user->getName() << " is active." << endl;

    vector<Restaurant*> restaurantList= tomato->searchRestaurants(user->getAddress());

    if (restaurantList.empty()) {
    cout << "No restaurants found!" << endl;
    return 0;
    }
    cout << "Found Restaurants:" << endl;
    for (auto restaurant : restaurantList) {
        cout << " - " << restaurant->getName() << endl;
    }

    tomato->selectRestaurant(user,restaurantList[0]);

    cout << "Selected restaurant: " << restaurantList[0]->getName() << endl;

    tomato->addToCart(user, "P1");
    tomato->addToCart(user, "P2");

    tomato->printUserCart(user);

    Order* order = tomato->checkoutNow(user, "Delivery", new UpiPaymentStrategy("1234567890"));

    tomato->payForOrder(user, order);

    delete tomato;
    delete user;

    return 0;
}