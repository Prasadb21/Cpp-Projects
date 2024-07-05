#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

#include "productClass.h"
#include "inventoryClass.h"

// Function to display the menu
void displayMenu() {
    std::cout << "\nInventory Management System Menu:" << std::endl;
    std::cout << "1. Add Product" << std::endl;
    std::cout << "2. Update Product" << std::endl;
    std::cout << "3. Delete Product" << std::endl;
    std::cout << "4. Display Products" << std::endl;
    std::cout << "5. Generate Report" << std::endl;
    std::cout << "6. Save Inventory to File" << std::endl;
    std::cout << "7. Load Inventory from File" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

// Main function to interact with the inventory system
int main() {
    Inventory inventory;
    int choice;

    // Load inventory from file at the start
    inventory.loadFromFile("inventory.txt");

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id, quantity;
                std::string name;
                double price;

                std::cout << "Enter Product ID: ";
                std::cin >> id;
                std::cin.ignore();  // Clear newline left in buffer
                std::cout << "Enter Product Name: ";
                std::getline(std::cin, name);  // Use getline to read entire line
                std::cout << "Enter Product Quantity: ";
                std::cin >> quantity;
                std::cout << "Enter Product Price: ";
                std::cin >> price;

                inventory.addProduct(Product(id, name, quantity, price));
                break;
            }
            case 2: {
                int id, quantity;
                std::string name;
                double price;

                std::cout << "Enter Product ID to update: ";
                std::cin >> id;
                std::cin.ignore();  // Clear newline left in buffer
                std::cout << "Enter new Product Name: ";
                std::getline(std::cin, name);  // Use getline to read entire line
                std::cout << "Enter new Product Quantity: ";
                std::cin >> quantity;
                std::cout << "Enter new Product Price: ";
                std::cin >> price;

                inventory.updateProduct(id, name, quantity, price);
                break;
            }
            case 3: {
                int id;

                std::cout << "Enter Product ID to delete: ";
                std::cin >> id;

                inventory.deleteProduct(id);
                break;
            }
            case 4:
                inventory.displayProducts();
                break;
            case 5:
                inventory.generateReport();
                break;
            case 6:
                inventory.saveFile("inventory.txt");
                break;
            case 7:
                inventory.loadFromFile("inventory.txt");
                break;
            case 8:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 8);

    return 0;
}