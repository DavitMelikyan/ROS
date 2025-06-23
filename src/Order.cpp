#include "../headers/Headers.hpp"
#include "./../headers/Order.hpp"
#include "./../headers/Customer.hpp"
#include "./../headers/Dish.hpp"

Order::Order(Customer* curCustomer) : customer{curCustomer},totalPrice{0.0} { }
    	
Order::Order(const Order& other) : customer{other.customer}, orderedDishes{other.orderedDishes}, totalPrice{other.totalPrice} { }
    	
Order& Order::operator=(const Order& other) {
    if (this == &other) {
        return *this;
    }
    customer = other.customer;
    orderedDishes = other.orderedDishes;
    totalPrice = other.totalPrice;
    return *this;
}
	
Order::Order(Order&& other) noexcept : customer{other.customer}, orderedDishes{std::move(other.orderedDishes)}, totalPrice{other.totalPrice} {
    other.customer = nullptr;
    other.totalPrice = 0.0;
}
    	
Order& Order::operator=(Order&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    customer = other.customer;
    orderedDishes = std::move(other.orderedDishes);
    totalPrice = other.totalPrice;
    other.customer = nullptr;
    other.totalPrice = 0.0;
    return *this;
}
    	
void Order::addDish(Dish* dish) {
    orderedDishes.push_back(dish);
}
    	
void Order::calculateTotal() {
    int size = orderedDishes.size();
    totalPrice = 0.0;
    for (int i = 0; i < size; ++i) {
        totalPrice += orderedDishes[i]->getPrice();
    }
}
    	
void Order::displayOrder() const {
    int size = orderedDishes.size();
    std::cout << "Customer Name: " << customer->getName() << std::endl;
    std::cout << "Ordered dishes\n";
    for (int i = 0; i < size; ++i) {
        orderedDishes[i]->display();
        std::cout << std::endl;
    }
    std::cout << "Total price: $" << totalPrice << std::endl;
}