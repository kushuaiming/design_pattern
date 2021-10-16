#include <iterator>

class Equipment {
 public:
  virtual ~Equipment();

  const char* Name() { return _name; }

  virtual Watt Power();
  virtual Currency NetPrice();
  virtual Currency DiscountPrice();

  virtual void Add(Equipment*);
  virtual void Remove(Equipment*);
  virtual std::iterator<std::input_iterator_tag, Equipment*> CreateIterator();

 protected:
  Equipment(const char*);

 private:
  const char* _name;
};
