#include <iostream>

#include "Store.h"

// Function to display the menu options
void displayMenu() {
    std::cout << "1. List Products\n";
    std::cout << "2. Register\n";
    std::cout << "3. Login\n";
    std::cout << "4. Add to Cart\n";
    std::cout << "5. View Cart\n";
    std::cout << "6. Place Order\n";
    std::cout << "7. Exit\n";
}

int main()
{
    Store store; // create a store objects

    // Load Data From Files
    try 
    {
        store.loadProductsFromFile("products.txt");
        store.loadUsersFromFile("users.txt");
        store.loadOrdersFromFile("orders.txt");
    } 
    catch (const std::runtime_error& e) {
        std::cerr << "Error loading data: " << e.what() << std::endl;
    }

int choice;
    while (true) {
        displayMenu(); // Display menu options
        std::cin >> choice;

        switch (choice) {
            case 1:
                // List products
                std::cout << "Listing Products:\n";
                try {
                    for (const auto& product : store.products) {
                        std::cout << product.getId() << " " << product.getName() << " $" << product.getPrice() << " " << product.getDescription() << "\n";
                    }
                } catch (const std::runtime_error& e) {
                    std::cerr << "Error listing products: " << e.what() << std::endl;
                }
                break;
            case 2: {
                // Register
                std::string username, password;
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                int userId = store.users.size() + 1;
                store.addUser(User(userId, username, User::hashPassword(password)));
                std::cout << "User registered successfully!\n";
                break;
            }
            case 3: {
                // Login
                std::string username, password;
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                try {
                    User user = store.getUserByUsername(username);
                    if (user.getPasswordHash() == User::hashPassword(password)) {
                        std::cout << "Login successful!\n";
                    } else {
                        std::cout << "Invalid credentials!\n";
                    }
                } catch (const std::runtime_error& e) {
                    std::cerr << "Login error: " << e.what() << std::endl;
                }
                break;
            }
            case 4:
                // Add to cart (Placeholder)
                std::cout << "Add to Cart functionality not implemented yet.\n";
                break;
            case 5:
                // View cart (Placeholder)
                std::cout << "View Cart functionality not implemented yet.\n";
                break;
            case 6:
                // Place order (Placeholder)
                std::cout << "Place Order functionality not implemented yet.\n";
                break;
            case 7:
                // Exit the program
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}


