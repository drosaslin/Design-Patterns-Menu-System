#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>
#include "full_menu.h"
#include "iterator.h"
#include "full_menu.h"
#include "category.h"
using namespace std;

class Manager
{
public:
  Manager();
  Manager(string,string);
  void PrintOperations();
  void AddCategory(FullMenu& menu);
  void DelCategory(FullMenu& menu);
  void ModifyCategory(FullMenu& menu, vector<Item>& item);
  void CreateItem(vector<Item>& item, vector<Ingredient>& ingredient);
  void ManageStorage(vector<Item>& item, vector<Ingredient>& ingredient);

private:
  string _name,_number;

  void AddItemToCategory(FullMenu& menu, vector<Item>& item);
  void DeleteItemFromCategory(FullMenu& menu);
  void AddIngredientToItem(Item& item, vector<Ingredient>& ingredient);
};
#endif
