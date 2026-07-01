
#include<iostream>
using namespace std;

class User{
    public:
    virtual void setPassword(string password){
        if(password.length()<8){
            throw runtime_error("password is short");
        }
    }
};

class AdminUser:User{
    virtual void setPassword(string password) override{
        if(password.length()<6){
            throw runtime_error("password is short");
        }
    }
};
int main()
{
    return 0;
}