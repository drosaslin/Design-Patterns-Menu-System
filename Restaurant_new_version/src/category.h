#ifndef CATEGORY_H
#define CATEGORY_H

#include "menu.h"
#include "item.h"
#include <string>
#include <vector>

class Category : public Menu{
public:
  Category(){}

  Category(std::string name, std::string description)
    :Menu(name, description)
  {
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

private:
  std::vector<Item*> _vItem;
};

#endif
