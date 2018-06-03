#include <iostream>
#include <cstdlib>
#include <string>
#include "manager.h"
using namespace std;

Manager::Manager(string name,string number):_name(name),_number(number)
{
  /*BaseMenu* menu1 = new Menu("Breakfast");
  BaseMenu* item1 = new MenuItem("Pancake",50,true,"It is very delicious.");
  BaseMenu* item2 = new MenuItem("Sandwich",15,false,"It is very delicious.");
  BaseMenu* item3 = new MenuItem("Milk Tea",20,false,"It is very delicious.");
  menu1->addItem(item1);
  menu1->addItem(item2);
  menu1->addItem(item3);*/
}
/*void Manager::~Manager()
{

}*/
void Manager::Operation()
{
  cout<<"\t++++++++++++++++++++++++++++++++++++++++"<<endl
      <<"\t+                                      +"<<endl
      <<"\t+     Welcome to the ManagerSystem     +"<<endl
      <<"\t+     1. Display All Menu              +"<<endl
      <<"\t+     2. Display All Item              +"<<endl
      <<"\t+     3. Add New Menu                  +"<<endl
      <<"\t+     4. Add New Item                  +"<<endl
      <<"\t+     5. Delete Menu                   +"<<endl
      <<"\t+     6. Delete Item                   +"<<endl
      <<"\t+                                      +"<<endl
      <<"\t++++++++++++++++++++++++++++++++++++++++"<<endl;
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
