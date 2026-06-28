#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;

class Account{
    public:
    virtual void deposit(double amount)=0;
    virtual void withdraw(double amount)=0;
};

class SavingsAccount: public Account{
    double balance;

    public:
    SavingsAccount(double balance=0){
        this->balance=balance;
    }

    void deposit(double amount){
        balance+=amount;
        cout<<"deposited: "<<amount<<endl;
    }

    void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"withdrawed: "<<amount<<endl;
        }else{
            cout<<"insufficient amount: "<<amount<<endl;
        }
    }
};
class CurrentAccount: public Account{
    double balance;

    public:
    CurrentAccount(double balance=0){
        this->balance=balance;
    }

    void deposit(double amount){
        balance+=amount;
        cout<<"deposited: "<<amount<<endl;
    }

    void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"withdrawed: "<<amount<<endl;
        }else{
            cout<<"insufficient amount: "<<amount<<endl;
        }
    }
};
class FixedAccount: public Account{
    double balance;

    public:
    FixedAccount(double balance=0){
        this->balance=balance;
    }

    void deposit(double amount){
        balance+=amount;
        cout<<"deposited: "<<amount<<endl;
    }

    void withdraw(double amount){
        throw logic_error("withdrawal not allowed in fixed account");
    }
};

class BankClient{
    vector<Account*> accounts;
    public:
    BankClient(vector<Account*>accounts){
        this->accounts=accounts;
    }

    void process(){
        for(auto a:accounts){
            a->deposit(1000);
            if(typeid(*a)==typeid(FixedAccount)){
                continue;
            }
            else{
                try{
                    a->withdraw(500);
                }catch(const logic_error&e){
                    cout<<e.what()<<endl;
                }
            }

        }
    }
};

int main()
{
    vector<Account*>accounts;
    accounts.push_back(new SavingsAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedAccount());

    BankClient* client=new BankClient(accounts);
    client->process();
    return 0;
}