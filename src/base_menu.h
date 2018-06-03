#ifndef BASE_MENU_H
#define BASE_MENU_H

#include "iterator.h"
#include <string>

class BaseMenu {
public:
  BaseMenu(std::string newName) : _name(newName)
  {
  }

  std::string getName() {
    return _name;
  }

  //void setIsVegatarian(bool isVegetarian) {
  //     _isVegetarian = isVegetarian;
  // }

  std::string getDescription() {
    return _description;
  }

  void setDescription(std::string newDescription) {
    _description = newDescription;
  }

  virtual double getPrice() = 0;

  virtual bool isVegetarian() = 0;

  virtual void setPrice() {}

  virtual std::string getIngredients() {
    throw std::invalid_argument("Invalid Operation");
    return "";
  }

  virtual bool isVegetarian(BaseMenu* item) {
    throw std::invalid_argument("Invalid Operation");
    return false;
  }

  virtual void addIngredient(std::string newIngredient) {
    throw std::invalid_argument("Invalid Operation");
  }

  virtual void delItem(std::string item) {
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

private:
  std::string _name, _description;
  bool _isVegetarian;
};

#endif
