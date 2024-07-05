#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include<string>

using namespace std;


class Product
{
    private:
        int id; // Product ID
        string name; // Product Name
        double price; // Product Price
        string description; // Products description

    public:
        // Constructor to initialize a product
        Product(int id, const string& name , double price , const string& description);

        // Getter for Product ID, Name, price, product description
        int getId() const;
        string getName() const;
        double getPrice() const;
        string getDescription() const;

};

#endif // PRODUCT_H