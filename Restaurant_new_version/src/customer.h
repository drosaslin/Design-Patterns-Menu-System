#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>
#include "full_menu.h"
#include "iterator.h"
#include "category.h"
#include "item.h"
using namespace std;

class Customer{
public:
  Customer(string name = "anon"): _name(name){}

  void OrderMenu(std::vector<Category> vCategory)
  {
    string itemCode = " ";
    bool isFound = false;
    do
    {
      isFound == false;
      cout << "Please input the code of the item to order (input x when finished): ";
      cin>>itemCode;
      //cin.ignore();
      if (itemCode == "x") break;
      else
      {
        for(int x = 0; x < vCategory.size(), isFound == false; x++)
        {
          for(int y = 0; y < vCategory[x].GetSize(); y++)
          {
            if(vCategory[x].GetItem(y).GetProductCode() == itemCode)
            {
              _orderItems.push_back(vCategory[x].GetItem(y));
              isFound = true;
              break;
            }
          }
        }
        if (isFound == false)
          cout << "That item doesn't exist." << endl;
      }
    }while (1);
  }

private:
  string _name;
  double _amountToPay;
  vector <Item> _orderItems;
};

#endif
