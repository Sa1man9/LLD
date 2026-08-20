#include<iostream>
using namespace std;

class Talkable{
    public:
    virtual void talk()=0;
};

class NormalTalk:public Talkable{
    public:
    void talk() override{
        cout<<"talking normally..."<<endl;
    }
};

class NoTalk:public Talkable{
    public:
    void talk() override{
        cout<<"not able to talk..."<<endl;
    }
};

class Walkable{
    public:
    virtual void walk()=0;
};

class NormalWalk:public Walkable{
    public:
    void walk() override{
        cout<<"walking normally..."<<endl;
    }
};

class NoWalk:public Walkable{
    public:
    void walk() override{
        cout<<"not able to walk..."<<endl;
    }
};

class Flyable{
    public:
    virtual void fly()=0;
};

class NormalFly:public Flyable{
    public:
    void fly() override{
        cout<<"flying normally..."<<endl;
    }
};

class NoFly:public Flyable{
    public:
    void fly() override{
        cout<<"not able to fly..."<<endl;
    }
};

class Robot{
    protected:
    Talkable* t;
    Walkable* w;
    Flyable* f;
    public:
    virtual void projection()=0;
    Robot(Talkable* t, Walkable* w, Flyable* f){
        this->f=f;
        this->w=w;
        this->t=t;
    }
    void walk(){
        w->walk();
    }
    void fly(){
        f->fly();
    }
    void talk(){
        t->talk();
    }
};

class CompanionRobot:public Robot{
    public:

    CompanionRobot(Talkable* t, Walkable* w, Flyable* f):Robot(t,w,f){}
    void projection() override{
        cout << "Displaying friendly companion features..." << endl;
    }
};

class WorkerRobot:public Robot{
    public:

    WorkerRobot(Talkable* t, Walkable* w, Flyable* f):Robot(t,w,f){}
    void projection() override{
        cout << "Displaying worker efficiency stats..." << endl;
    }
};
int main()
{
    Robot * robot=new CompanionRobot(new NormalTalk(),new NormalWalk(),new NormalFly());

    robot->projection();
    robot->talk();
    robot->walk();
    robot->fly();
    return 0;
}