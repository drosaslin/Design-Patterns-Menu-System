#ifndef UT_MENUITERATOR_H
#define UT_MENUITERATOR_H
#include "../src/base_menu.h"
#include "../src/menu.h"
#include "../src/menu_item.h"
#include "../src/iterator.h"

class MenuIteratorTest : public ::testing::Test{

  protected:
    BaseMenu* hamburger;
    BaseMenu* pizza;
    BaseMenu* spaguetti;
    BaseMenu* gyro;
    BaseMenu* salad;
    BaseMenu* lunchMenu;
    BaseMenu* dinnerMenu;

    virtual void SetUp(){
      hamburger = new MenuItem("Hamburger", 5.00, false);
      pizza = new MenuItem("Pizza", 4.50, false);
      spaguetti = new MenuItem("Spaguetti", 8.75, false);
      gyro = new MenuItem("Gyro", 5.00, false);
      salad = new MenuItem("Salad", 150, true);
      lunchMenu = new Menu("Lunch Menu");
      dinnerMenu = new Menu("Dinner Menu");

      hamburger->addIngredient("Cheese");
      hamburger->addIngredient("Bread");
      salad->addIngredient("Lettuce");
      salad->addIngredient("Tomato");
      salad->addIngredient("Vinegar");
    }
};

TEST_F(MenuIteratorTest, GetName) {
  ASSERT_EQ("Lunch Menu", lunchMenu->getName());
}

#endif
