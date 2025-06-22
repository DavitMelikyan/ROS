#include "../headers/Headers.hpp"

// Appetizer

Appetizer::Appetizer(std::string dishName, double dishPrice, bool spicy) : Dish{dishName, dishPrice}, isSpicy{spicy} { }
    	
void Appetizer::display() const {
    Dish::display();
    std::cout << "Is Spicy: " << (isSpicy ? "Yes" : "No") << std::endl;
}

// Entree

Entree::Entree(std::string dishName, double dishPrice, int cal) : Dish{dishName, dishPrice}, calories{cal} { }
    	
void Entree::display() const {
    Dish::display();
    std::cout << "Calories: " << calories << std::endl;
}

// Dessert

Dessert::Dessert(std::string dishName, double dishPrice, bool nuts) :  Dish{dishName, dishPrice}, containsNuts{nuts} { }
    	
void Dessert::display() const {
    Dish::display();
    std::cout << "Contains Nuts: " << (containsNuts ? "Yes" : "No") << std::endl;
}