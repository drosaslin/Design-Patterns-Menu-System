#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>
#include "base_menu.h"
#include "menu.h"
#include "menu_item.h"
#include "iterator.h"
using namespace std;

class Manager
{
public:
  Manager(string,string);
  void PrintOperations();
  void Operation();
  void PrintMenuAndItem();
  void PrintAMenu();
  void PrintMenuNames();
  void PrintAllItems();
  void AddMenu();
  void DelMenu();
  void AddItem();
  void DelItem();
private:
  string _name,_number;
  vector<BaseMenu*> _vAllItems;
};
#endif
