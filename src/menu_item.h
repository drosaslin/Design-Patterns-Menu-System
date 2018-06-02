#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <string>
#include <vector>
#include <iostream>

class MenuItem : public BaseMenu {
public:
  MenuItem(std::string newName, double price = 0.00, bool isVeg = "false")
      :BaseMenu(newName)
  {
      _isVegetarian = isVeg;
      _price = price;
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

  bool isVegetarian(){
    return _isVegetarian;
  }

  void setVegetarian(bool isVeg){
    _isVegetarian = isVeg;
  }

  std::string getIngredients(){
    std::string ingredients;
    int size = _ingredients.size();
    for(int n = 0; n < size; n++){
      ingredients +=  _ingredients[n];
      if(n != size - 1) ingredients += ", ";
    }
    return ingredients;
  }

  void removeIngredient(std::string ingredient) {
    int size = _ingredients.size();
    for (int n = 0; n < size; n++){
      if (_ingredients[n] == ingredient)
        _ingredients.erase(_ingredients.begin() + n);
    }
  }

  double getPrice(){
    return _price;
  }

  void setPrice(double newPrice){
    _price = newPrice;
  }

private:
  std::vector<std::string> _ingredients;
  double _fat, _carbs, _protein, _sugar, _sodium;
  double _price;
  bool _isVegetarian;
};

#endif
