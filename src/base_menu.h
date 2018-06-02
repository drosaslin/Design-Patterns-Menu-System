#ifndef BASE_MENU_H
#define BASE_MENU_H

#include<string>

class BaseMenu {
public:
  BaseMenu(std::string newName) : _name(newName)
  {
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

  virtual bool isVegetarian(BaseMenu* item) {
    throw std::invalid_argument("Invalid Operation");
    return false;
  }

  virtual std::string getName() {
    return _name;
  }

  virtual std::string getDescription() = 0;

  virtual double getPrice() = 0;


private:
  std::string _name;
};

#endif
