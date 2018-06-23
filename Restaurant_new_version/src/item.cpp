#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "item.h"
#include "ingredient.h"
#include "iterator.h"
#include "menu.h"
#include "category.h"

using namespace std;

public:
  Item::Item()
  {
  }

  Item::Item(string name, string description, string productCode, double price)
    :Product(name, description, productCode), _price(price)
  {

  }

  Iterator<Ingredient *>* Item::createIterator()
  {
    return new ItemIterator(this);
  }
  void Item::SetPrice(double price)
  {
    _price = price;
  }
  void Item::SetIsVegetarian(bool flag)
  {
    _isVegetarian = flag;
  }
  void Item::SetProtein(double num)
  {
    _perProtein = num;
  }
  double Item::SetFat(double num)
  {
    _perFat = num;
  }
  double Item::SetCarbohydrates(double num)
  {
    _perCarbonhydrates = num;
  }
  double Item::GetPrice()
  {
    return _price;
  }
  bool Item::IsVegetarian()
  {
    return _isVegetarian;
  }
  double Item::GetProtein()
  {
    return _weight * _perProtein;
  }
  double Item::GetFat()
  {
    return _weight * _perFat;
  }
  double Item::GetCarbohydrates()
  {
    return _weight * _perCarbonhydrates;
  }
  double Item::GetCalorie()
  {
    return (GetProtein() + GetCarbohydrates()) * 4000 + GetFat() * 9000;
  }
  double Item::GetWeight()
  {
    return _weight;
  }
  void Item::AddIngredient(Ingredient *ingredient)
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
  Ingredient* Item::GetItem(string name)
  {
    Iterator<Ingredient *> *it = createIterator();
    for (it->first();!it->isDone();it->next()) {
      if(it->currentItem()->GetName()==name) return it->currentItem();
    }
    //throw std::invalid_argument("Not Found");
    return nullptr;
  }

  void Item::AddObserver(Menu* cat) {
    _observers.push_back(cat);
    //cout << GetName() << " observer" << cat->GetName() << endl;
  }

  void Item::NotifyDeletion() {
    //cout << "notiying" << _observers[0]->GetName() << endl;
    for(int n = _observers.size() - 1; n >= 0; n--) {
      _observers[n]->update(GetName());
      _observers.erase(_observers.begin() + n);
    }
    //cout << "notified" << endl;
  }
;
