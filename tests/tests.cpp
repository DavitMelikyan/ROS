#include "../headers/Headers.hpp"
#include <gtest/gtest.h>

TEST(DishesTest, DishTest) {
    Dish d("Pasta", 12.5);
    EXPECT_EQ(d.getName(), "Pasta");
    EXPECT_DOUBLE_EQ(d.getPrice(), 12.5);
}

TEST(DishesTest, AppetizerTest) {
    Appetizer a("Wings", 8.0, true);
    EXPECT_EQ(a.getName(), "Wings");
    EXPECT_DOUBLE_EQ(a.getPrice(), 8.0);
}

TEST(DishesTest, EntreeTest) {
    Entree e("Steak", 20.0, 700);
    EXPECT_EQ(e.getName(), "Steak");
    EXPECT_DOUBLE_EQ(e.getPrice(), 20.0);
}

TEST(DishesTest, DessertTest) {
    Dessert d("Cake", 6.5, true);
    EXPECT_EQ(d.getName(), "Cake");
    EXPECT_DOUBLE_EQ(d.getPrice(), 6.5);
}

TEST(MenuTest, AddDish) {
    Menu menu;
    Dish* d = new Dish("Soup", 5.0);
    menu.addDish(d);

    Dish* newDish = menu.getDishByName("Soup");
    ASSERT_NE(newDish, nullptr);
    EXPECT_EQ(newDish->getName(), "Soup");
    EXPECT_DOUBLE_EQ(newDish->getPrice(), 5.0);
}

TEST(OrderTest, TotalCalc) {
    Customer c("Anna", "anna@gmail.com");
    Order o(&c);

    Dish* d1 = new Dish("Salad", 5.0);
    Dish* d2 = new Dish("Pizza", 15.0);

    o.addDish(d1);
    o.addDish(d2);
    o.calculateTotal();

    EXPECT_EQ(o.getTotal(), 20);
}

