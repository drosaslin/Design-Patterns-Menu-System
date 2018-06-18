#ifndef FULL_MENU_H
#define FULL_MENU_H

#include "menu.h"
#include "category.h"
#include <string>

class FullMenu: public Menu{
public:
  FullMenu(string name, string description){
    Menu(name, description);
  }

  void AddCategory(Category *cat){
    _vCategory.push_back(cat);
  }

  void DelCategory(string name){
    for(int n = 0; n < _vCategory.size(); n++){
        if (_vCategory[n]->name() == name){
          _vCategory.erase(_vCategory.begin()+n);
          return;
        }
    }
  }

  void ShowMenu(){
    for(int n = 0; n < _vCategory.size(); n++){
      _vCategory[n].ShowMenu();
      std::cout << std::endl; 
    }
  }

private:
  std::vector<Category*> _vCategory;
};

#endif
