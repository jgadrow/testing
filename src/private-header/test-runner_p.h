#if !defined TEST_RUNNER_P_H
#define TEST_RUNNER_P_H

#include <string>
#include <list>
using std::list;
using std::string;

class TestRunnerPrivate {
public:
  void beginTest(string test);
  void failTest();
  void passTest();
  void skipTest();
  int status;
  list<Test> tests;
};

#endif

