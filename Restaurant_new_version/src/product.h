#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
  Product(std::string newName, std::string newDescription)
    :_name(newName), _description(newDescription)
  {}

  std::string GetName() {
    return _name;
  }

  std::string GetDescription() {
    return _description;
  }

  bool GetIsVegetarian() {
    return isVegetarian;
  }

  void SetName(std::string newName) {
    _name = newName;
  }

  void SetDescription(std::string newDescription) {
    _description = newDescription;
  }

  void setIsVegetarian(bool flag) {
    isVegetarian = flag;
  }

private:
  std::string _name;
  std::string _description;
  bool isVegetarian;
};

#endif
