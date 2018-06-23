#include "menu.h"
#include "visitor.h"
#include "sort_by_price_visitor.h"
#include <string>

  Menu::Menu(){}

  Menu::Menu(std::string newName, std::string newDescription)
    :_name(newName), _description(newDescription)
  {}

  std::string Menu::GetName() {
    return _name;
  }

  std::string Menu::GetDescription() {
    return _description;
  }

  void Menu::SetName(std::string newName) {
    _name = newName;
  }

  void Menu::SetDescription(std::string newDescription) {
    _description = newDescription;
  }

  void Menu::update(std::string itemName){
  }

  void Menu::accept(Visitor &v){
    //do nothing
  }

// private:
//   std::string _name;
//   std::string _description;
