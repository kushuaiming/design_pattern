#include "list.h"
namespace {
static const long DEFAULT_LIST_CAPACITY = 1000;
} // namespac<Item>

template <class Item>
List<Item>::List(long size = DEFAULT_LIST_CAPACITY) {}
template <class Item>
List<Item>::List(List&) {}
template <class Item>
List<Item>::~List() {}

template <class Item>
long List<Item>::Count() const {}
template <class Item>
Item& List<Item>::Get(long index) const {}
template <class Item>
Item& List<Item>::First() const {}
template <class Item>
Item& List<Item>::Last() const {}
template <class Item>
bool List<Item>::Includes(const Item&) const {}

template <class Item>
void List<Item>::Append(const Item&) {}
template <class Item>
void List<Item>::Prepend(const Item&) {}

template <class Item>
void List<Item>::Remove(const Item&) {}
template <class Item>
void List<Item>::RemoveLast() {}
template <class Item>
void List<Item>::RemoveFirst() {}
template <class Item>
void List<Item>::RemoveAll() {}