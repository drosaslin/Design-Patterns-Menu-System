#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "ingredient.h"
#include "iterator.h"
#include "menu.h"
#include "category.h"
class Menu;

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
      _current = _item->_vIngredient.begin();
    }
    void next()
    {
      ++_current;
    }
    bool isDone()const
    {
      return (_current == _item->_vIngredient.end());
    }
    Ingredient* currentItem()
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

  Item(string name, string description, string productCode, double price)
    :Product(name, description, productCode), _price(price)
  {

  }

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
  double SetCarbohydrates(double num)
  {
    _perCarbonhydrates = num;
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

  void AddObserver(Menu* cat) {
    _observers.push_back(cat);
    //cout << GetName() << " observer" << cat->GetName() << endl;
  }

  void NotifyDeletion() {
    //cout << "notiying" << _observers[0]->GetName() << endl;
    for(int n = _observers.size() - 1; n >= 0; n--) {
      _observers[n]->update(GetName());
      _observers.erase(_observers.begin() + n);
    }
    //cout << "notified" << endl;
  }

private:
  string _name, _description;
  double _price, _perProtein, _perFat, _perCarbonhydrates, _weight;
  bool _isVegetarian;
  vector<Ingredient*> _vIngredient;
  vector<Menu*> _observers;
};

#endif
