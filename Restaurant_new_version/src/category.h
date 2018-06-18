#ifndef CATEGORY_H
#define CATEGORY_H

#include "menu.h"
#include "item.h"
#include <string>

class Category : public menu{
public:
  Category(string name, string description){
    Menu(name, description);
  }

  void AddItem(Item *item){
    _vItem.push_back(item);
  }

  void DelItem(string name){
    for(int n = 0; n < _vItem.size(); n++){
        if (_vItem[n]->name() == name){
          _vItem.erase(_vItem.begin()+n);
          return;
        }
    }
  }

  void ShowMenu(){
    for(int n = 0; n < _vItem.size(); n++){
        std::cout << _vItem.name() << " " <<_vItem.description() << " " << _vItem.price() << std::endl;
    }
  }

private:
  std::vector<Item*> _vItem;
};

#endif
