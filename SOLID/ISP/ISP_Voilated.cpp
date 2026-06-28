#include<iostream>
using namespace std;

class Shape{
    public:
    virtual void area()=0;
    virtual void volume()=0;
};

class Square:public Shape{
    int length;
    public:
    Square(int length){
        this->length=length;
    }
    void area() override{
        cout<<"area: "<<length*length<<endl;
    }
    void volume() override{
        logic_error("square dont have volume");
    }
};

class Rectangle:public Shape{
    int length,breadth;
    public:
    Rectangle(int length,int breadth){
        this->length=length;
        this->breadth=breadth;
    }
    void area() override{
        cout<<"area: "<<length*breadth<<endl;
    }
    void volume() override{
        logic_error("Rectangle dont have volume");
    }
};

class Cube:public Shape{
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
    Shape* square=new Square(5);
    try
    {
        square->volume();
    }
    catch(logic_error & e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}