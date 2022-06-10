template <class Item>
class ListNode {
 private:
  ListNode<Item>* next_node_;
  ListNode<Item>* prev_node_;
};

template <class Item>
class List {
 public:
  List(long size = DEFAULT_LIST_CAPACITY);
  List(List&);
  ~List();
  List& operator=(const List&);

  long Count() const;
  Item& Get(long index) const;
  Item& First() const;
  Item& Last() const;
  bool Includes(const Item&) const;

  void Append(const Item&);
  void Prepend(const Item&);

  void Remove(const Item&);
  void RemoveLast();
  void RemoveFirst();
  void RemoveAll();
};
