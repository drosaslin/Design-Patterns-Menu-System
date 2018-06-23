#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include "restaurant_system.h"
#include "manager.h"
using namespace std;

void LoginMenu();
void InitMenu();

int main()
{
  RestaurantSystem restaurantSystem;

  do
  {
    string input;
    LoginMenu();
    cout << "Choose your user type: ";
    cin >> input;

    if(input=="1")
    {
      system("clear");
    }
    else if(input=="2")
    {
      system("clear");
      restaurantSystem.ManagerOperations();
    }
    else if(input=="3")
      break;

    else
    {
      system("clear");
      cout<<"Invalid input.Please input'1' or '2' or '3'"<<endl;
    }
    system("clear");
  }while(1);

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
