#include "library.h"
class Product {
public:
    string name;
    int quantity;
    double price;
    Product(string name, int quantity, double price) {
        this->name = name;
        this->quantity = quantity;
        this->price = price;
    }
    double getTotalPrice() {
        return price * quantity;
    }
};
class Customer {
public:
    string name;
    string address;
    string phone;
    Customer(string name, string address, string phone) {
        this->name = name;
        this->address = address;
        this->phone = phone;
    }
};
class Sale {
public:
    Customer customer;
    Product* products;
    int numProducts;
    double total;
    Sale(Customer customer, Product* products, int numProducts) {
        this->customer = customer;
        this->products = products;
        this->numProducts = numProducts;
        total = 0;
        for (int i = 0; i < numProducts; i++) {
            total += products[i].getTotalPrice();
        }
    }
};
class Return {
public:
    Customer customer;
    Product* products;
    int numProducts;
    double total;
    Return(Customer customer, Product* products, int numProducts) {
        this->customer = customer;
        this->products = products;
        this->numProducts = numProducts;
        total = 0;
        for (int i = 0; i < numProducts; i++) {
            total += products[i].getTotalPrice();
        }
    }
};
int main() {
    Product laptop("Laptop", 2, 1000);
    Product phone("Phone", 1, 500);
    Customer customer("Maxim Maximchyk", "123 Main St", "555-555-5555");
    Product saleProducts[] = { laptop, phone };
    Sale sale(customer, saleProducts, 2);
    cout << "Sale" << endl;
    cout << "Customer: " << sale.customer.name << endl;
    cout << "Address: " << sale.customer.address << endl;
    cout << "Phone: " << sale.customer.phone << endl;
    for (int i = 0; i < sale.numProducts; i++) {
        cout << sale.products[i].name << " (" << sale.products[i].quantity << "): $" << sale.products[i].getTotalPrice() << endl;
    }
    cout << "Total: $" << sale.total;
    Product returnProducts[] = {laptop};
    Return returnObj(customer, returnProducts, 1);
    cout << endl << "Return" << endl;
    cout << "Customer: " << returnObj.customer.name << endl;
    cout << "Address: " << returnObj.customer.address << endl;
    cout << "Phone: " << returnObj.customer.phone << endl;
    for (int i = 0; i < returnObj.numProducts; i++) {
        cout << returnObj.products[i].name << " (" << returnObj.products[i].quantity << "): $" << returnObj.products[i].getTotalPrice() << endl;
    }
    cout << "Total: $" << returnObj.total << endl;
    return 0;
}









