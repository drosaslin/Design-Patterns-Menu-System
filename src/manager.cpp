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
void Manager::Operation()
{
  cout<<"\t++++++++++++++++++++++++++++++++++++++++"<<endl
      <<"\t+                                      +"<<endl
      <<"\t+     Welcome to the ManagerSystem     +"<<endl
      <<"\t+     1. Display All Menus & Items     +"<<endl
      <<"\t+     2. Display All Items             +"<<endl
      <<"\t+     3. Add New Menu                  +"<<endl
      <<"\t+     4. Delete Menu                   +"<<endl
      <<"\t+     5. Add New Item                  +"<<endl
      <<"\t+     6. Delete Item                   +"<<endl
      <<"\t+                                      +"<<endl
      <<"\t++++++++++++++++++++++++++++++++++++++++"<<endl;
  string command;
  regex com("[1-6]");
  cout<<"Please input command";
  cin>>command;
  while(1)
  {
    if (regex_match(command,com))
    {
      if (command=="1")
      {
        PrintMenu();
      }
      else if (command=="2")
      {
        PrintItem();
      }
      else if (command=="3")
      {
        AddMenu();
      }
      else if (command=="4")
      {
        DelManu();
      }
      else if (command=="5")
      {
        AddItem();
      }
      else if (command=="6")
      {
        DelItem();
      }
      break;
    }
    else
    {
      cout<<"Input Error. Please input 1 ~ 6:";
      cin>>command;
    }
  }

}
void Manager::PrintMenuAndItem()
{

}
void Manager::PrintMenu()
{

}
void Manager::PrintItem()
{

}
void Manager::AddMenu()
{

}
void Manager::DelMenu()
{

}
void Manager::AddItem()
{

}
void Manager::DelItem()
{

}
