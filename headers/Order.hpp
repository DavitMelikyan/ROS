#ifndef ORDER_HPP
#define ORDER_HPP
#include "Headers.hpp"
class Customer;
class Dish;


class Order {
private:
    	Customer* customer;
    	std::vector<Dish*> orderedDishes;
    	double totalPrice;
public:
    	Order(Customer* customer);
    	Order(const Order& other);
    	Order& operator=(const Order& other);
	Order(Order&& other) noexcept;
    	Order& operator=(Order&& other) noexcept;
    	~Order() = default;
    	void addDish(Dish* dish);
		double getTotal() const;
    	void calculateTotal();
    	void displayOrder() const;
};

#endif