#include "list.h"

template <class Item>
class Iterator {
 public:
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() const = 0;
  virtual Item CurrentItem() const = 0;

 protected:
  Iterator();
};

template <class Item>
class ListIterator : public Iterator<Item> {
 public:
  ListIterator(const List<Item>* aList);

  virtual void First();
  virtual void Next();
  virtual bool IsDone() const;
  virtual Item CurrentItem() const;

 private:
  const List<Item>* _list;
  long _current;
};
