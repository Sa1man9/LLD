#include<iostream>
using namespace std;

class Car{
    protected:
    int speed;
    public:

    Car(){
        speed=0;
    }

    virtual void accelarate(){
        speed++;
    }
};

class HybridCar:public Car{
    protected:
    int charge;
    HybridCar():Car(){
        charge=0;
    }

    void accelarate() override{
        speed++;
        charge--;
    }
};
int main()
{
    return 0;
}