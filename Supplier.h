#include <string>
#include <iostream>
#include <ctime>
class Supplier {
private:
    std::string name;
    std::string contactInfo;

public:
    Supplier(const std::string& name, const std::string& contactInfo)
        : name(name), contactInfo(contactInfo) {}

    void display() const {
        std::cout << "Supplier Name: " << name << ", Contact: " << contactInfo << std::endl;
    }
};
