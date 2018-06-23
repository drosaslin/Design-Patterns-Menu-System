#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
public:
  Menu(){}

  Menu(std::string newName, std::string newDescription)
    :_name(newName), _description(newDescription)
  {}

  std::string GetName() {
    return _name;
  }

  std::string GetDescription() {
    return _description;
  }

  void SetName(std::string newName) {
    _name = newName;
  }

  void SetDescription(std::string newDescription) {
    _description = newDescription;
  }

  virtual void update(std::string itemName){
  }

private:
  std::string _name;
  std::string _description;

};

#endif
