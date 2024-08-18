#include <iostream>
#include <string>
#include <vector>

class Item {
protected:
    std::string name;
    int stock;
    double price;

public:
    Item(const std::string& name, int stock, double price)
        : name(name), stock(stock), price(price) {}

    virtual ~Item() {}

    virtual void display() const {
        std::cout << "Name: " << name << ", Stock: " << stock << ", Price: " << price << std::endl;
    }

    int getStock() const {
        return stock;
    }

    void addStock(int amount) {
        stock += amount;
    }

    void removeStock(int amount) {
        if (amount <= stock) {
            stock -= amount;
        } else {
            std::cout << "Not enough stock available.\n";
        }
    }

    virtual void checkRestock() const {
        if (stock < 10) {
            std::cout << "Restock needed for item: " << name << std::endl;
        }
    }
};
