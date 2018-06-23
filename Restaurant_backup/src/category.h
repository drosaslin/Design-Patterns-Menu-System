#ifndef CATEGORY_H
#define CATEGORY_H

#include "menu.h"
#include "item.h"
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
        cout << _vItem[n].GetName() << "deleted\n";
        _vItem.erase(_vItem.begin()+n);
        return;
      }
    }
  }

  void ShowMenu(){
    cout << endl;
    Iterator<Item>* it = createIterator();
    // for(it->first(); !it->isDone(); it->next()) {
    //   std::cout << GetName() << " " << it->currentItem().GetName() << " " << it->currentItem().GetDescription() << " " << it->currentItem().GetPrice() << std::endl;
    // }
    for(int n = 0; n < _vItem.size(); n++){
      std::cout << GetName() << " " << _vItem[n].GetName() << " " << _vItem[n].GetDescription() << " " << _vItem[n].GetPrice() << std::endl;
      }
  }

  void update(string itemName) {
      cout << _vItem.size() << endl;
      DelItem(itemName);
      cout << _vItem.size() << endl;
      // Iterator<Item*>* it = createIterator();
      // for(it->first(); !it->isDone(); it->next()) {
      //   std::cout << it->currentItem()->GetName() << " " << it->currentItem()->GetDescription() << " " << it->currentItem()->GetPrice() << std::endl;
      // }
      // cout << "updating" << endl;
      // Iterator<Item*>* it = createIterator();
      // int n;
      // for(n = 0, it->first(); !it->isDone(); n++, it->next()) {
      //   cout << it->currentItem()->GetName() << endl;
      //   if(it->currentItem()->GetName() == itemName) {
      //     _vItem.erase(_vItem.begin() + n);
      //     break;
      //   }
      // }
      // for(int n = _vItem.size(); n >= 0; n--) {
      //   cout << _vItem[n].GetName() << endl;
      //   if(_vItem[n].GetName() == itemName) {
      //     _vItem.erase(_vItem.begin() + n);
      //     break;
      //   }
      // }
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

private:
  std::vector<Item> _vItem;
};

#endif
