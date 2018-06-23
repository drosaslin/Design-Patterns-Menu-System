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

  void OrderMenu()
  {
    string itemCode;
    do
    {

    }while (itemCode != "x");
  }

private:
  string _name;
  double _amountToPay;
  vector <Item *> _orderItems;
};

#endif
