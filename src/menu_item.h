#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <string>
#include <vector>
#include <iostream>

class MenuItem : public BaseMenu {
public:
  MenuItem(std::string newName, std::string description = "no description available", bool isVegetarian = false) : BaseMenu(newName)
  {
      _description = description;
      _isVegetarian = isVegetarian;
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

  bool isVegetarian (){
    return _isVegetarian;
  }

  void addDescription(std::string newDescription){
    _description = newDescription;
  }

  std::string getDescription(){
    return _description;
  }

  void getIngredients(){
    for(int n = 0; n < _ingredients.size(); n++){
      std::cout << _ingredients[n] << std::endl;
    }
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
  std::string _description;
  bool _isVegetarian;
};

#endif
