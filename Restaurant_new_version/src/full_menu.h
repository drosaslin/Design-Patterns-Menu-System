#ifndef FULL_MENU_H
#define FULL_MENU_H

#include "menu.h"
#include "category.h"
#include "iterator.h"
//#include "sort_by_price_visitor.h"
// #include "sort_by_calorie_visitor.h"
//#include "visitor.h"
#include <string>
#include <vector>

class FullMenu : public Menu{
public:
  class FullMenuIterator : public Iterator<Category>
  {
  public:
    FullMenuIterator(FullMenu *it)
    {
      _menu = it;
    }
    void first()
    {
      _current = _menu->_vCategory.begin();
    }
    void next()
    {
      ++_current;
    }
    bool isDone() const
    {
      return (_current == _menu->_vCategory.end());
    }
    Category currentItem()
    {
      return *_current;
    }
  private:
    FullMenu *_menu;
    vector<Category>::iterator _current;
  };

  FullMenu();

  FullMenu(string name, string description);

  void AddCategory(Category& cat);

  void DelCategory(string name);

  void DisplayCategories();

  void ShowMenu();

  Category& GetCategory(int index);

  int GetSize();

  Iterator<Category>* createIterator();

  void accept(Visitor &v);

private:
  std::vector<Category> _vCategory;
};

#endif
