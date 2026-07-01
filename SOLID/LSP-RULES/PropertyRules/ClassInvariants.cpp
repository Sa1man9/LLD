#include<iostream>
using namespace std;

// Class Invariant of a parent class Object should not be broken by child class Object.
// Hence child class can either maintain or strengthen the invariant but never narrows it down.

//Invariant : Balance cannot be negative

class BankAccount{
    protected:
    double balance;
    public:
    BankAccount(double balance){
        if(balance<0) throw invalid_argument("negetive balance");
        this->balance=balance;
    }

    virtual void withdraw(double amount){
        if (balance - amount < 0) throw runtime_error("Insufficient funds");
        balance -= amount;
        cout<< "Amount withdrawn. Remaining balance is " << balance << endl;
    }

};

class CheatAccount:BankAccount{
    public:
    CheatAccount(double balance): BankAccount( balance){};
    virtual void withdraw(double amount) override{
        balance -= amount;//LSP BROKEN
        cout<< "Amount withdrawn. Remaining balance is " << balance << endl;
    }
};
int main()
{

    BankAccount* bankAccount = new BankAccount(100);
    bankAccount->withdraw(100);


    return 0;
}