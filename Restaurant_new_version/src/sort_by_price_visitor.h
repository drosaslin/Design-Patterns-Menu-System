#ifndef SORT_BY_PRICE_VISITOR_H
#define SORT_BY_PRICE_VISITOR_H

#include <vector>
#include "visitor.h"
#include "menu.h"
#include "full_menu.h"
#include "category.h"
#include "iterator.h"
using namespace std;

class SortByPriceVisitor:public Visitor
{
public:
  SortByPriceVisitor():_maxPrice(0)
  {

  }
  void visit(FullMenu *fm)
  {
    Iterator<FullMenu *> *it = fm->createIterator();
    for (it->first(); !it->isDone(); it->next())
    {
      it->currentItem()->accept(*this);
    }
  }
  void visit(Category *c)
  {
    Iterator<FullMenu *> *it = c->createIterator();
    for (it->first();!it->isDone();it->next())
    {
      if(it->currentItem()->GetName()==name)
      {
        _vItem.erase(it->currentItem());
        break;
      }
    }
  }
private:
  double _maxPrice;
  vector<Category> _vCategory;
  vector<Item *> _vItem, _result;
};

#endif
