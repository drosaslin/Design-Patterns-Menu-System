#ifndef VISITOR_H
#define VISITOR_H

#include <string>
#include "menu.h"
#include "category.h"
#include "full_menu.h"
class Menu;
class Category;
class FullMenu;

class Visitor {
public:
  virtual void visit(FullMenu *m) = 0;
  virtual void visit(Category *c) = 0;
  //virtual std::string getResult() = 0;
};

#endif
