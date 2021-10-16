class Equipment {
 public:
  virtual ~Equipment();

  const char* Name() { return _name; }

  virtual Watt Power();
  virtual Currency NetPrice();
  virtual Currency DiscountPrice();

  virtual void Accept(EquipmentVisitor&);

 protected:
  Equipment(const char*);

 private:
  const char* _name;
};

class EquipmentVisitor {
 public:
  virtual ~EquipmentVisitor();

  virtual void VisitFloppyDisk(FloppyDisk*);
  virtual void VisitCard(Card*);
  virtual void VisitChassis(Chassis*);
  virtual void VisitBus(Bus*);

 protected:
  EquipmentVisitor();
};
