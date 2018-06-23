#ifndef CATEGORY_H
#define CATEGORY_H

#include "menu.h"
#include "item.h"
// //#include "visitor.h"
// //#include "sort_by_price_visitor.h"
// // #include "sort_by_calorie_visitor.h"
// #include <string>
// #include <vector>

class Category : public Menu {
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

  Category();

  Category(std::string name, std::string description);

  void AddItem(Item *item);

  void DelItem(std::string name);

  void ShowMenu();

  void update(string itemName);

  Item GetItem(int index);

  int GetSize();

  Iterator<Item>* createIterator();

  void accept(Visitor &v);

private:
  std::vector<Item> _vItem;
};

#endif
