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

  void OrderMenu(FullMenu fullMenu)
  {
    string itemCode = " ";
    bool isFound = false;
    do
    {
      cout << "Please input the code of the item to order (input x when finished): ";
      cin>>itemCode;
      //cin.ignore();
      if (itemCode == "x") break;
      else
      {
        for(int x = 0; isFound == false, x < fullMenu.GetSize(); x++)
        {
          for(int y = 0; y < fullMenu.GetCategory(x).GetSize(); y++)
          {
            //cout << fullMenu.GetCategory(x).GetItem(y).GetName() << " " << fullMenu.GetCategory(x).GetItem(y).GetProductCode() <<endl;
            if(fullMenu.GetCategory(x).GetItem(y).GetProductCode() == itemCode)
            {
              _orderItems.push_back(fullMenu.GetCategory(x).GetItem(y));
              isFound = true;
              break;
            }
          }
        }
      }
      if (isFound == false)
        cout << "That item doesn't exist." << endl;
      else
        isFound = false;

    }while (1);

    PrintReceipt();
  }

  void PrintReceipt()
  {
    system("clear");
    double totalToPay = 0;
    cout << "++++++++   Your Order    ++++++++" << endl;
    for(int n = 0; n < _orderItems.size(); n++)
    {
      cout << _orderItems[n].GetName() << "       " << _orderItems[n].GetPrice() << "\n";
      totalToPay+=_orderItems[n].GetPrice();
    }
    cout << "\n\n" << "Total amount to pay: " << totalToPay << endl << endl;
    cout << "++++++++    Thank You    ++++++++" << "\n\n\n";
    _orderItems.clear();
  }

private:
  string _name;
  double _amountToPay;
  vector <Item> _orderItems;
};

#endif
