#ifndef UTFS_H
#define UTFS_H
#include "../src/menu.h"
#include "../src/category.h"
#include "../src/full_menu.h"
#include "../src/product.h"
#include "../src/item.h"
#include "../src/ingredient.h"
#include <sys/stat.h>
#include <string>

class MenuSystemTest : public ::testing::Test{
  protected:
    // MenuSystemTest() {
    //   Ingredient meat("Meat", "delicious meat", 0.2, 0.13, 0.16, 0.24, false);
    //   Ingredient bread("Bread", "delicious bread", 0.2, 0.13, 0.16, 0.24, true);
    //   Ingredient tomato("Tomato", "delicious bread", 0.2, 0.13, 0.16, 0.24, true);
    //   Ingredient spaghetti("Spaghetti", "delicious bread", 0.2, 0.13, 0.16, 0.24, true);
    //   Ingredient onion("Onion", "delicious bread", 0.20, 0.13, 0.16, 0.24, true);
    //   Item hamburger("Hamburger", "delicious hamburger", 10);
    //   Item carbonara("Carbonara", "delicious carbonara", 10);
    //   Category dummy("dummy", "dummy category");
    //   FullMenu fullMenu("MENU", "good menu");
    // }
    //
    // virtual void SetUp(){
    //   hamburger.AddIngredient(&bread);
    //   hamburger.AddIngredient(&meat);
    //   hamburger.AddIngredient(&tomato);
    //   hamburger.AddIngredient(&onion);
    //
    //   carbonara.AddIngredient(&spaghetti);
    //   carbonara.AddIngredient(&onion);
    //   carbonara.AddIngredient(&tomato);
    //
    //   dummy.AddItem(&hamburger);
    //   dummy.AddItem(&carbonara);
    //
    //   fullMenu.AddCategory(&dummy);
    // }
};

TEST_F(MenuSystemTest, GetItemName) {
  // Ingredient meat("Meat", "delicious meat", 0.2, 0.13, 0.16, 0.24, false);
  // Ingredient bread("Bread", "delicious bread", 0.2, 0.13, 0.16, 0.24, true);
  // Ingredient tomato("Tomato", "delicious bread", 0.2, 0.13, 0.16, 0.24, true);
  // Ingredient spaghetti("Spaghetti", "delicious bread", 0.2, 0.13, 0.16, 0.24, true);
  // Ingredient onion("Onion", "delicious bread", 0.20, 0.13, 0.16, 0.24, true);
  // Item hamburger("Hamburger", "delicious hamburger", 10);
  // Item carbonara("Carbonara", "delicious carbonara", 10);
  // Category dummy("dummy", "dummy category");
  // FullMenu fullMenu("MENU", "good menu");
  // hamburger.AddIngredient(&bread);
  // hamburger.AddIngredient(&meat);
  // hamburger.AddIngredient(&tomato);
  // hamburger.AddIngredient(&onion);
  //
  // carbonara.AddIngredient(&spaghetti);
  // carbonara.AddIngredient(&onion);
  // carbonara.AddIngredient(&tomato);
  //
  // dummy.AddItem(&hamburger);
  // dummy.AddItem(&carbonara);
  //
  // fullMenu.AddCategory(&dummy);
  //ASSERT_EQ("Hamburger", hamburger.GetName());
}


#endif
