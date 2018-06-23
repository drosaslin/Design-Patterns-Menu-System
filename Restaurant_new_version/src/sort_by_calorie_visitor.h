#ifndef SORT_BY_Calorie_VISITOR_H
#define SORT_BY_Calorie_VISITOR_H

#include "visitor.h"
#include "menu.h"
#include "full_menu.h"
#include "category.h"

class SortByPriceVisitor:public Visitor
{
public:
private:
  double _maxPrice;
};

#endif
