#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>
#include "base_menu.h"
using namespace std;

class Menu : public BaseMenu
{
public:
  class MenuIterator : public Iterator<BaseMenu*>
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
  };

  Menu(std::string newName, double price = 0.0, std::string newDescr = "no description available")
    :BaseMenu(newName, newDescr)
  {
    setPrice(price);
  }
  Iterator<BaseMenu *>*createIterator()
  {
    return new MenuIterator(this);
  }
  void addItem(BaseMenu* item)
  {
    _vMenu.push_back(item);
  }
  // void delItem(string name)
  // {
  //   Iterator<BaseMenu *> *it = createIterator();
  //   for (it->first();!it->isDone();it->next())
  //   {
  //     if(it->currentItem()->getName()==name)
  //     {
  //       _vMenu.erase(*it->currentItem());
  //       break;
  //     }
  //   }
  // }
  BaseMenu* getItem(std::string name)
  {
    Iterator<BaseMenu *> *it = createIterator();
    for (it->first();!it->isDone();it->next()) {
      if(it->currentItem()->getName()==name) return it->currentItem();
    }
    //throw std::invalid_argument("Not Found");
    return nullptr;
  }
  bool isVegetarian()
  {
    Iterator<BaseMenu *> *it = createIterator();
    for (it->first();!it->isDone();it->next())
      if(!it->currentItem()->isVegetarian())return false;
    return true;
  }
  bool isVegetarian(BaseMenu *m)
  {
    return m->isVegetarian();
  }
  void setPrice(double)
  {
    _totalPrice*=0.8;
  }
  double getTotalPrice()
  {
    return _totalPrice;
  }

  double getPrice()
  {
    return 0.0;
  }

private:
  double _totalPrice;
  vector<BaseMenu *> _vMenu;
};
#endif
