#ifndef UT_MENUITERATOR_H
#define UT_MENUITERATOR_H
#include "../src/iterator.h"

class MenuIteratorTest : public ::testing::Test{

//   protected:
//     BaseMenu* hamburger;
//     BaseMenu* pizza;
//     BaseMenu* spaghetti;
//     BaseMenu* gyro;
//     BaseMenu* salad;
//     BaseMenu* lunchMenu;
//     BaseMenu* dinnerMenu;
//
//     virtual void SetUp(){
//       hamburger = new MenuItem("Hamburger", 5.00, false);
//       pizza = new MenuItem("Pizza", 4.50, false);
//       spaghetti = new MenuItem("Spaghetti", 8.75, false);
//       gyro = new MenuItem("Gyro", 5.00, false);
//       salad = new MenuItem("Salad", 150, true);
//       lunchMenu = new Menu("Lunch Menu");
//       dinnerMenu = new Menu("Dinner Menu");
//
//       hamburger->addIngredient("Cheese");
//       hamburger->addIngredient("Bread");
//       salad->addIngredient("Lettuce");
//       salad->addIngredient("Tomato");
//       salad->addIngredient("Vinegar");
//       lunchMenu->addItem(hamburger);
//       lunchMenu->addItem(gyro);
//       lunchMenu->addItem(salad);
//       dinnerMenu->addItem(hamburger);
//       dinnerMenu->addItem(spaghetti);
//       dinnerMenu->addItem(pizza);
//     }
// };
//
// TEST_F(MenuIteratorTest, AddItemToMenu) {
//   Iterator<BaseMenu*>* it = lunchMenu->createIterator();
//   ASSERT_EQ(nullptr, lunchMenu->getItem("Pizza"));
//   lunchMenu->addItem(pizza);
//   ASSERT_EQ(pizza, lunchMenu->getItem("Pizza"));
// }
//
// TEST_F(MenuIteratorTest, GetMenuItem){
//   Iterator<BaseMenu *>* it = dinnerMenu->createIterator();
//   it->first();
//   ASSERT_EQ("Hamburger", it->currentItem()->getName());
//   it->next();
//   ASSERT_EQ("Spaghetti", it->currentItem()->getName());
//   it->next();
//   ASSERT_EQ("Pizza", it->currentItem()->getName());
//   it->next();
//   ASSERT_TRUE(it->isDone());
// }
//
// TEST_F(MenuIteratorTest, GetMenuItem){
//   Iterator<BaseMenu *>* it = dinnerMenu->createIterator();
//   it->first();
//   ASSERT_EQ("Hamburger", it->currentItem()->getName());
//   it->next();
//   ASSERT_EQ("Spaghetti", it->currentItem()->getName());
//   it->next();
//   ASSERT_EQ("Pizza", it->currentItem()->getName());
//   it->next();
//   ASSERT_TRUE(it->isDone());
};

#endif
