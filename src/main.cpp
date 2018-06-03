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

void InitMenu()
{
  Menu menu1("Breakfast");
  Menu menu2("Lunch");
  Menu menu3("Dinner");
}
