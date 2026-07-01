#include<iostream>
using namespace std;

class Animal{

};

class Dog: public Animal{

};

class Parent{
    public:

    virtual Animal* getAnimal(){
        return new Animal();
    }
};

class Child:public Parent{
   virtual Dog* getAnimal(){
        return new Dog();
    }
};

int main()
{
    Parent* child=new Child();
    Animal* animal=child->getAnimal();
    return 0;
}