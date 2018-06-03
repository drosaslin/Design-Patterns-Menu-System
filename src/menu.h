#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>
#include <cstdlib>
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

  Menu(std::string newName, std::string newDescr = "no description available")
    :BaseMenu(newName, newDescr)
  {
    _totalPrice = 0;
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
  void setTotalPrice(double)
  {
    Iterator<BaseMenu *> *it = createIterator();
    for (it->first();!it->isDone();it->next())_totalPrice+=it->currentItem()->getPrice();
  }
  double getTotalPrice()
  {
    return _totalPrice;
  }

  double getPrice()
  {
    return _totalPrice;
  }

  void printMenu()
  {
    cout<<"\t++++++++++++++++++++++++++++++++++++++++"<<endl
        <<"\t+                                      +"<<endl
        <<"\t+       "<<getName()<<"            +"<<endl;
    Iterator<BaseMenu *> *it = createIterator();
    int number = 1;
    for (it->first();!it->isDone();it->next())
    {
          cout<<"\t+"<<number<<". "<<it->currentItem()->getName()<<"\t"<<it->currentItem()->getDescription()<<"\t";
          if (it->currentItem()->isVegetarian()) cout<<"T+"<<endl;
          else cout<<"F+\t";
          cout<<it->currentItem()->getPrice()<<"+"<<endl;
    }
    cout <<"\t+                                      +"<<endl
         <<"\t++++++++++++++++++++++++++++++++++++++++"<<endl;
  }
private:
  double _totalPrice;
  vector<BaseMenu *> _vMenu;
};
#endif
