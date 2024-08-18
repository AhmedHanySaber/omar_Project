#include <iostream>
#include <string>
#include <ctime>
#include "Item.h"
class PerishableItem : public Item {
private:
    std::time_t expiryDate;

public:
    PerishableItem(const std::string& name, int stock, double price, std::time_t expiryDate)
        : Item(name, stock, price), expiryDate(expiryDate) {}

    void display() const override {
        Item::display();
        std::cout << "Expiry Date: " << std::ctime(&expiryDate);
    }

    void checkRestock() const override {
        if (stock < 10) {
            std::cout << "Restock needed for perishable item: " << name << std::endl;
        }
    }
};
