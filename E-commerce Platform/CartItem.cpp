#include "CartItem.h"

// Constructor implementation
CartItem::CartItem(const Product& product, int quantity)
    : product(product), quantity(quantity) {}

// Getter for product

Product CartItem::getProduct() const
{
    return product;
}

// Getter for quantity

int CartItem::getQuantity() const
{
    return quantity;
}

// setter for quantity
void CartItem::setQuantity(int quantity)
{
    this->quantity = quantity;
}



