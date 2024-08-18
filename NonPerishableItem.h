#include <string>
#include <ctime>
#include "Item.h"

class NonPerishableItem : public Item {
public:
    NonPerishableItem(const std::string& name, int stock, double price)
        : Item(name, stock, price) {}

    void checkRestock() const override {
        if (stock < 5) {
            std::cout << "Restock needed for non-perishable item: " << name << std::endl;
        }
    }
};
