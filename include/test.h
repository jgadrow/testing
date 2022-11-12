#if !defined TEST_H
#define TEST_H

#include <string>
using std::string;
typedef bool (*tFun)();
class TestPrivate;

class Test {
public:
  Test(string name, tFun handler);
  Test(const Test &old);
  ~Test();
  string getName();
  bool inactive() const;
  bool run();
  void skip();
private:
  TestPrivate* _mData;
};

#endif

