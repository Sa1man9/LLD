#include<iostream>
using namespace std;

class Parent{
    public:

    virtual void print(int x){
        cout<<x<<endl;
    }
};

class Child:public Parent{
    void print(long long x){
        cout<<x<<endl;
    }
};

int main()
{
    Parent* child=new Child();
    child->print(5);
    return 0;
}