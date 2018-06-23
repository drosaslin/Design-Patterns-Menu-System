#ifndef FULL_MENU_H
#define FULL_MENU_H

#include "menu.h"
#include "category.h"
#include <string>
#include <vector>

class FullMenu: public Menu{
public:
  class FullMenuIterator : public Iterator<Menu *>
  {
  public:
    FullMenuIterator(FullMenu *it)
    {
      _fullMenu=it;
    }
    void first()
    {
      _current=_fullMenu->_vMenu.begin();
    }
    void next()
    {
      ++_current;
    }
    bool isDone()const
    {
      return (_current == _fullMenu->_vMenu.end());
    }
    Menu *currentItem()
    {
      return *_current;
    }
  private:
    FullMenu *_fullMenu;
    vector<Menu *>::iterator _current;
  };
  FullMenu(){}

  FullMenu(string name, string description)
    :Menu(name, description)
  {
  }

  void AddCategory(Category cat){
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

  void ShowMenu(){
    std::cout << GetName() << std::endl;
    for(int n = 0; n < _vCategory.size(); n++){
      std::cout << _vCategory[n].GetName() << std::endl;
      _vCategory[n].ShowMenu();
      std::cout << std::endl;
    }
  }

  Category& GetCategory(int index) {
    if(index >= 0 && index <= _vCategory.size())
      return _vCategory[index];
  }

  int GetSize() {
    return (int)_vCategory.size();
  }

  //READ!!!!!:不會編譯
  Iterator<Menu *>*createIterator()
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
