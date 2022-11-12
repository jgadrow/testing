#include <string>
#include "../include/test.h"
#include "./private-header/test_p.h"
using std::string;
typedef bool (*tFun)();

Test::Test(string name, tFun handler) {
  _mData = new TestPrivate(name, handler);
}

Test::Test(const Test &old) {
  _mData = new TestPrivate(old._mData->name, old._mData->handler);

  if (old.inactive()) {
    skip();
  }
}

Test::~Test() {
  delete _mData;
}

string Test::getName() {
  return _mData->name;
}

bool Test::inactive() const {
  return !_mData->active;
}

bool Test::run() {
  return _mData->handler();
}

void Test::skip() {
  _mData->active = false;
}

TestPrivate::TestPrivate(
  string n,
  tFun h
) : name(n), handler(h) {
  active = true;
}

