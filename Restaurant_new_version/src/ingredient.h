#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <iostream>
#include <string>
#include "product.h"
using namespace std;

class Ingredient:public product
{
public:
  Ingredient()
  {

  }
  Ingredient(string name, string description, double num1, double num2, double num3, double w, bool flag)
  :_name(name), _description(description), _perProtein(num1), _perFat(num2), _perCarbonhydrates(num3), _weight(w), _isVegetarian(flag)
  {

  }
  string GetName()
  {
    return _name;
  }
  double GetProtein()
  {
    return _perProtein * _weight;
  }
  double GetFat()
  {
    return _perFat * _weight;
  }
  double GetCarbohydrates()
  {
    return _perCarbonhydrates * _weight;
  }
  double GetCalorie()
  {
    return 4000 * (GetProtein() + GetCarbohydrates()) + 9000 * GetFat();
  }
  double GetWeight()
  {
    return _weight;
  }
  bool IsVegetarian()
  {
    return _isVegetarian
  }
private:
  string _name;
  double _perProtein, _perFat, _perCarbonhydrates, _calorie, _weight;
  bool _isVegetarian;
};

#endif
