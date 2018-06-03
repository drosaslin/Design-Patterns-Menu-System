#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
using namespace std;

void LoginMenu();

int main()
{
  LoginMenu();
  string input;
  while(cin>>input)
  {
    if(input=="1")
    {
      system("clear");
      cout<<"You are a Customer."<<endl;
      //break;
    }
    else if(input=="2")
    {
      system("clear");
      cout<<"You are a Manager."<<endl;
      //break;
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
