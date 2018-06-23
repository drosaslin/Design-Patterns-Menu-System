#ifndef FULL_MENU_H
#define FULL_MENU_H

#include "menu.h"
#include "category.h"
#include "iterator.h"
//#include "sort_by_price_visitor.h"
// #include "sort_by_calorie_visitor.h"
#include "visitor.h"
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

  FullMenu(){
  }

  FullMenu(string name, string description)
    :Menu(name, description)
  {
  }

  void AddCategory(Category& cat){
    _vCategory.push_back(cat);
  }

  void DelCategory(string name){
    for(int n = 0; n < _vCategory.size(); n++){
      if (_vCategory[n].GetName() == name){
        _vCategory.erase(_vCategory.begin()+n);
        return;
      }
    }
  }

  void DisplayCategories() {
    int n;
    Iterator<Category>* it = createIterator();
    for(n = 1, it->first(); !it->isDone(); it->next(), n++) {
      cout << n << ". " << it->currentItem().GetName() << endl;
    }
  }

  void ShowMenu(){
    Iterator<Category>* it = createIterator();
    std::cout << GetName() << std::endl;
    for(it->first(); !it->isDone(); it->next()) {
      std::cout << std::endl << it->currentItem().GetName() << std::endl;
      it->currentItem().ShowMenu();
    }
  }

  Category& GetCategory(int index) {
    if(index >= 0 && index <= _vCategory.size())
      return _vCategory[index];
  }

  int GetSize() {
    return (int)_vCategory.size();
  }

  Iterator<Category>* createIterator()
  {
    return new FullMenuIterator(this);
  }

  // void accept(Visitor &v)
  // {
  //   v.visit(this);
  // }

private:
  std::vector<Category> _vCategory;
};

#endif
