#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <vector>
#include "ingredient.h"
#include "iterator.h"
using namespace std;

class Item : public Product
{
public:
  class ItemIterator : public Iterator<Ingredient*>
  {
  public:
    ItemIterator(Item *it)
    {
      _item=it;
    }
    void first()
    {
      _current=_item->_vIngredient.begin();
    }
    void next()
    {
      ++_current;
    }
    bool isDone()const
    {
      return (_current == _item->_vIngredient.end());
    }
    Ingredient *currentItem()
    {
      return *_current;
    }
  private:
    Item *_item;
    vector<Ingredient *>::iterator _current;
  };

  Item()
  {

  }

  Item(string name, string description, string productCode, int price)
  :Product(name, description, productCode), _price(price)
  {

  }
  // Item()
  // :Ingredient(name), _price(price), _perProtein(num1), _perFat(num2), _perCarbonhydratesr(num3), _weight(w)
  // {
  //
  // }
  Iterator<Ingredient *>*createIterator()
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
  // string GetName()
  // {
  //   return _name;
  // }
  // string GetDescription()
  // {
  //   return _description;
  // }
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
  void AddIngredient(Ingredient *ingredient)
  {
    _vIngredient.push_back(ingredient);
  }
  // void DelIngredient(string name)
  // {
  //   Iterator<_vIngredient *> *it = createIterator();
  //   for (it->first();!it->isDone();it->next())
  //   {
  //     if(it->currentItem()->GetName()==name)
  //     {
  //       _vItem.erase(it->currentItem());
  //       break;
  //     }
  //   }
  // }
  Ingredient* GetItem(string name)
  {
    Iterator<Ingredient *> *it = createIterator();
    for (it->first();!it->isDone();it->next()) {
      if(it->currentItem()->GetName()==name) return it->currentItem();
    }
    //throw std::invalid_argument("Not Found");
    return nullptr;
  }

private:
  string _name, _description;
  double _price, _perProtein, _perFat, _perCarbonhydrates, _weight;
  bool _isVegetarian;
  vector<Ingredient *> _vIngredient;
};

#endif
