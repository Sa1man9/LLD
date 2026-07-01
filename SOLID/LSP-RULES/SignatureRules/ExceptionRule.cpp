// Exception Rule:
// A subclass should throw fewer or narrower exceptions 
// (but not additional or broader exceptions) than the parent.
// C++ does not enforces this. Hence no compilation error.

/*
├── std::logic_error        <-- For logical errors detected before runtime
│   ├── std::invalid_argument   <-- Invalid function argument
│   ├── std::domain_error       <-- Function argument domain error
│   ├── std::length_error       <-- Exceeding valid length limits
│   ├── std::out_of_range       <-- Array or container index out of bounds
│
├── std::runtime_error      <-- For errors that occur at runtime
│   ├── std::range_error        <-- Numeric result out of range
│   ├── std::overflow_error     <-- Arithmetic overflow
│   ├── std::underflow_error   
*/

#include<iostream>
using namespace std;

class Parent{
    public:

    virtual void getValue() noexcept(false){
        throw logic_error("Parent error");
    }

};

class Child:public Parent{
    public:

    void getValue() noexcept(false) override{
        throw range_error("child error");
    }
};

class Client{
    public:
    void takeValue(Parent* p){
        try
        {
            p->getValue();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
};

int main()
{
    Parent* child=new Child();
    Client* client= new Client();
    client->takeValue(child);
    return 0;
}