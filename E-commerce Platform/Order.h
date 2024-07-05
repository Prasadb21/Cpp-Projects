#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "CartItem.h"

// Class representing an order placed by a user
class Order {
private:
    int orderId; // Order ID
    int userId; // ID of the user who placed the order
    std::vector<CartItem> items; // List of items in the order
    double totalAmount; // Total amount of the order

public:
    // Constructor to initialize an order
    Order(int orderId, int userId, const std::vector<CartItem>& items, double totalAmount);

    // Getter for order ID
    int getOrderId() const;

    // Getter for user ID
    int getUserId() const;

    // Getter for list of items
    std::vector<CartItem> getItems() const;

    // Getter for total amount
    double getTotalAmount() const;
    
};

#endif // ORDER_H
