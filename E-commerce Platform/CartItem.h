#ifndef CARTITEM_H
#define CARTITEM_H

#include "Product.h"

// Class representing an item in the shopping cart

class CartItem
{
    private:
    Product product; // The product in the cart
    int quantity; // Quantity of the product

    public:

        // Constructor to initialise a cart item
        CartItem(const Product& product, int quantity);

        // Getter for quantity
        int getQuantity() const;

        // Gather for product 
        Product getProduct() const;

        // setter for quantity
        void setQuantity(int quantity);

};

#endif // CARTITEM_H