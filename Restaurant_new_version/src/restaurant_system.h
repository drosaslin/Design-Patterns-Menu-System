#ifndef RESTAURANT_SYSTEM_H
#define RESTAURANT_SYSTEM_H

#include "../src/menu.h"
#include "../src/category.h"
#include "../src/full_menu.h"
#include "../src/product.h"
#include "../src/item.h"
#include "../src/ingredient.h"
#include "manager.h"
#include "customer.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdlib.h>

using namespace std;

class RestaurantSystem {
public:
  RestaurantSystem() {
    _vIngredient.push_back(Ingredient("Meat", 0.2, 0.13, 0.16, 0.24, false));
    _vIngredient.push_back(Ingredient("Tomato", 0.2, 0.13, 0.16, 0.24, true));
    _vIngredient.push_back(Ingredient("Spaghetti", 0.2, 0.13, 0.16, 0.24, true));
    _vIngredient.push_back(Ingredient("Onion", 0.20, 0.13, 0.16, 0.24, true));
    _vIngredient.push_back(Ingredient("Water", 0.2, 0.13, 0.16, 0.24, false));
    _vIngredient.push_back(Ingredient("Shrimp",  0.2, 0.13, 0.16, 0.24, true));
    _vIngredient.push_back(Ingredient("Cheese",  0.2, 0.13, 0.16, 0.24, true));
    _vIngredient.push_back(Ingredient("Mushroom", 0.20, 0.13, 0.16, 0.24, true));
    _vItem.push_back(Item("Hamburger", "delicious hamburger", "H01", 10));
    _vItem[0].AddIngredient(&_vIngredient[0]);
    _vItem[0].AddIngredient(&_vIngredient[1]);
    _vItem[0].AddIngredient(&_vIngredient[3]);
    _vItem.push_back(Item("Cheeseburger", "delicious cheeseburger", "H02",10));
    _vItem[0].AddIngredient(&_vIngredient[0]);
    _vItem[0].AddIngredient(&_vIngredient[6]);
    _vItem[0].AddIngredient(&_vIngredient[1]);
    _vItem[0].AddIngredient(&_vIngredient[3]);
    _vItem.push_back(Item("Mushroom burger", "delicious shroomburger", "H03", 10));
    _vItem[0].AddIngredient(&_vIngredient[0]);
    _vItem[0].AddIngredient(&_vIngredient[6]);
    _vItem[0].AddIngredient(&_vIngredient[1]);
    _vItem[0].AddIngredient(&_vIngredient[7]);
    _vItem[0].AddIngredient(&_vIngredient[3]);
    _vItem.push_back(Item("Carbonara", "delicious carbonara", "P01", 10));
    _vItem[1].AddIngredient(&_vIngredient[0]);
    _vItem[1].AddIngredient(&_vIngredient[1]);
    _vItem[1].AddIngredient(&_vIngredient[2]);
    _vItem[1].AddIngredient(&_vIngredient[6]);
    _vItem.push_back(Item("Spaghetti and Mushrooms", "delicious carbonara", "P02", 10));
    _vItem[1].AddIngredient(&_vIngredient[0]);
    _vItem[1].AddIngredient(&_vIngredient[1]);
    _vItem[1].AddIngredient(&_vIngredient[2]);
    _vItem[1].AddIngredient(&_vIngredient[7]);
    _vItem.push_back(Item("Brownie", "delicious brownie", "D01", 10));
    _vItem.push_back(Item("Cheese Cake", "delicious cheese cake", "D02", 10));
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
      ShowManagerMenu();
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

  void CustomerOperations(){
     regex com("[1-3]");
     string command;

     do {
       ShowCustomerMenu();
       cout<<"Please input command: ";
       cin>>command;
       if (regex_match(command,com))
       {
         if (command == "1")
           fullMenu.ShowMenu();
         else if (command=="2")
           customer.OrderMenu();
         else if (command=="3")
           break;
       }
       else
         cout << "Input Error. Please input 1 ~ 3:" << endl;
     }while(1);
   }

  void ShowManagerMenu() {
    cout<<"\t++++++++++++++++++++++++++++++++++++++++"<<endl
        <<"\t+                                      +"<<endl
        <<"\t+     Welcome to the ManagerSystem     +"<<endl
        <<"\t+     1. Display Menu                  +"<<endl
        <<"\t+     2. Add Category                  +"<<endl
        <<"\t+     3. Delete Category               +"<<endl
        <<"\t+     4. Modify Categories             +"<<endl
        <<"\t+     5. Manage Storage                +"<<endl
        <<"\t+     6. Delete Item                   +"<<endl
        <<"\t+     7. Exit                          +"<<endl
        <<"\t+                                      +"<<endl
        <<"\t++++++++++++++++++++++++++++++++++++++++"<<endl;
  }

    void ShowCustomerMenu(){
      cout<<"\t++++++++++++++++++++++++++++++++++++++++"<<endl
          <<"\t+                                      +"<<endl
          <<"\t+     Welcome to the Customer System   +"<<endl
          <<"\t+     1. Display Menu                  +"<<endl
          <<"\t+     2. Order                         +"<<endl
          <<"\t+     3. Exit                          +"<<endl
          <<"\t+                                      +"<<endl
          <<"\t++++++++++++++++++++++++++++++++++++++++"<<endl;
    }

private:
  vector<Ingredient> _vIngredient;
  vector<Item> _vItem;
  vector<Category> _vCategory;
  FullMenu fullMenu;
  Manager manager;
  Customer customer;
};

#endif
