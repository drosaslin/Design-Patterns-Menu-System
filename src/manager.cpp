#include <iostream>
#include <cstdlib>
#include <string>
#include "manager.h"
using namespace std;

Manager::Manager(string name,string number):_name(name),_number(number)
{
  BaseMenu* breakfastMenu = new Menu("Breakfast Menu");
  BaseMenu* lunchMenu = new Menu("Lunch Menu");
  BaseMenu* pancake = new MenuItem("Pancake",50,true,"It is very delicious.");
  BaseMenu* sandwich = new MenuItem("Sandwich",15,false,"It is very delicious.");
  BaseMenu* milkTea = new MenuItem("Milk Tea",20,false,"It is very delicious.");
  BaseMenu* hamburger = new MenuItem("Hamburger",90,false,"It is very delicious.");
  BaseMenu* gyro = new MenuItem("Gyro",40,false,"It is very delicious.");
  BaseMenu* taco = new MenuItem("Taco",30,false,"It is very delicious.");
  BaseMenu* cake = new MenuItem("Cake",20,true,"It is very delicious.");
  breakfastMenu->addItem(pancake);
  breakfastMenu->addItem(sandwich);
  breakfastMenu->addItem(milkTea);
  lunchMenu->addItem(hamburger);
  lunchMenu->addItem(taco);
  lunchMenu->addItem(cake);
  lunchMenu->addItem(gyro);
  lunchMenu->addItem(milkTea);

  _vAllItems.push_back(pancake);
  _vAllItems.push_back(sandwich);
  _vAllItems.push_back(milkTea);
  _vAllItems.push_back(hamburger);
  _vAllItems.push_back(gyro);
  _vAllItems.push_back(taco);
  _vAllItems.push_back(cake);
  _vAllItems.push_back(breakfastMenu);
  _vAllItems.push_back(lunchMenu);
}

void Manager::PrintOperations()
{
  cout<<"\t++++++++++++++++++++++++++++++++++++++++"<<endl
      <<"\t+                                      +"<<endl
      <<"\t+     Welcome to the ManagerSystem     +"<<endl
      <<"\t+     1. Display All Menus & Items     +"<<endl
      <<"\t+     2. Display A Menu                +"<<endl
      <<"\t+     3. Add New Menu                  +"<<endl
      <<"\t+     4. Delete Menu                   +"<<endl
      <<"\t+     5. Add New Item                  +"<<endl
      <<"\t+     6. Delete Item                   +"<<endl
      <<"\t+     7. Exit                          +"<<endl
      <<"\t+                                      +"<<endl
      <<"\t++++++++++++++++++++++++++++++++++++++++"<<endl;
}

void Manager::Operation()
{
  PrintOperations();
  string command;
  regex com("[1-7]");
  cout<<"Please input command: ";
  cin>>command;
  while(1)
  {
    if (regex_match(command,com))
    {
      if (command=="1")
      {
        PrintMenuAndItem();
      }
      else if (command=="2")
      {
        PrintAMenu();
      }
      else if (command=="3")
      {
        AddMenu();
      }
      else if (command=="4")
      {
        DelMenu();
      }
      else if (command=="5")
      {
        AddItem();
      }
      else if (command=="6")
      {
        DelItem();
      }
      else if (command=="6")
      {
        DelItem();
      }
      else if (command=="7")
      {
        break;
      }
    }
    else
    {
      cout<<"Input Error. Please input 1 ~ 7:";
    }
    PrintOperations();
    cout<<"Please input command: ";
    cin>>command;
  }

}
void Manager::PrintMenuAndItem()
{
  int size = _vAllItems.size();
  for(int n = 0; n < size; n++)
  {
    Menu *menu = dynamic_cast<Menu*>(_vAllItems[n]);
    if(menu)
      menu->printMenu();
  }
}

void Manager::PrintMenuNames()
{
  int x = 1;
  for(int n = 0; n < _vAllItems.size(); n++)
  {
    Menu* menu = dynamic_cast<Menu*>(_vAllItems[n]);
    if (menu)
    {
      cout << x++ << ". ";
      cout << _vAllItems[n]->getName() << endl;
    }

  }
}

void Manager::PrintAMenu()
{
  PrintMenuNames();
  cout<<"Please input menu name: ";
  string name;
  cin.ignore();
  getline(cin, name);
  for(int n = 0; n < _vAllItems.size(); n++)
  {
    Menu* menu = dynamic_cast<Menu*>(_vAllItems[n]);
    if (menu)
    {
      if (_vAllItems[n]->getName() == name)
      {
        _vAllItems[n]->printMenu();
        return;
      }
    }
  }
  cout<<"The menu does not exist"<<endl;
}

void Manager::PrintAllItems()
{
  cout << "\nCurrent Items:\n";
  for(int n = 0; n < _vAllItems.size(); n++)
  {
    MenuItem* item = dynamic_cast<MenuItem*>(_vAllItems[n]);
    if (item)
        cout << "-" << _vAllItems[n]->getName() << endl;
  }
}

void Manager::AddMenu()
{
  string name, description;
  cout<<"Please input menu name:";
  cin.ignore();
  getline(cin, name);

  cout<<"Please input menu description:";
  cin.ignore();
  getline(cin, description);

  BaseMenu* menu = new Menu(name,description);
  _vAllItems.push_back(menu);

  PrintMenuNames();
}

void Manager::DelMenu()
{
  string name;
  PrintMenuNames();
  cout<<"Which menu do you want to delete:";
  cin.ignore();
  getline(cin, name);

  for(int n = 0; n < _vAllItems.size(); n++)
  {
    Menu* menu = dynamic_cast<Menu*>(_vAllItems[n]);
    if (menu)
    {
      if (_vAllItems[n]->getName() == name)
      {
        _vAllItems.erase(_vAllItems.begin() + n);
        break;
      }
    }
  }
  PrintMenuNames();
}

void Manager::AddItem()
{
  string name, description;
  char yn;
  double price;
  bool isVeg;
  cout << "Input new item name: ";
  cin.ignore();
  getline(cin, name);

  cout << "Input item price: ";
  cin >> price;

  cout << "Is it vegetarian? (y/n): ";
  cin >> yn;
  if (yn == 'y') isVeg == true;
  else isVeg == false;

  cout << "Input new description: ";
  cin.ignore();
  getline(cin, description);

  BaseMenu* newItem = new MenuItem(name, price, isVeg, description);
  _vAllItems.push_back(newItem);
  PrintAllItems();
}

void Manager::DelItem()
{
  PrintAllItems();
  string name;
  cout<<"Which item do you want to delete?:";
  cin.ignore();
  getline(cin, name);
  for(int n = 0; n < _vAllItems.size(); n++)
  {
    MenuItem* item = dynamic_cast<MenuItem*>(_vAllItems[n]);
    if (item)
    {
      if (_vAllItems[n]->getName() == name)
      {
        _vAllItems.erase(_vAllItems.begin() + n);
        break;
      }
    }
  }
  PrintAllItems();
}
