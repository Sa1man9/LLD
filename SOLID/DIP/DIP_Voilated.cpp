#include<iostream>
using namespace std;

class MySqlDatabase{
    public:
    void save(){
        cout<<"saving to my sql database"<<endl;
    }
};

class MongoDBDatabase{
    public:
    void save(){
        cout<<"saving to mongodb"<<endl;
    }
};

class UserService{
    MySqlDatabase* mysql;
    MongoDBDatabase* mongo;
    public:

    UserService(){
        this->mysql=new MySqlDatabase();
        this->mongo=new MongoDBDatabase();
    }

    void savetosql(){
        mysql->save();
    }

    void savetomongo(){
        mongo->save();
    }
    
};

int main()
{
    UserService* service=new UserService();
    service->savetomongo();
    service->savetosql();
    return 0;
}