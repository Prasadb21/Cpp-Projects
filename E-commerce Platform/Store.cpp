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

// save products to a file
void Store::saveProductsToFile(const std::string& filename) const
{
    std::ofstream file(filename);
    if(!file.is_open())
    {
        throw std::runtime_error("Failed to open file");
    }

    for(const auto& product : products)
    {
        file << product.getId() << " " << product.getName() << " " << product.getPrice() << " " << product.getDescription() << "\n";
    }

    file.close();

}

// load users from a file

void Store::loadUsersFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if(!file.is_open())
    {
        throw std::runtime_error("Failed to open file");
    }

    int userId;
    std::string username;
    std::string passwordHash;

    while (file >> userId >> username >> passwordHash) {
        users.push_back(User(userId, username, passwordHash));
    }

    file.close();

}

// Save users to a file
void Store::saveUsersToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }

    for (const auto& user : users) {
        file << user.getUserId() << " " << user.getUsername() << " " << user.getPasswordHash() << "\n";
    }

    file.close();
}

// Load orders from a file

void Store::loadOrdersFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }

    int orderId, userId, productId, quantity;
    double totalAmount;
    std::vector<CartItem> items;

    while(file >> orderId >> userId >> totalAmount)
    {
        items.clear();
        while(file >> productId >> quantity)
        {
            Product product = getProductById(productId);
            items.push_back(CartItem(product , quantity));
        }

        orders.push_back(Order(orderId, userId, items, totalAmount));

    }

    file.close();
}

// Save orders to a file
void Store::saveOrdersToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }

    for (const auto& order : orders) {
        file << order.getOrderId() << " " << order.getUserId() << " " << order.getTotalAmount() << "\n";
        for (const auto& item : order.getItems()) {
            file << item.getProduct().getId() << " " << item.getQuantity() << "\n";
        }
    }

    file.close();
}




