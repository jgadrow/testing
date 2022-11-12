#include <iostream>
#include <string>
#include "../include/test-runner.h"
#include "./private-header/test-runner_p.h"
using std::cout;
using std::endl;
using std::string;

TestRunner::TestRunner() {
  _mData = new TestRunnerPrivate();
}

TestRunner::~TestRunner() {
  delete _mData;
  _mData = NULL;
}

void TestRunner::registerTest(Test &test) {
  _mData->tests.push_back(test);
}

int TestRunner::runTests() {
  if (0 == _mData->tests.size()) {
    cout << "No Tests were defined." << endl;
    return 0;
  }

  for (; !_mData->tests.empty(); _mData->tests.pop_front()) {
    _mData->beginTest(_mData->tests.front().getName());

    if (_mData->tests.front().inactive()) {
      _mData->skipTest();
      continue;
    }

    if (!_mData->tests.front().run()) {
      _mData->failTest();
      _mData->status = 1;
      continue;
    }

    _mData->passTest();
  }

  return _mData->status;
}

void TestRunnerPrivate::beginTest(string test) {
  cout << test << "::";
}

void TestRunnerPrivate::failTest() {
  cout << "\033[91mfailed\033[0m" << endl;
}

void TestRunnerPrivate::passTest() {
  cout << "\033[92mpassed\033[0m" << endl;
}

void TestRunnerPrivate::skipTest() {
  cout << "\033[33mskipped\033[0m" << endl;
}

