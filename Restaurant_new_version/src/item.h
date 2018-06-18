#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <vector>
#include "product.h"
#include "ingredient.h"
#include "iterator.h"
using namespace std;

class Item:public Product
{
public:
  class ItemIterator : public Iterator<Product*>
  {
  public:
    ItemIterator(Item *it)
    {
      _item=it;
    }
    void first()
    {
      _current=_menu->_vItem.begin();
    }
    void next()
    {
      ++_current;
    }
    bool isDone()const
    {
      return (_current == _item->_vItem.end());
    }
    Product *currentItem()
    {
      return *_current;
    }
  private:
    Item *_item;
    vector<Product *>::iterator _current;
  };
  Item()
  {

  }
  Item(string name, string description, double price, double num1, double num2, double num3, double w)
  :_name(name), _description(description), _price(price), _perProtein(num1), _perFat(num2), _perCarbonhydratesr(num3), _weight(w)
  {

  }
  Iterator<Product *>*createIterator()
  {
    return new ItemIterator(this);
  }
  void SetPrice(double price)
  {
    _price = price;
  }
  void SetIsVegetarian(bool flag)
  {
    _isVegetarian = flag;
  }
  void SetProtein(double num)
  {
    _perProtein = num;
  }
  double SetFat(double num)
  {
    _perFat = num;
  }
  double GetCarbohydrates(double num)
  {
    _perCarbonhydrates = num;
  }
  string GetName()
  {
    return _name;
  }
  string GetDescription()
  {
    return _description;
  }
  double GetPrice()
  {
    return _price;
  }
  bool IsVegetarian()
  {

    return _isVegetarian;
  }
  double GetProtein()
  {
    return _weight * _perProtein;
  }
  double GetFat()
  {
    return _weight * _perFat;
  }
  double GetCarbohydrates()
  {
    return _weight * _perCarbonhydrates;
  }
  double GetCalorie()
  {
    return (GetProtein() + GetCarbohydrates()) * 4000 + GetFat() * 9000;
  }
  double GetWeight()
  {
    return _weight;
  }
  void AddIngredient(Product *ingredient)
  {
    _vItem.push_back(ingredient);
  }
  void DelIngredient(string name)
  {
    Iterator<Product *> *it = createIterator();
    for (it->first();!it->isDone();it->next())
    {
      if(it->currentItem()->getName()==name)
      {
        _vItem.erase(*it->currentItem());
        break;
      }
    }
  }
  Product* GetItem(string name)
  {
    Iterator<Product *> *it = createIterator();
    for (it->first();!it->isDone();it->next()) {
      if(it->currentItem()->getName()==name) return it->currentItem();
    }
    //throw std::invalid_argument("Not Found");
    return nullptr;
  }

private:
  string _name,_description;
  double _price, _perProtein, _perFat, _perCarbonhydrates, _weight;
  bool _isVegetarian;
  vector<Product *> _vItem;
};

#endif
