#include<iostream>
#include<vector>
using namespace std;

class Product{
    public:
    string name;
    double price;
    Product(string name,double price){
        this->name=name;
        this->price=price;
    }
};

class ShoppingCart{
    vector<Product*>products;
    public:

    void addProduct(Product* p){
        products.push_back(p);
    }

    vector<Product*>& getProducts(){
        return products;
    }

    double calculateTotal(){
        double total=0;
        for(auto p:products){
            total+=p->price;
        }
        return total;
    }

    void printInVoice(){
        cout<<"invoice: "<<endl;

        for(auto p:products){
            cout<<p->name<<" : Rs"<<p->price<<endl;
        }
        cout<<"Total :Rs"<<calculateTotal()<<endl;
    }

    void saveToDatabase(){
        cout<<"saved to database"<<endl;
    }
};
int main()
{
    ShoppingCart* cart =new ShoppingCart();
    
    cart->addProduct(new Product("mobile",300));
    cart->addProduct(new Product("Phone",400));
    
    cart->printInVoice();
    cart->saveToDatabase();
    return 0;
}