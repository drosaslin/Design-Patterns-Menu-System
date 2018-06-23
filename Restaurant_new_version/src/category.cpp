#include "category.h"
#include "item.h"
#include "visitor.h"
//#include "visitor.h"
//#include "sort_by_price_visitor.h"
// #include "sort_by_calorie_visitor.h"
#include <string>
#include <vector>

  Category::Category(){}

  Category::Category(std::string name, std::string description)
    :Menu(name, description)
  {
  }

  void Category::AddItem(Item *item){
    _vItem.push_back(*item);
    item->AddObserver(this);
  }

  void Category::DelItem(std::string name){
    for(int n = 0; n < _vItem.size(); n++){
      if (_vItem[n].GetName() == name){
        //cout << _vItem[n].GetName() << "deleted\n";
        _vItem.erase(_vItem.begin()+n);
        return;
      }
    }
  }

  void Category::ShowMenu(){
    Iterator<Item>* it = createIterator();
    for(it->first(); !it->isDone(); it->next()) {
      std::cout << it->currentItem().GetProductCode() << " " << it->currentItem().GetName() << "     " << it->currentItem().GetDescription() << "    " << fixed << setprecision(2) << it->currentItem().GetPrice() << std::endl;
    }
  }

  void Category::update(string itemName) {
      DelItem(itemName);
  }

  Item Category::GetItem(int index) {
    if(index >= 0 && index <= _vItem.size())
      return _vItem[index];
  }

  int Category::GetSize() {
    return (int)_vItem.size();
  }

  Iterator<Item>* Category::createIterator() {
    return new CategoryIterator(this);
  }

  void Category::accept(Visitor &v)
  {
    v.visit(this);
  }
//
// private:
//   std::vector<Item> _vItem;
