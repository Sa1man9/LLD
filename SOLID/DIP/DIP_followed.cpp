#include<iostream>
using namespace std;

class Database{
    public:
    virtual void save()=0;
};

class MySqlDatabase:public Database{
    public:
    void save() override{
        cout<<"saving to my sql database"<<endl;
    }
};

class MongoDBDatabase: public Database{
    public:
    void save() override{
        cout<<"saving to mongodb"<<endl;
    }
};

class UserService{
    Database* db;
    public:

    UserService(Database* db){
        this->db=db;
    }

    void save(){
        db->save();
    }
    
};


int main()
{
    MySqlDatabase* mysql=new MySqlDatabase();
    MongoDBDatabase* mongo=new MongoDBDatabase();

    UserService* service1= new UserService(mysql);
    service1->save();

    UserService* service2=new UserService(mongo);
    service2->save();

    return 0;
}