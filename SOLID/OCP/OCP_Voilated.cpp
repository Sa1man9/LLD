#include<iostream>
#include<vector>
using namespace std;

class Product{
    public:
    string name;
    double price;

    Product(string name, double price){
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

};

class ShoppingCartPrinter{
    ShoppingCart* cart;
    public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart=cart;
    }
    void printInvoice(){
        cout<<"Invoice:"<<endl;
        for(auto p:cart->getProducts()){
            cout<<p->name<<" : Rs"<<p->price<<endl;
        }
        cout<<"Total :Rs"<<cart->calculateTotal()<<endl;
    }
};

class ShoppingCartStorage{
    ShoppingCart* cart;
    public:
    ShoppingCartStorage(ShoppingCart* cart){
        this->cart=cart;
    }
    void saveToSQLDB(){
        cout<<"saving to SQL database"<<endl;
    }

    void saveToMongodb(){
        cout<<"saving to mongodb"<<endl;
    }

    void saveToFile(){
        cout<<"saving to file"<<endl;
    }
};

int main()
{
    ShoppingCart* cart=new ShoppingCart();
    cart->addProduct(new Product("mobile",300));
    cart->addProduct(new Product("Phone",400));

    ShoppingCartPrinter* printer=new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* storage=new ShoppingCartStorage(cart);
    storage->saveToSQLDB();
    storage->saveToFile();
    storage->saveToMongodb();

    return 0;
}