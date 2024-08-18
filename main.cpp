#include "Inventory.h"
#include "Supplier.h"
#include "Item.h"
#include "NonPerishableItem.h"
#include "PerishableItem.h"
int main() {
    Inventory inventory;

    // Create suppliers
    Supplier supplier1("ABC Suppliers", "abc@example.com");
    Supplier supplier2("XYZ Wholesalers", "xyz@example.com");

    // Add suppliers to inventory
    inventory.addSupplier(supplier1);
    inventory.addSupplier(supplier2);

    // Create items
    Item* apple = new PerishableItem("Apple", 50, 0.5, std::time(0) + 60*60*24*7); // 1 week expiry
    Item* rice = new NonPerishableItem("Rice", 200, 1.0);

    // Add items to inventory
    inventory.addItem(apple);
    inventory.addItem(rice);

    // Create an order
    std::vector<Item*> orderItems = { apple, rice };
    inventory.createOrder(supplier1, orderItems);

    // Display inventory details
    std::cout << "Items in Inventory:\n";
    inventory.displayItems();

    std::cout << "\nSuppliers in Inventory:\n";
    inventory.displaySuppliers();

    std::cout << "\nOrders in Inventory:\n";
    inventory.displayOrders();

    return 0;
}
