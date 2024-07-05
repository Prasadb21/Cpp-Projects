

class Product
{
    private:
        int id;
        string name;
        int quantity;
        double price;
    
    public:
        Product(int id , const std::string &name , int quantity , double price)
            : id(id) , name(name), quantity(quantity) , price(price) {}
        
        // Getter methods to access private members
        int getId() const 
        { 
            return id; 
        }
        std::string getName() const 
        {
            return name;
        }
        int getQuantity() const 
        {
            return quantity;
        }
        double getPrice() const 
        {
            return price;
        }

        // setter methods to modify private members

        void setName(const std::string &name)
        {
            this->name = name;
        }
        void setQuantity(int quantity)
        {
            this->quantity = quantity;
        }
        void setPrice(double price)
        {
            this->price = price;
        }

        // Display method to show the product details
        void display() const
        {
            std::cout << "ID : " << id << ", Name : " << name << ", Quantity : " << quantity << ", Price : $" << price << std::endl;
        }


};

