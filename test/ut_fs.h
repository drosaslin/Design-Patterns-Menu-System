#ifndef UTFS_H
#define UTFS_H
#include "../src/base_menu.h"
#include "../src/menu_item.h"
#include <sys/stat.h>
#include <string>

class MenuSystemTest : public ::testing::Test{
  protected:
    BaseMenu* hamburger;
    BaseMenu* pizza;
    BaseMenu* spaguetti;
    BaseMenu* gyro;
    BaseMenu* salad;

    virtual void SetUp(){
      hamburger = new MenuItem("Hamburger", 5.00, false);
      pizza = new MenuItem("Pizza", 4.50, false);
      spaguetti = new MenuItem("Spaguetti", 8.75, false);
      gyro = new MenuItem("Gyro", 5.00, false);
      salad = new MenuItem("Salad", 150, true);

      hamburger->addIngredient("Cheese");
      hamburger->addIngredient("Bread");
      salad->addIngredient("Lettuce");
      salad->addIngredient("Tomato");
      salad->addIngredient("Vinegar");
    }
};

TEST_F(MenuSystemTest, GetItemName) {
  ASSERT_EQ("Hamburger", hamburger->getName());
}

TEST_F(MenuSystemTest, HasIngredients) {
  ASSERT_TRUE(hamburger->hasIngredient("Cheese"));
}

TEST_F(MenuSystemTest, RemoveIngredients) {
  hamburger->removeIngredient("Bread");
  ASSERT_FALSE(hamburger->hasIngredient("Bread"));
}

TEST_F(MenuSystemTest, GetItemIngredients){
  ASSERT_EQ("Lettuce, Tomato, Vinegar", salad->getIngredients());
  ASSERT_EQ(150, salad->getPrice());
  ASSERT_TRUE(salad->isVegetarian());
}

TEST_F(MenuSystemTest, AddIngredient){
  salad->addIngredient("Cheese");
  ASSERT_TRUE(salad->hasIngredient("Cheese"));
}

TEST_F(MenuSystemTest, SetNewPrice){
  gyro->setPrice(5.50);
  ASSERT_EQ(5.50, gyro->getPrice());
}

TEST_F(MenuSystemTest, setVegetarian){
  gyro->setIsVegetarian(true);
  ASSERT_TRUE(gyro->isVegetarian());
}

#endif
