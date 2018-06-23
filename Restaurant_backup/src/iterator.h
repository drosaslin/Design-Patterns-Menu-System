#ifndef ITERATOR_H
#define ITERATOR_H

template <class Object>
class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual bool isDone() const = 0;
  virtual Object currentItem() = 0;
};

template <class Object>
class NullIterator : public Iterator<Object> {
public:
  void first() {}
  void next() {}
  bool isDone() const {return true;}
  Object currentItem() {return Object();}
};
#endif
