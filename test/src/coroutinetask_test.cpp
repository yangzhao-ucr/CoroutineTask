#include "coroutine_task.h"

#include "gtest/gtest.h"

using namespace std;

class CoroutineTask_Test : public ::testing::Test {

protected:
  coroutine_task::Coroutine_Task<int> func1_ut(int i)
  {
    if(i<=0) co_return 0;
    // cout << "i = " << i <<endl;
    int r = i+ (co_await func1_ut(i-1));
    // cout << "r = " << i <<endl;
    co_return r;
  }

  virtual void SetUp() {
  };

  virtual void TearDown() {
  };

  virtual void verify(int expected, int actual) {
    EXPECT_EQ(expected, actual);
  }
};

TEST_F(CoroutineTask_Test, recursive_down) 
{
  auto t = func1_ut(10);
  t.Resume(); 
  verify(t.GetReturnValue(), 55);
}
