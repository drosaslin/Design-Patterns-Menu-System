#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>
#include "base_menu.h"
using namespace std;

class Menu:public NaseMenu
{
public:
  class MenuIterator:public Iterator<BaseMenu *>
  {
  public:
    MenuIterator(Menu *m)
    {
      _menu=m;
    }
    void first()
    {
      _current=_menu->_vMenu.begin();
    }
    void next()
    {
      ++_current;
    }
    bool isDone()const
    {
      return (_current == _menu->_vMenu.end());
    }
    BaseMenu *currentItem()
    {
      return *_current;
    }
  private:
    Menu *_menu;
    vector<BaseMenu *>::iterator _current;
  }
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
  bool hasIngredient(std::string ingredient)
  {
    throw std::invalid_argument("Invalid Operation");
  }
  void addItem(BaseMenu* item)
  {
    _vMenu.push_back(item);
  }
  void deleteItem(std::string name)
  {
    for(int i=0;i<_vMenu.size();i++)
    {
      if(_vMenu[i]->name()==name)
      {
        _vMenu.erase(_vMenu.begin()+i);
        break;
      }
    }
  }
  BaseMenu* getItem(std::string name)
  {
    for(int i=0;i<_vMenu.size();i++)
    {
      if(_vMenu[i]->name()==name)
      {
        return _vMenu[i];
      }
    }
    throw std::invalid_argument("Not Found");
    return nullptr;
  }
  bool isVegetarian(BaseMenu* item)
  {
    for(int i=0;i<_vMenu.size();i++)
    {
      if(!_vMenu[i]->getVegetarian())
      {
        return false;
      }
    }
    return true;
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
}
#endif
