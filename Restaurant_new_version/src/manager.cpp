#include <iostream>
#include <cstdlib>
#include <string>
#include "manager.h"
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

void Manager::AddCategory(FullMenu& menu)
{
  string name, description;
  cout<<"Please input category name:";
  cin.ignore();
  getline(cin, name);

  cout<<"Please input category description:";
  cin.ignore();
  getline(cin, description);
  Category newCat(name, description);
  menu.AddCategory(newCat);
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
  cout << "1. Add items to category" << endl << "2. Delete items from category" << endl << endl;
  cout << "Please choose your command: ";
  cin.ignore();
  getline(cin, command);
  if(command == "1")
    AddItemToCategory(menu, item);
  if(command == "2")
    DeleteItemFromCategory(menu);
}

void Manager::AddItemToCategory(FullMenu& menu, vector<Item>& item)
{
    int category;
    cout << endl;
    for(int n = 0; n < menu.GetSize(); n++) {
      cout << n + 1 << ". " << menu.GetCategory(n).GetName() << endl;
    }
    cout << "Choose category: ";
    cin >> category;

    cout << endl;
    int itemChosen;
    for(int n = 0; n < item.size(); n++) {
      cout << n + 1 << ". " << item[n].GetName() << endl;
    }
    cout << "Choose item to add: ";
    cin >> itemChosen;

    menu.GetCategory(category - 1).AddItem(&item[itemChosen - 1]);
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
  getline(cin, command);
  if(command == "1")
    CreateItem(item, ingredient);
  if(command == "2")
    DeleteItemFromStorage(item);
}

void Manager::CreateItem(vector<Item>& item, vector<Ingredient>& ingredient)
{
  double price;
  string name, description, itemCode;
  cout << "Enter the item's name: ";
  getline(cin, name);
  cout << "Enter the item's description: ";
  getline(cin, description);
  cout << "Enter the item's price: ";
  cin >> price;
  cout << "Enter the item's code: ";
  cin >> itemCode;

  item.push_back(Item(name, description, itemCode, price));
  AddIngredientToItem(item[item.size() - 1], ingredient);
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
