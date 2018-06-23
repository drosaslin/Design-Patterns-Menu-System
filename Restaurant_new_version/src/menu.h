#ifndef MENU_H
#define MENU_H

#include <string>
class Visitor;
class SortByPriceVisitor;

using namespace std;

class Menu {
public:
  Menu();
  Menu(std::string newName, std::string newDescription);

  std::string GetName();

  std::string GetDescription();

  void SetName(std::string newName);

  void SetDescription(std::string newDescription);

  virtual void update(std::string itemName);

  virtual void accept(Visitor &v);

private:
  std::string _name;
  std::string _description;
};

#endif
