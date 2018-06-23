#ifndef FULL_MENU_H
#define FULL_MENU_H

#include "menu.h"
#include "category.h"
#include "iterator.h"
#include <string>
#include <vector>

using namespace std;

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
      std::cout << "This category doesn't exist" << std::endl;
    }
  }

  Item* GetItem(string name)
  {
    //Iterator<Ingredient *> *it = createIterator();
    // for (it->first();!it->isDone();it->next()) {
    //   if(it->currentItem()->GetName()==name) return it->currentItem();
    // }
    //throw std::invalid_argument("Not Found");
    return nullptr;
  }

  void ShowMenu(){
    Iterator<Category>* it = createIterator();
    std::cout << GetName() << std::endl;
    for(it->first(); !it->isDone(); it->next()) {
      std::cout << std::endl << it->currentItem().GetName() << std::endl;
      it->currentItem().ShowMenu();
    }
    // for(int n = 0; n < _vCategory.size(); n++){
    //   std::cout << _vCategory[n].GetName() << std::endl;
    //   _vCategory[n].ShowMenu();
    //   std::cout << std::endl;
    // }
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

  void accept(Visitor &v)
  {
    v.visit(this);
  }

private:
  std::vector<Category> _vCategory;
  std::vector<Menu *> _vMenu;
};

#endif
