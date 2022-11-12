#if !defined TEST_P_H
#define TEST_P_H

#include <string>
using std::string;
typedef bool (*tFun)();

class TestPrivate {
public:
  TestPrivate(string name, tFun handler);
  bool active;
  const tFun handler;
  const string name;
};

#endif

