#ifndef UTFS_H
#define UTFS_H
#include "../src/base_menu.h"
#include "../src/menu_item.h"
#include <sys/stat.h>
#include <string>

TEST(MenuSystem, GetItemName) {
  MenuItem hamburger("Hamburger");
  ASSERT_EQ("Hamburger", hamburger.getName());
}

TEST(MenuSystem, AddIngredients) {
  MenuItem hamburger("Hamburger");
  hamburger.addIngredient("Cheese");
  ASSERT_TRUE(hamburger.hasIngredient("Cheese"));
}

TEST(MenuSystem, RemoveIngredients) {
  MenuItem hamburger("Hamburger");
  hamburger.addIngredient("Cheese");
  hamburger.addIngredient("Bread");
  hamburger.removeIngredient("Bread");
  ASSERT_FALSE(hamburger.hasIngredient("Bread"));
}

TEST(MenuSystem, GetItemIngredients){
  MenuItem salad("Salad", 150, "Delicious salad", true);
  salad.addIngredient("Lettuce");
  salad.addIngredient("Tomato");
  salad.addIngredient("Vinegar");
  ASSERT_EQ("Lettuce, Tomato, Vinegar", salad.getIngredients());
  ASSERT_EQ(150, salad.getPrice());
  ASSERT_TRUE(salad.isVegetarian());
}

#endif
