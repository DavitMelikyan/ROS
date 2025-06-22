#include "../headers/Headers.hpp"

Menu::Menu(const Menu& other) {
    int size = other.dishes.size();
    for (int i = 0; i < size; ++i) {
        dishes[i] =  new Dish(*other.dishes[i]);
    }
}
    	
Menu& Menu::operator=(const Menu& other) {
    if(this == &other) {
		return *this;
	}
	int sizeCur = dishes.size();
	int sizeOther  = other.dishes.size();
	for(int i = 0; i < sizeCur; ++i) {
		delete dishes[i];
	}
	dishes.clear();
	for(int i = 0; i < sizeOther; ++i) {
		dishes.emplace_back(new Dish(*other.dishes[i]));
	}
	return *this;
}
    	
Menu::Menu(Menu&& other) noexcept {
    dishes = std::move(other.dishes);
}
    	
Menu& Menu::operator=(Menu&& other) noexcept {
    if(this == &other) {
		return *this;
	}
    int sizeCur = dishes.size();
	int sizeOther  = other.dishes.size();
	for(int i = 0; i < sizeCur; ++i) {
		delete dishes[i];
	}
	dishes.clear();
	dishes = std::move(other.dishes);
	return *this;
}
    	
Menu::~Menu() {
    int size = dishes.size();
    for(int i = 0; i < size; ++i) {
		delete dishes[i];
	}
}
    	
void Menu::addDish(Dish* dish) {
    dishes.push_back(dish);
}
    	
void Menu::displayMenu() const {
    int size = dishes.size();
    for (int i = 0; i < size; ++i) {
        dishes[i]->display();
    }
}
    	
Dish* Menu::getDishByName(const std::string& dishName) const {
    int size = dishes.size();
    for (int i = 0; i < size; ++i) {
        if (dishes[i]->getName() == dishName) {
            return dishes[i];
        }
    }
    std::cout << "Dish not found";
    return nullptr;
}
