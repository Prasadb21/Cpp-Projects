

class Inventory
{
    private:
        vector<Product> products; // Vectors to store the products

    public:

        // Method to add a new Product to the inventory
        void addProduct(const Product &product)
        {
            products.push_back(product);
        }

        // Method to update an existing product's details
        void updateProduct(int id , const string &name, int quantity , double price)
        {
            for(auto &product : products)
            {
                if(product.getId() == id)
                {
                    product.setName(name); // update name
                    product.setPrice(price); // update price
                    product.setQuantity(quantity); // update quantity
                    return;
                }
            }
            cout<<"Product not Found!! " << endl; // product not found error displayed
        }

        // Method to delete a product from the inventory
        void deleteProduct(int id) {
            // Use std::remove_if to find and remove the product with the given id
            // std::remove_if shifts elements that do not match the condition to the front of the container
            // and returns an iterator to the new end of the range of remaining elements
            auto it = remove_if(products.begin(), products.end(),
                                    [id](const Product &product) { return product.getId() == id; });
            
            // Erase the elements from the vector that have been moved to the end of the range
            // This effectively removes the elements that match the condition
            if (it != products.end()) {
                products.erase(it, products.end());
            } else {
                cout << "Product not found!" << endl;  // Print message if product not found
            }
        }

        // method to display all products from inventory
        void displayProducts() const
        {
            for(const auto &product : products)
            {
                product.display(); // display each product
            }
        }

        // method to save the inventory to a file

        void saveFile(const string &filename) const
        {
            ofstream file(filename); // open file for writing 
            if(!file)
            {
                cerr<<"Error opening file for writing!" << endl;
                return;
            }

            // write each product's details to the file
            for(const auto &product : products)
            {
                file << product.getId() << ' ' << product.getName() << ' ' << product.getQuantity() << ' ' << product.getPrice() << '\n';
            }
            file.close(); // close the file

        }

        // method to load the inventory from file
        void loadFromFile(const string &filename)
        {

            ifstream file(filename);  // openfile for reading
            if(!file)
            {
                cerr<<"Error opening file for writing!" << endl;
                return;
            }
            products.clear();  // Clear current inventory
            int id , quantity;
            string name;
            double price;

            // Read each product's details from the file
            while(file >> id >> name >> quantity >> price)
            {
                products.emplace_back(id , name , quantity , price);
            }

            file.close();

        }

        // Method to generate a report of the inventory 
        void generateReport() const
        {
            cout<<"\nInventory Report:" << endl;
            double totalValue = 0; // variable to store total values

            for(const auto &product : products)
            {
                product.display();
                totalValue += product.getQuantity() * product.getPrice();  // calculate the total price
            }

            cout << "Total Inventory Value: $" << totalValue << std::endl;

        }    

};