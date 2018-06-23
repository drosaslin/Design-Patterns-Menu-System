#ifndef SORT_BY_NAME_VISITOR_H
#define SORT_BY_NAME_VISITOR_H

#include <vector>
#include <string>
#include "menu.h"
#include "full_menu.h"
#include "category.h"
#include "iterator.h"
class Menu;
class FullMenu;
class Category;

using namespace std;

class SortByNameVisitor:public Visitor
{
public:
  SortByNameVisitor()
  {
  }
  void visit(FullMenu *fm)
  {
    Iterator<Category> *it = fm->createIterator();
    for (it->first(); !it->isDone(); it->next())
    {
      cout << it->currentItem().GetName() << endl;
      it->currentItem().accept(*this);
    }
  }

  void visit(Category *c)
  {
    Iterator<Item>* it = c->createIterator();
    for(it->first(); !it->isDone(); it->next())
      items.push_back(it->currentItem());

    BubbleSort();
    for(int n = 0; n < items.size(); n++)
      std::cout << items[n].GetProductCode() << " " << items[n].GetName() << "     " << items[n].GetDescription() << "    " << fixed << setprecision(2) << items[n].GetPrice() << std::endl;

    cout << endl;
    items.clear();
  }

  void BubbleSort()
  {
    int size = items.size();
    for(int n = 0; n < size; n++)
    {
      for(int i = 1; i < size - n; i++)
      {
        if(items[i].GetName().compare(items[i-1].GetName()) < 0)
          Swap(i-1, i);
      }
    }
  }

  void Swap(int index1, int index2)
  {
    Item temp = items[index1];
    items[index1] = items[index2];
    items[index2] = temp;
  }

private:
  vector<Item> items;
};

#endif
