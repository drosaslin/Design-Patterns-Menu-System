#ifndef CATEGORY_H
#define CATEGORY_H

#include "menu.h"
#include "item.h"
#include <string>
#include <vector>

class Category : public Menu{
public:
  class CategoryIterator : public Iterator<Menu *>
  {
  public:
    CategoryIterator(Category *it)
    {
      _category=it;
    }
    void first()
    {
      _current=_category->_vMenu.begin();
    }
    void next()
    {
      ++_current;
    }
    bool isDone()const
    {
      return (_current == _category->_vMenu.end());
    }
    Menu *currentItem()
    {
      return *_current;
    }
  private:
    Category *_category;
    vector<Menu *>::iterator _current;
  };
  Category(){}

  Category(std::string name, std::string description)
    :Menu(name, description)
  {
  }

  //READ!!!!! 不會編譯
 Iterator<Menu *>*createIterator()
  {
     return new CategoryIterator(this);
  }


  void AddItem(Item *item){
    _vItem.push_back(item);
  }

  void DelItem(std::string name){
    for(int n = 0; n < _vItem.size(); n++){
      if (_vItem[n]->GetName() == name){
        _vItem.erase(_vItem.begin()+n);
        return;
      }
    }
  }

  void ShowMenu(){
    for(int n = 0; n < _vItem.size(); n++){
      std::cout << _vItem[n]->GetProductCode() << " " << _vItem[n]->GetName() << " " <<_vItem[n]->GetDescription() << " " << _vItem[n]->GetPrice() << std::endl;
    }
  }

  Item GetItem(int index) {
    if(index >= 0 && index <= _vItem.size())
      return *_vItem[index];
  }

  int GetSize() {
    return (int)_vItem.size();
  }

  void accept(Visitor &v)
  {
    v.visit(this);
  }

private:
  std::vector<Item*> _vItem;
  std::vector<Menu *> _vMenu;
};

#endif
