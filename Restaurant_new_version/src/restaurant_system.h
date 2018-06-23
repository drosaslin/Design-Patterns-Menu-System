#ifndef RESTAURANT_SYSTEM_H
#define RESTAURANT_SYSTEM_H

#include "../src/menu.h"
#include "../src/category.h"
#include "../src/full_menu.h"
#include "../src/product.h"
#include "../src/item.h"
#include "../src/ingredient.h"
#include "../src/manager.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdlib.h>

using namespace std;

class RestaurantSystem {
public:
  RestaurantSystem() {
    _vIngredient.push_back(Ingredient("Meat", "delicious meat", 0.2, 0.13, 0.16, 0.24, false));
    _vIngredient.push_back(Ingredient("Tomato", "delicious bread", 0.2, 0.13, 0.16, 0.24, true));
    _vIngredient.push_back(Ingredient("Spaghetti", "delicious bread", 0.2, 0.13, 0.16, 0.24, true));
    _vIngredient.push_back(Ingredient("Onion", "delicious bread", 0.20, 0.13, 0.16, 0.24, true));
    _vIngredient.push_back(Ingredient("Water", "delicious water", 0.2, 0.13, 0.16, 0.24, false));
    _vIngredient.push_back(Ingredient("Shrimp", "delicious shrimp", 0.2, 0.13, 0.16, 0.24, true));
    _vIngredient.push_back(Ingredient("Cheese", "delicious cheese", 0.2, 0.13, 0.16, 0.24, true));
    _vIngredient.push_back(Ingredient("Mushroom", "delicious mushroom", 0.20, 0.13, 0.16, 0.24, true));
    _vItem.push_back(Item("Hamburger", "delicious hamburger", 10));
    _vItem[0].AddIngredient(&_vIngredient[0]);
    _vItem[0].AddIngredient(&_vIngredient[1]);
    _vItem[0].AddIngredient(&_vIngredient[3]);
    _vItem.push_back(Item("Cheeseburger", "delicious cheeseburger", 10));
    _vItem[0].AddIngredient(&_vIngredient[0]);
    _vItem[0].AddIngredient(&_vIngredient[6]);
    _vItem[0].AddIngredient(&_vIngredient[1]);
    _vItem[0].AddIngredient(&_vIngredient[3]);
    _vItem.push_back(Item("Mushroom burger", "delicious shroomburger", 10));
    _vItem[0].AddIngredient(&_vIngredient[0]);
    _vItem[0].AddIngredient(&_vIngredient[6]);
    _vItem[0].AddIngredient(&_vIngredient[1]);
    _vItem[0].AddIngredient(&_vIngredient[7]);
    _vItem[0].AddIngredient(&_vIngredient[3]);
    _vItem.push_back(Item("Carbonara", "delicious carbonara", 10));
    _vItem[1].AddIngredient(&_vIngredient[0]);
    _vItem[1].AddIngredient(&_vIngredient[1]);
    _vItem[1].AddIngredient(&_vIngredient[2]);
    _vItem[1].AddIngredient(&_vIngredient[6]);
    _vItem.push_back(Item("Spaghetti and Mushrooms", "delicious carbonara", 10));
    _vItem[1].AddIngredient(&_vIngredient[0]);
    _vItem[1].AddIngredient(&_vIngredient[1]);
    _vItem[1].AddIngredient(&_vIngredient[2]);
    _vItem[1].AddIngredient(&_vIngredient[7]);
    _vItem.push_back(Item("Brownie", "delicious brownie", 10));
    _vItem.push_back(Item("Cheese Cake", "delicious cheese cake", 10));
    _vCategory.push_back(Category("Hamburgers", "delicious hamburgers"));
    _vCategory.push_back(Category("Pasta", "delicious pasta"));
    _vCategory.push_back(Category("Desserts", "delicious desserts"));
    _vCategory[0].AddItem(&_vItem[0]);
    _vCategory[0].AddItem(&_vItem[1]);
    _vCategory[0].AddItem(&_vItem[2]);
    _vCategory[1].AddItem(&_vItem[3]);
    _vCategory[1].AddItem(&_vItem[4]);
    _vCategory[2].AddItem(&_vItem[5]);
    _vCategory[2].AddItem(&_vItem[6]);
    for(int n = 0; n < _vCategory.size(); n++) {
      fullMenu.AddCategory(_vCategory[n]);
    }
  }

  void ManagerOperations() {
    regex com("[1-7]");
    string command;
    do {
      manager.PrintOperations();
      cout<<"Please input command: ";
      cin>>command;
      if (regex_match(command,com))
      {
        if (command == "1")
          fullMenu.ShowMenu();
        else if (command=="2")
          manager.AddCategory(fullMenu);
        else if (command=="3")
          manager.DelCategory(fullMenu);
        else if (command=="4")
          manager.ModifyCategory(fullMenu, _vItem);
        else if (command=="5")
          manager.ManageStorage(_vItem, _vIngredient);
        // else if (command=="6")
        //   DelItem();
        // else if (command=="6")
        //   DelItem();
        else if (command=="7")
          break;
      }
      else
        cout << "Input Error. Please input 1 ~ 7:" << endl;
    }while(1);
  }


private:
  vector<Ingredient> _vIngredient;
  vector<Item> _vItem;
  vector<Category> _vCategory;
  FullMenu fullMenu;
  Manager manager;
};

#endif
