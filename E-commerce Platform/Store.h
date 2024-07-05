#ifndef STORE_H
#define STORE_H

#include <vector>
#include <string>
#include "Product.h"
#include "User.h"
#include "Order.h"

// Class representing the store, managing products, users, and orders

class Store
{
    private:
        std::vector<Order> orders;  // List Of Orders

    public:
        std::vector<Product> products; // List of products in the store
        std::vector<User> users;  // List of registered users
        
        // Add a product to the store
        void addProduct(const Product& product);

        // Add a user to the store
        void addUser(const User& user);

        // Add an Order to the store
        void addOrder(const Order& order);

        // Get a product bu its ID
        Product getProductById(int id) const;

        // Get a user by their username
        User getUserByUsername(const std::string& username) const;

        // Get an order by its ID
        Order getOrderById(int id) const;

        // Load products from a file
        void loadProductsFromFile(const std::string& filename);

        // Save products to a file
        void saveProductsToFile(const std::string& filename) const;

        // Load users from a file
        void loadUsersFromFile(const std::string& filename);

        // Save users to a file
        void saveUsersToFile(const std::string& filename) const;

        // Load orders from a file
        void loadOrdersFromFile(const std::string& filename);

        // Save orders to a file
        void saveOrdersToFile(const std::string& filename) const;            

};

#endif