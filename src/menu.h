#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>
using namespace std;
class Menu:public NaseMenu
{
public:
  Menu(string description,double price):_description(description),_price(price)
  {
  }
  void addIngredient(std::stirng newIngredient)
  {
    throw std::invalid_argument("Invalid Operation");
  }
  void removeIngredient(std::string ingredient)
  {
    throw std::invalid_argument("Invalid Operation");
  }
  bool hasIngredient(stirng ingredient)
  {
    throw std::invalid_argument("Invalid Operation");
  }
  void addItem(BaseMenu* item)
  {
    _vMenu.push_back(item);
  }
  BaseMenu* deleteItem(str::string item)
  {

  }
  BaseMenu* getItem(string name)
  {

  }
  bool isVegetarian(BaseMenu* item)
  {

  }
  string getName()
  {
    return _name;
  }
  string getDescription()
  {
    return _description;
  }
  double getPrice()
  {
    return _price;
  }
private:
  string _name,_description;
  double _price;
  bool _isVegetarian;
  vector<BaseMenu *> _vMenu;
#endif
