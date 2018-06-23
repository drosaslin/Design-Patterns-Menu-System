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

// void Manager::Operation()
// {
//   PrintOperations();
//   string command;
//   regex com("[1-7]");
//   cout<<"Please input command: ";
//   cin>>command;
//   while(1)
//   {
//     if (regex_match(command,com))
//     {
//       if (command=="1")
//       {
//         PrintMenuAndItem();
//       }
//       else if (command=="2")
//       {
//         PrintAMenu();
//       }
//       else if (command=="3")
//       {
//         AddMenu();
//       }
//       else if (command=="4")
//       {
//         DelMenu();
//       }
//       else if (command=="5")
//       {
//         AddItem();
//       }
//       else if (command=="6")
//       {
//         DelItem();
//       }
//       else if (command=="6")
//       {
//         DelItem();
//       }
//       else if (command=="7")
//       {
//         break;
//       }
//     }
//     else
//     {
//       cout<<"Input Error. Please input 1 ~ 7:"<<endl;
//     }
//     PrintOperations();
//     cout<<"Please input command: ";
//     cin>>command;
//   }

//}
// void Manager::PrintMenuAndItem(FullMenu menu)
// {
//   int size = _vAllItems.size();
//   for(int n = 0; n < size; n++)
//   {
//     Menu *menu = dynamic_cast<Menu*>(_vAllItems[n]);
//     if(menu)
//       menu->printMenu();
//   }
// }

// void Manager::PrintMenuNames()
// {
//   int x = 1;
//   for(int n = 0; n < _vAllItems.size(); n++)
//   {
//     Menu* menu = dynamic_cast<Menu*>(_vAllItems[n]);
//     if (menu)
//     {
//       cout << x++ << ". ";
//       cout << _vAllItems[n]->getName() << endl;
//     }
//
//   }
// }

// void Manager::PrintAMenu()
// {
//   PrintMenuNames();
//   cout<<"Please input menu name: ";
//   string name;
//   cin.ignore();
//   getline(cin, name);
//   for(int n = 0; n < _vAllItems.size(); n++)
//   {
//     Menu* menu = dynamic_cast<Menu*>(_vAllItems[n]);
//     if (menu)
//     {
//       if (_vAllItems[n]->getName() == name)
//       {
//         _vAllItems[n]->printMenu();
//         return;
//       }
//     }
//   }
//   cout<<"The menu does not exist"<<endl;
// }

// void Manager::PrintAllItems()
// {
//   cout << "\nCurrent Items:\n";
//   for(int n = 0; n < _vAllItems.size(); n++)
//   {
//     MenuItem* item = dynamic_cast<MenuItem*>(_vAllItems[n]);
//     if (item)
//         cout << "-" << _vAllItems[n]->getName() << endl;
//   }
// }

void Manager::AddCategory(FullMenu& menu)
{
  string name, description;
  cout<<"Please input category name:";
  cin.ignore();
  getline(cin, name);

  cout<<"Please input category description:";
  cin.ignore();
  getline(cin, description);

  menu.AddCategory(Category(name, description));
}

void Manager::DelCategory(FullMenu& menu)
{
  string name;
  cout<<"Please input category name:";
  cin.ignore();
  getline(cin, name);
  menu.DelCategory(name);
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
  // if(command == "2")
  //   DeleteItemFromCategory(menu);
}

void Manager::CreateItem(vector<Item>& item, vector<Ingredient>& ingredient)
{
  double price;
  string name, description, productCode;
  cout << "Enter the item's name: ";
  getline(cin, name);
  cout << "Enter the item's description: ";
  getline(cin, description);
  cout << "Enter the item's code: ";
  getline(cin, productCode);
  cout << "Enter the item's price: ";
  cin >> price;

  item.push_back(Item(name, description, productCode, price));
  AddIngredientToItem(item[item.size() - 1], ingredient);
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

// void Manager::DelCategory()
// {
//   string name;
//   PrintMenuNames();
//   cout<<"Which menu do you want to delete:";
//   cin.ignore();
//   getline(cin, name);
//
//   for(int n = 0; n < _vAllItems.size(); n++)
//   {
//     if (menu)
//     {
//       if (_vAllItems[n]->getName() == name)
//       {
//         _vAllItems.erase(_vAllItems.begin() + n);
//         break;
//       }
//     }
//   }
//   PrintMenuNames();
// }

// void Manager::AddItem()
// {
//   string name, description;
//   char yn;
//   double price;
//   bool isVeg;
//   cout << "Input new item name: ";
//   cin.ignore();
//   getline(cin, name);
//
//   cout << "Input item price: ";
//   cin >> price;
//
//   cout << "Is it vegetarian? (y/n): ";
//   cin >> yn;
//   if (yn == 'y') isVeg == true;
//   else isVeg == false;
//
//   cout << "Input new description: ";
//   cin.ignore();
//   getline(cin, description);
//
//   BaseMenu* newItem = new MenuItem(name, price, isVeg, description);
//   _vAllItems.push_back(newItem);
//   PrintAllItems();
// }

// void Manager::DelItem()
// {
//   PrintAllItems();
//   string name;
//   cout<<"Which item do you want to delete?:";
//   cin.ignore();
//   getline(cin, name);
//   for(int n = 0; n < _vAllItems.size(); n++)
//   {
//     MenuItem* item = dynamic_cast<MenuItem*>(_vAllItems[n]);
//     if (item)
//     {
//       if (_vAllItems[n]->getName() == name)
//       {
//         _vAllItems.erase(_vAllItems.begin() + n);
//         break;
//       }
//     }
//   }
//   PrintAllItems();
// }
