#ifndef BASE_MENU_H
#define BASE_MENU_H

#include "iterator.h"
#include <string>

class BaseMenu {
public:
  BaseMenu(std::string newName, std::string newDescr) : _name(newName), _description(newDescr)
  {
  }

  std::string getName() {
    return _name;
  }

  virtual void setIsVegetarian(bool) {
    throw std::invalid_argument("Invalid Operation");
  }

  std::string getDescription() {
    return _description;
  }

  void setDescription(std::string newDescription) {
    _description = newDescription;
  }

  virtual double getPrice() = 0;

  virtual bool isVegetarian() = 0;

<<<<<<< HEAD
  virtual void setIsVegetarian(bool isVeg) {}

=======
>>>>>>> deb778127e7a65b2ce8cc41e18a29d24966c2b76
  virtual void setPrice(double) {}

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
