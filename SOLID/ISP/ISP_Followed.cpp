#include<iostream>
using namespace std;

class TwoDShape{
    public:
    virtual void area()=0;
};

class ThreeDShape{
    public:
    virtual void area()=0;
    virtual void volume()=0;
};

class Square:public TwoDShape{
    int length;
    public:
    Square(int length){
        this->length=length;
    }
    void area() override{
        cout<<"area: "<<length*length<<endl;
    }
};

class Rectangle:public TwoDShape{
    int length,breadth;
    public:
    Rectangle(int length,int breadth){
        this->length=length;
        this->breadth=breadth;
    }
    void area() override{
        cout<<"area: "<<length*breadth<<endl;
    }
};

class Cube:public ThreeDShape{
    int side;
    public:
    Cube(int side){
        this->side=side;
    }
    void area() override{
        cout<<"area: "<<6*side*side<<endl;
    }
    void volume() override{
        cout<<"volume: "<<side* side*side<<endl;
    }
};

int main()
{
    TwoDShape* square=new Square(5);    
    return 0;
}