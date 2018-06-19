#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <iostream>
#include <string>
#include "product.h"
using namespace std;

class Ingredient : public Product
{
public:
  Ingredient()
  {
  }

  Ingredient(string name, string description, double perProtein, double perFat, double perCarbohydrates, double weight, bool flag)
  :Product(name, description), _perProtein(perProtein), _perFat(perFat), _perCarbohydrates(perCarbohydrates), _weight(weight), _isVegetarian(flag)
  {

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
    return _perCarbohydrates * _weight;
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
    return _isVegetarian;
  }
private:
  string _name;
  double _perProtein, _perFat, _perCarbohydrates, _calorie, _weight;
  bool _isVegetarian;
};

#endif
