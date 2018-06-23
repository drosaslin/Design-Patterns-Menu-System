#ifndef CATEGORY_H
#define CATEGORY_H

#include "menu.h"
#include "item.h"
#include "visitor.h"
//#include "sort_by_price_visitor.h"
// #include "sort_by_calorie_visitor.h"
#include <string>
#include <vector>

class Category : public Menu{
public:
  class CategoryIterator : public Iterator<Item>
  {
  public:
    CategoryIterator(Category *it)
    {
      _category = it;
    }
    void first()
    {
      _current = _category->_vItem.begin();
    }
    void next()
    {
      ++_current;
    }
    bool isDone()const
    {
      return (_current == _category->_vItem.end());
    }
    Item currentItem()
    {
      return *_current;
    }
  private:
    Category *_category;
    vector<Item>::iterator _current;
  };

  Category(){}

  Category(std::string name, std::string description)
    :Menu(name, description)
  {
  }

  void AddItem(Item *item){
    _vItem.push_back(*item);
    item->AddObserver(this);
  }

  void DelItem(std::string name){
    for(int n = 0; n < _vItem.size(); n++){
      if (_vItem[n].GetName() == name){
        //cout << _vItem[n].GetName() << "deleted\n";
        _vItem.erase(_vItem.begin()+n);
        return;
      }
    }
  }

  void ShowMenu(){
    Iterator<Item>* it = createIterator();
    for(it->first(); !it->isDone(); it->next()) {
      std::cout << it->currentItem().GetProductCode() << " " << it->currentItem().GetName() << "     " << it->currentItem().GetDescription() << "    " << fixed << setprecision(2) << it->currentItem().GetPrice() << std::endl;
    }
  }

  void update(string itemName) {
      DelItem(itemName);
  }

  Item GetItem(int index) {
    if(index >= 0 && index <= _vItem.size())
      return _vItem[index];
  }

  int GetSize() {
    return (int)_vItem.size();
  }

  Iterator<Item>* createIterator() {
    return new CategoryIterator(this);
  }

  // void accept(Visitor &v)
  // {
  //   v.visit(this);
  // }

private:
  std::vector<Item> _vItem;
};

#endif
