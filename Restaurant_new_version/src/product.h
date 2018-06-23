#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
  Product()
  {
  }

  Product(std::string newName, std::string newDescription, std::string productCode)
    :_name(newName), _description(newDescription), _productCode(productCode)
  {}

  std::string GetName() {
    return _name;
  }

  std::string GetDescription() {
    return _description;
  }

  std::string GetProductCode(){
    return _productCode;
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
  std::string _name, _description, _productCode;
  bool isVegetarian;
};

#endif
