#include<iostream>
#include<vector>
using namespace std;

class DepositOnlyAccount{
    public:
    virtual void deposit(double amount)=0;
};

class WithdrawableAccount: public DepositOnlyAccount{
    public:
    virtual void withdraw(double amount)=0;
};

class SavingsAccount: public WithdrawableAccount{
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
class CurrentAccount: public WithdrawableAccount{
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
class FixedAccount: public DepositOnlyAccount{
    double balance;

    public:
    FixedAccount(double balance=0){
        this->balance=balance;
    }

    void deposit(double amount){
        balance+=amount;
        cout<<"deposited: "<<amount<<endl;
    }

};

class BankClient{
    vector<DepositOnlyAccount*> depositOnlyAccounts;
    vector<WithdrawableAccount*> withdrawableAccounts;
    public:
    BankClient(vector<DepositOnlyAccount*>depositOnlyAccounts,vector<WithdrawableAccount*> withdrawableAccounts){
        this->depositOnlyAccounts=depositOnlyAccounts;
        this->withdrawableAccounts=withdrawableAccounts;
    }

    void process(){
        for(auto a:withdrawableAccounts){
            a->deposit(1000);
            a->withdraw(500);
        }
        for (auto a:depositOnlyAccounts){
            a->deposit(100);
        }
    }
};

int main()
{
    vector<WithdrawableAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingsAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedAccount());

    BankClient* client = new BankClient(depositOnlyAccounts,withdrawableAccounts);
    client->process();
    return 0;
}