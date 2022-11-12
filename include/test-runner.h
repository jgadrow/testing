#if !defined TEST_RUNNER_H
#define TEST_RUNNER_H

#include "test.h"
class TestRunnerPrivate;

class TestRunner {
public:
  TestRunner();
  ~TestRunner();
  int getStatus();
  void registerTest(Test &test);
  int runTests();
  void setStatus(int status);
private:
  TestRunnerPrivate* _mData;
};

#endif

