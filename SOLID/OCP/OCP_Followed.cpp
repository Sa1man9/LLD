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

class Persistance{
    public:
    virtual void save(ShoppingCart* cart)=0;
};

class SQLPersistance: public Persistance{
    public:
    void save(  ShoppingCart* cart){
        cout<<"saving to SQL database"<<endl;
    }
};

class MongoDBPersistance:public Persistance{
    public:
    void save(ShoppingCart* cart){
          cout<<"saving to mongodb"<<endl;
    }
};

class FilePersistance:public Persistance{
    public:
    void save(ShoppingCart* cart){
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

    Persistance * sqlDB=new SQLPersistance();
    sqlDB->save(cart);

    Persistance * file=new FilePersistance();
    file->save(cart);

    return 0;
}