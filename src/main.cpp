#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include "manager.h"
#include "base_menu.h"
#include "menu.h"
#include "menu_item.h"
#include "iterator.h"
using namespace std;

void LoginMenu();
void InitMenu();

int main()
{
  //InitMenu();
  BaseMenu* menu1 = new Menu("Breakfast");
  BaseMenu* item1 = new MenuItem("Pancake",50,true,"It is very delicious.");
  BaseMenu* item2 = new MenuItem("Sandwich",15,false,"It is very delicious.");
  BaseMenu* item3 = new MenuItem("Milk Tea",20,false,"It is very delicious.");
  menu1->addItem(item1);
  menu1->addItem(item2);
  menu1->addItem(item3);
  LoginMenu();
  string input;
  while(cin>>input)
  {
    if(input=="1")
    {
      system("clear");
      break;
    }
    else if(input=="2")
    {
      system("clear");
      menu1->printMenu();
    }
    else
    {
      system("clear");
      cout<<"Invalid input.Please input'1' or '2'"<<endl;
    }
    LoginMenu();
  }

  return 0;
}

void LoginMenu()
{
  cout<<"\t++++++++++++++++++++++++++++++++++++++++"<<endl
      <<"\t+                                      +"<<endl
      <<"\t+     Welcome to the MenuSystem        +"<<endl
      <<"\t+     1. Customer                      +"<<endl
      <<"\t+     2. Manager                       +"<<endl
      <<"\t+                                      +"<<endl
      <<"\t++++++++++++++++++++++++++++++++++++++++"<<endl;
}

/*void InitMenu()
{
  Menu menu1("Breakfast");
  MenuItem item1("Pancake",50,true,"It is very delicious.");
  MenuItem item2("Sandwich",15,false,"It is very delicious.");
  MenuItem item3("Milk Tea",20,false,"It is very delicious.");
  menu1.addItem(item1);
  menu1.addItem(item2);
  menu1.addItem(item3);
  //Menu menu2("Lunch");
  //Menu menu3("Dinner");
}*/
