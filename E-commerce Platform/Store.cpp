#include "Store.h"
#include <fstream>
#include <iostream>

// Add a product to the store
void Store::addProduct(const Product& product)
{
    products.push_back(product);
}

// Add a user to the store
void Store::addUser(const User& user)
{
    users.push_back(user);
}

// Add an Order to the store
void Store::addOrder(const Order& order)
{
    orders.push_back(order);
}

// Get Product by its IDs
Product Store::getProductById(int id) const
{
    for(const auto& product : products)
    {
        if(product.getId() == id)
        {
            return product;
        }
    }

    throw std::runtime_error("Product not Found");
}

// Get a User by thier username
User Store::getUserByUsername(const std::string& username) const
{
    for(const auto& user : users)
    {
        if(user.getUsername() == username)
        {
            return user;
        }
    }

    throw std::runtime_error("User Not found");
}

// Get Order By Id
Order Store::getOrderById(int id) const
{
    for(const auto& order : orders)
    {
        if(order.getOrderId() == id)
        {
            return order;
        }
    }

    throw std::runtime_error("Order not found");
}

// Load products from a file
void Store::loadProductsFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if(!file.is_open())
    {
        throw std::runtime_error("Failed to open file");
    }

    int id;
    std::string name;
    double price;
    std::string description;

    while (file >> id >> name >> price >> std::ws && std::getline(file , description))
    {
        products.push_back(Product(id , name , price , description));
    }

    file.close();

}

