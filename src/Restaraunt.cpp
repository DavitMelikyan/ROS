#include "../headers/Headers.hpp"

Restaurant::Restaurant() = default;
    	
Restaurant::Restaurant(const Restaurant& other) : menu{other.menu}, orders{other.orders} {
    int sizeOther = other.customers.size();
    for (int i = 0; i < sizeOther; ++i) {
        customers.push_back(new Customer(*other.customers[i]));
    }
}
    	
Restaurant& Restaurant::operator=(const Restaurant& other) {
    if (this == &other) {
        return *this;
    }
    menu = other.menu;
    orders = other.orders;
    int sizeCur = customers.size();
    int sizeOther = other.customers.size();
    for (int i = 0; i < sizeCur; ++i) {
        delete customers[i];
    }
    customers.clear();
    for (int i = 0; i < sizeOther; ++i) {
        customers.push_back(new Customer(*other.customers[i]));
    }
    return *this;
}
    	
Restaurant::Restaurant(Restaurant&& other) noexcept : menu{std::move(other.menu)}, customers{std::move(other.customers)}, orders{std::move(other.orders)} { }
    	
Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    menu = std::move(other.menu);
    orders = std::move(other.orders);
    int sizeCur = customers.size();
    for (int i = 0; i < sizeCur; ++i) {
        delete customers[i];
    }
    customers.clear();
    orders = std::move(other.orders);
    return *this;
}
    	
Restaurant::~Restaurant() {
    int size = customers.size();
    for (int i = 0; i < size; ++i) {
        delete customers[i];
    }
}
    	
void Restaurant::showMenu() const {
    menu.displayMenu();
}
    	
Customer* Restaurant::getCustomerByName(const std::string& name) {
    int size = customers.size();
    for (int i = 0; i < size; ++i) {
        if (customers[i]->getName() == name) {
            return customers[i];
        }
    }
    std::cout << "Customer not found\n";
    return nullptr;
}
    	
void Restaurant::placeNewOrder(const std::string& customerName) {
    Customer* customer = getCustomerByName(customerName);
    if (!customer) {
        std::string contact;
        std::cout << "Please enter contact info: ";
        std::cin >> contact;
        customer = new Customer(customerName, contact);
        customers.push_back(customer);
    }
    Order order(customer);
    while (true) {
        std::string dishName;
        std::cout << "Enter dish name to add (q to exit): ";
        std::cin >> dishName;
        if (dishName == "q") {
            break;
        }
        Dish* dish = menu.getDishByName(dishName);
        if (dish) {
            order.addDish(dish);
        } else {
            std::cout << "Dish not found\n";
        }
    }
    order.calculateTotal();
    orders.push_back(order);
    customer->placeOrder(order);
}
    	
void Restaurant::viewCustomerOrderHistory(const std::string& customerName) const {
    int size = customers.size();
    for (int i = 0; i < size; ++i) {
        if (customers[i]->getName() == customerName) {
            customers[i]->viewOrderHistory();
            return;
        }
    }
    std::cout << "Customer not found\n";
}