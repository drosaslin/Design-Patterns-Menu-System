#include "full_menu.h"
#include "category.h"
#include "iterator.h"
#include "visitor.h"
#include <string>
#include <vector>

  FullMenu::FullMenu(){
  }

  FullMenu::FullMenu(string name, string description)
    :Menu(name, description)
  {
  }

  void FullMenu::AddCategory(Category& cat){
    _vCategory.push_back(cat);
  }

  void FullMenu::DelCategory(string name){
    for(int n = 0; n < _vCategory.size(); n++){
      if (_vCategory[n].GetName() == name){
        _vCategory.erase(_vCategory.begin()+n);
        return;
      }
    }
  }

  void FullMenu::DisplayCategories() {
    int n;
    Iterator<Category>* it = createIterator();
    for(n = 1, it->first(); !it->isDone(); it->next(), n++) {
      cout << n << ". " << it->currentItem().GetName() << endl;
    }
  }

  void FullMenu::ShowMenu(){
    Iterator<Category>* it = createIterator();
    std::cout << GetName() << std::endl;
    for(it->first(); !it->isDone(); it->next()) {
      std::cout << std::endl << it->currentItem().GetName() << std::endl;
      it->currentItem().ShowMenu();
    }
  }

  Category& FullMenu::GetCategory(int index) {
    if(index >= 0 && index <= _vCategory.size())
      return _vCategory[index];
  }

  int FullMenu::GetSize() {
    return (int)_vCategory.size();
  }

  Iterator<Category>* FullMenu::createIterator()
  {
    return new FullMenuIterator(this);
  }

  void FullMenu::accept(Visitor &v)
  {
    v.visit(this);
  }
//
// private:
//   std::vector<Category> _vCategory;
