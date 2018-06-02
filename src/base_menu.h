#ifndef BASE_MENU_H
#define BASE_MENU_H

#include<string>

class BaseMenu {
public:
  BaseMenu(std::string newName) : _name(newName)
  {
  }

  virtual void addIngredient(std::string newIngredient) {
    //throw exception
  }

  virtual bool hasIngredient(std::string ingredient) {
    //throw exception
  }

  virtual std::string getName() {
    return _name;
  }

  virtual void removeIngredient(std::string ingredient) {
    //throw exception
  }

private:
  std::string _name;
};

#endif
