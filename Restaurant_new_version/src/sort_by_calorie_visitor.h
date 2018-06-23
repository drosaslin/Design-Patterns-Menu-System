#ifndef SORT_BY_CALORIE_VISITOR_H
#define SORT_BY_CALORIE_VISITOR_H

#include <vector>
#include "menu.h"
#include "full_menu.h"
#include "category.h"
#include "iterator.h"
class Menu;
class FullMenu;
class Category;

using namespace std;

class SortByCalorieVisitor:public Visitor
{
public:
  SortByCalorieVisitor():_maxPrice(0),_index(0)
  {
  }
  void visit(FullMenu *fm)
  {
    Iterator<Category> *it = fm->createIterator();
    for (it->first(); !it->isDone(); it->next())
    {
      it->currentItem()->accept(*this);
    }
  }
  void visit(Category *c)
  {
    _temp.clear();
    for (int i=0;i<c->GetSize();i++)
    {
      _maxCalorie = 0;
      for (int j=0;j<c->GetSize();j++)
      {
        flag=false;
        for (int k = 0; k<_temp.size();k++)
        {
          if (j==_temp[k])
          {
            flag=true;
            break;
          }
        }
        if (c->GetItem(j).GetCalorie()>_maxPrice && !flag)
        {
          _maxCalorie=c->GetItem(j)->GetPrice()
          _index=j;
        }
      }
      _temp.push_back(_index);
    }
    for (int k = 0; k<_temp.size();k++)
    {
      cout<<c->GetItem(_temp[k])->GetName()<<"\t"<<c->GetItem(_temp[k])->GetCalorie()<<endl;
    }
  }
private:
  int _index;
  double _maxCalorie;
  bool flag;
  vector<int> _temp;
  vector<Category> _vCategory;
};

#endif
