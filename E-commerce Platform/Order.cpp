#include "Order.h"


// Constructor implementation

Order::Order(int orderId , int userId , const std::vector<CartItem>& items , double totalAmount )
      : orderId(orderId) , userId(userId) , items(items) , totalAmount(totalAmount) {}

// Getter for order ID
int Order::getOrderId() const {
    return orderId;
}

// Getter for user ID
int Order::getUserId() const {
    return userId;
}

// Getter for list of items
std::vector<CartItem> Order::getItems() const {
    return items;
}

// Getter for total amount
double Order::getTotalAmount() const {
    return totalAmount;
}