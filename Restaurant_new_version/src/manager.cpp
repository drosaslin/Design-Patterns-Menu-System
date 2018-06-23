#include <iostream>
#include <cstdlib>
#include <string>
#include "manager.h"
#include "visitor.h"
#include "sort_by_price_visitor.h"
#include "sort_by_name_visitor.h"
using namespace std;

Manager::Manager():_name("Manager"), _number("1"){
}

Manager::Manager(string name = "Manager",string number = "1"):_name(name),_number(number)
{
}

void Manager::PrintOperations()
{
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

void Manager::MenuOptions(FullMenu& fullMenu) {
  system("clear");
  fullMenu.ShowMenu();
  cout << endl;
  string input;
  int index;
  do {
    cout << "1. Order items by price" << endl
        << "2. Order items by name" << endl
        << "3. Go back" << endl;
    cout << "choose command: ";
    cin >> input;
    if(input != "1" && input != "2" && input != "3")
      cout << "Invalid input, please try again\n";
    else CallVisitor(fullMenu, input);
  }while(input != "3");
  system("clear");
}

void Manager::CallVisitor(FullMenu& menu, string command) {
  if(command == "1") {
    system("clear");
    Visitor *v = new SortByPriceVisitor();
    menu.accept(*v);
  }
  if(command == "2"){
    system("clear");
    Visitor *v = new SortByNameVisitor();
    menu.accept(*v);
  }
}

void Manager::AddCategory(FullMenu& menu)
{
  string name, description;
  do {
    cout<<"Please input category name(input 'x' to cancel):";
    cin.ignore();
    getline(cin, name);
  }while(IsCategoryRepeated(menu, name) && name != "x");
  if(name == "x") return;

  cout<<"Please input category description:";
  cin.ignore();
  getline(cin, description);
  Category newCat(name, description);
  menu.AddCategory(newCat);
  system("clear");
  cout << name << " successfully added!\n";
}

void Manager::AddCategory(FullMenu& menu, Category& newCat)
{
  menu.AddCategory(newCat);
}

void Manager::DelCategory(FullMenu& menu)
{
  system("clear");
  string input;
  int index;
  menu.DisplayCategories();
  do {
    cout << "Please input the category you want to delete(input 'x' to cancel): ";
    cin >> input;
    index = atoi(input.c_str());
    if(index > 0 && index <= menu.GetSize() || input == "x") break;
    else cout << "Invalid input, please try again.\n";
  }while(1);
  system("clear");
  if(input != "x") {
    cout << menu.GetCategory(index - 1).GetName() << " successfully deleted!\n";
    menu.DelCategory(menu.GetCategory(index - 1).GetName());
  }
}

void Manager::ModifyCategory(FullMenu& menu, vector<Item>& item)
{
  string command;
  cout << "1. Add items to category" << endl << "2. Delete items from category" << endl << "3. Go back\n\n";
  cout << "Please choose your command: ";
  cin.ignore();
  do{
    getline(cin, command);
    if(command == "1")
      AddItemToCategory(menu, item);
    else if(command == "2")
      DeleteItemFromCategory(menu);
    else if(command == "3")
      return;
    else
      cout << "invalid input, please try again\n";
  }while(command != "1" && command != "2" && command != "3");
}

void Manager::AddItemToCategory(FullMenu& menu, vector<Item>& item)
{
    string input;
    int category;
    cout << endl;
    for(int n = 0; n < menu.GetSize(); n++) {
      cout << n + 1 << ". " << menu.GetCategory(n).GetName() << endl;
    }
    do{
      cout << "Choose category(input 'x' to cancel): ";
      cin >> input;
      category = atoi(input.c_str());
      if(category > 0 && category <= menu.GetSize() || input == "x") break;
      else cout << "invalid input, please try again\n";
    }while(1);
    if(input == "x") return;

    cout << endl;
    int itemChosen;
    for(int n = 0; n < item.size(); n++) {
      cout << n + 1 << ". " << item[n].GetName() << endl;
    }
    do {
      cout << "Choose item to add(input 'x' to cancel): ";
      cin >> input;
      itemChosen = atoi(input.c_str());
      if(itemChosen > 0 && itemChosen <= item.size()) {
        menu.GetCategory(category - 1).AddItem(&item[itemChosen - 1]);
        cout << item[itemChosen - 1].GetName() << " added\n";
      }
      else if(input != "x")
        cout << "invalid input, please try again\n";
    }while(input != "x");
    system("clear");
}

void Manager::AddItemToCategory(FullMenu& menu, vector<Item>& item, int catIndex, int itemIndex)
{
    menu.GetCategory(catIndex - 1).AddItem(&item[itemIndex - 1]);
}

void Manager::DeleteItemFromCategory(FullMenu& menu)
{
  int category, itemChosen;
  cout << endl;
  for(int n = 0; n < menu.GetSize(); n++) {
    cout << n + 1 << ". " << menu.GetCategory(n).GetName() << endl;
  }
  cout << "Choose category: ";
  cin >> category;

  cout << endl;
  for(int n = 0; n < menu.GetCategory(category - 1).GetSize(); n++) {
    cout << n + 1 << ". " << menu.GetCategory(category - 1).GetItem(n).GetName() << endl;
  }
  cout << "Choose item to delete: ";
  cin >> itemChosen;

  string itemName = menu.GetCategory(category - 1).GetItem(itemChosen - 1).GetName();
  menu.GetCategory(category - 1).DelItem(itemName);
}

void Manager::ManageStorage(vector<Item>& item, vector<Ingredient>& ingredient)
{
  string command;
  cout << "\n1. Create new item" << endl << "2. Delete item" << endl;
  cout << "Please choose your command: ";
  cin.ignore();
  do{
  getline(cin, command);
  if(command == "1")
    CreateItem(item, ingredient);
  else if(command == "2")
    DeleteItemFromStorage(item);
  else if(command == "3")
    return;
  else
    cout << "invalid input, please try again\n";
  }while(command != "1" && command != "2" && command != "3");
}

void Manager::CreateItem(vector<Item>& item, vector<Ingredient>& ingredient)
{
  system("clear");
  double price;
  string name, description, itemCode, priceInput;
  do{
  cout << "Enter the item's name(input 'x' to cancel): ";
    getline(cin, name);
  }while(IsItemNameRepeated(item, name) && name != "x");
  if(name == "x") return;

  cout << "Enter the item's description(input 'x' to cancel): ";
  getline(cin, description);
  if(description == "x") return;

  do{
    cout << "Enter the item's price(input 'x' to cancel): ";
    getline(cin, priceInput);
    price = atof(priceInput.c_str());
  }while(price < 0 && priceInput != "x");
  if(priceInput == "x") return;

  do{
    cout << "Enter the item's code: ";
    cin >> itemCode;
  }while(IsItemCodeRepeated(item, itemCode));

  item.push_back(Item(name, description, itemCode, price));
  AddIngredientToItem(item[item.size() - 1], ingredient);
  system("clear");
  cout << name << " successfully created!\n";
}

bool Manager::IsItemNameRepeated(vector<Item>& item, string name) {
  for(int n = item.size() - 1; n >= 0; n--) {
    if(item[n].GetName() == name) {
      cout << "This item already exist, please choose another name\n";
      return true;
    }
  }
  return false;
}

bool Manager::IsItemCodeRepeated(vector<Item>& item, string code) {
  for(int n = item.size() - 1; n >= 0; n--) {
    if(item[n].GetProductCode() == code) {
      cout << "This code is already taken, please choose another one\n";
      return true;
    }
  }
  return false;
}

bool Manager::IsCategoryRepeated(FullMenu& menu, string name) {
  Iterator<Category>* it = menu.createIterator();
  for(it->first(); !it->isDone(); it->next()) {
    if(it->currentItem().GetName() == name) {
      cout << "This category already exists, please choose another name\n";
      return true;
    }
  }
  return false;
}

void Manager::DeleteItemFromStorage(vector<Item>& item) {
  system("clear");
  string input;
  int index;
  do{
    for(int n = 0; n < item.size(); n++)
      cout << n+1 << ". " << item[n].GetName() << endl;
    cout << "Enter the item you want to delete(input 'x' to go back): ";
    cin >> input;
    index = atoi(input.c_str());
    if(index > 0 && index <= item.size()) {
      item[index - 1].NotifyDeletion();
      system("clear");
      cout << item[index - 1].GetName() << " successfully deleted!\n";
      item.erase(item.begin() + index - 1);
    }
    if(input == "x") break;
  }while(1);
  system("clear");
}

void Manager::AddIngredientToItem(Item& item, vector<Ingredient>& ingredient)
{
  string command;
  cout << endl;
  for(int n = 0; n < ingredient.size(); n++) {
    cout << n + 1 << ". " << ingredient[n].GetName() << endl;
  }

  do {
    cout << "Add ingredients to your item(input 'x' when finished): ";
    cin >> command;
    int index = atoi(command.c_str());
    if(command == "x")
      break;
    else if(index >= 0 && index <= ingredient.size()) {
      item.AddIngredient(&ingredient[index - 1]);
    }
    else
      cout << "Invalid input\n";
  }while(1);
}
