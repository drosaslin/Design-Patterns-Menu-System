#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <string>
#include <vector>
#include <iostream>

class MenuItem : public BaseMenu {
public:
  MenuItem(std::string newName) : BaseMenu(newName)
  {
  }

  void addIngredient(std::string newIngredient) {
    _ingredients.push_back(newIngredient);
  }

  bool hasIngredient(std::string ingredient) {
    int size = _ingredients.size();
    for (int n = 0; n < size; n++)
      if (_ingredients[n] == ingredient) return true;

    return false;
  }

  void removeIngredient(std::string ingredient) {
    int size = _ingredients.size();
    for (int n = 0; n < size; n++){
      if (_ingredients[n] == ingredient) 
        _ingredients.erase(_ingredients.begin() + n);
    }
  }

private:
  std::vector<std::string> _ingredients;
};

#endif
