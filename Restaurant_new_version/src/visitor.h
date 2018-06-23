#ifndef VISITOR_H
#define VISITOR_H

#include <string>
class Menu;
class Category;

class Visitor {
public:
  virtual void visit(Menu *m) = 0;
  virtual void visit(Category *c) = 0;
  virtual std::string getResult() = 0;
};

#endif
