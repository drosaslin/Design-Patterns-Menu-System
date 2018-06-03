#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include "manager.h"
using namespace std;

void LoginMenu();
void InitMenu();

int main()
{
  //InitMenu();

  LoginMenu();
  cout << "Choose your user type: ";
  string input;
  while(1)
  {
    cin >> input;
    if(input=="1")
    {
      system("clear");
    }
    else if(input=="2")
    {
      system("clear");
      Manager manager("AAA","001");
      manager.Operation();
    }
    else if(input=="3")
    {
      break;
    }
    else
    {
      system("clear");
      cout<<"Invalid input.Please input'1' or '2' or '3'"<<endl;
    }
    system("clear");
    LoginMenu();
    cout << "Choose your user type: ";
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
      <<"\t+     3. Exit                          +"<<endl
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
