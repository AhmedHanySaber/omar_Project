#include <string>
#include <vector>
#include <ctime>
#include "Item.h"
#include "Supplier.h"
class Order {
private:
    Supplier supplier;
    std::vector<Item*> items;

public:
    Order(const Supplier& supplier) : supplier(supplier) {}

    void addItem(Item* item) {
        items.push_back(item);
    }

    void display() const {
        std::cout << "Order from: ";
        supplier.display();
        std::cout << "Items in order:\n";
        for (const auto& item : items) {
            item->display();
        }
    }
};
