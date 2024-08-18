#include <string>
#include <vector>
#include <ctime>
#include "Item.h"
#include "Supplier.h"
#include "Order.h"
class Inventory {
private:
    std::vector<Item*> items;
    std::vector<Supplier> suppliers;
    std::vector<Order> orders;

public:
    ~Inventory() {
        for (auto item : items) {
            delete item;
        }
    }

    void addItem(Item* item) {
        items.push_back(item);
    }

    void addSupplier(const Supplier& supplier) {
        suppliers.push_back(supplier);
    }

    void createOrder(const Supplier& supplier, std::vector<Item*> orderItems) {
        Order order(supplier);
        for (auto item : orderItems) {
            order.addItem(item);
            item->addStock(100); // example restock quantity
        }
        orders.push_back(order);
    }

    void displayItems() const {
        for (const auto& item : items) {
            item->display();
        }
    }

    void displaySuppliers() const {
        for (const auto& supplier : suppliers) {
            supplier.display();
        }
    }

    void displayOrders() const {
        for (const auto& order : orders) {
            order.display();
        }
    }
};
