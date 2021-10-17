class MazeFactory {
 public:
  static MazeFactory* Instance();
  // existing interface goes here
 protected:
  MazeFactory() {}

 private:
  static MazeFactory* _instance;
};
