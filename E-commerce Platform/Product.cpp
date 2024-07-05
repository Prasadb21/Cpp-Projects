#include "Product.h"

// constructror implementation

Product::Product(int id , const string& name , double price , const string& description)
        : id(id) , name(name) , price(price) , description(description) {}

// getter for product ID , name , price , description
int Product::getId() const
{
    return id;
}

string Product::getName() const
{
    return name;
}

double Product::getPrice() const
{
    return price;
}

string Product::getDescription() const
{
    return description;
}