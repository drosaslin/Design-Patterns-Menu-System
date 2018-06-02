#ifndef BASE_MENU_H
#define BASE_MENU_H

#include "iterator.h"
#include <string>

class BaseMenu {
public:
  BaseMenu(std::string newName) : _name(newName)
  {
  }

  virtual bool isVegetarian() {
    return _isVegetarian;
  }

  void setIsVegatarian(bool isVegetarian) {
      _isVegetarian = isVegetarian;
  }

  std::string getName() {
    return _name;
  }

  virtual void addIngredient(std::string newIngredient) {
    throw std::invalid_argument("Invalid Operation");
  }

  virtual void deleteItem(std::string item) {
    throw std::invalid_argument("Invalid Operation");
  }

  virtual void addItem(BaseMenu* item) {
    throw std::invalid_argument("Invalid Operation");
  }

  virtual void removeIngredient(std::string ingredient) {
    throw std::invalid_argument("Invalid Operation");
  }

  virtual bool hasIngredient(std::string ingredient) {
    throw std::invalid_argument("Invalid Operation");
  }

  virtual BaseMenu* getItem(std::string name) {
    throw std::invalid_argument("Invalid Operation");
    return nullptr;
  }

  virtual Iterator<BaseMenu*>* createIterator() {
   return new NullIterator<BaseMenu*>;
  }

  virtual bool isVegetarian(BaseMenu* item) {
    throw std::invalid_argument("Invalid Operation");
    return false;
  }

  virtual std::string getDescription() = 0;

  virtual double getPrice() = 0;

private:
  std::string _name;
  bool _isVegetarian;
};

#endif
