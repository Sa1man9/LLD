#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include<vector>
#include<algorithm>
#include<string>
#include "../models/Restaurant.h"

using namespace std;

class RestaurantManager{
private:
    vector<Restaurant*> restaurants;
    static RestaurantManager* instance;

    RestaurantManager(){}

    public:
    
    static RestaurantManager* getInstance(){
        if(!instance){
            instance=new RestaurantManager();
        }
        return instance;
    }

    void addRestaurant(Restaurant* r){
        restaurants.push_back(r);
    }
    
    vector<Restaurant*> searchByLocation(string loc){
        vector<Restaurant*> result;
        transform(loc.begin(),loc.end(),loc.begin(),::tolower);

        for(auto r: restaurants){
            string r1=r->getLocation();
            transform(r1.begin(),r1.end(),r1.begin(),::tolower);
            if(r1==loc){
                result.push_back(r);
            }
        }
        return result;
    }

};

RestaurantManager* RestaurantManager::instance=nullptr;
#endif