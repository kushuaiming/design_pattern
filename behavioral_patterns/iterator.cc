// Intent: Provide a way to access the elements of an aggregate object
// sequentially without exposing its underlying representation.
template <typename Item>
class List {
 public:
  List();
  long Count() const;
  Item& Get(long index) const;
};

template <typename Item>
class Iterator {
 public:
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() const = 0;
  virtual Item CurrentItem() const = 0;

 protected:
  Iterator();
};

template <typename Item>
class ListIterator : public Iterator<Item> {
 public:
  ListIterator(const List<Item>* a_list);
  void First();
  void Next();
  bool IsDone() const;
  Item CurrentItem() const;

 private:
  const List<Item>* list_;
  long current_;
};

template <typename Item>
ListIterator<Item>::ListIterator(const List<Item>* a_list)
    : list_(a_list), current_(0) {}

template <typename Item>
void ListIterator<Item>::First() {
  current_ = 0;
}

template <typename Item>
void ListIterator<Item>::Next() {
  current_++;
}

template <typename Item>
bool ListIterator<Item>::IsDone() const {
  return current_ >= list_->Count();
}

template <typename Item>
Item ListIterator<Item>::CurrentItem() const {
  if (IsDone()) {
    throw;
  }
  return list_->Get(current_);
}