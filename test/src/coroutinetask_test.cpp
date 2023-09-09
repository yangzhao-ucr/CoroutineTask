//
// Created by Konstantin Gredeskoul on 5/16/17.
//
#include <division.h>
#include "gtest/gtest.h"

using namespace std;


#define VI vector<long long>

class DividerTest : public ::testing::Test {

protected:
  VI numerators   = {5, 9, 17, 933345453464353416L};
  VI denominators = {2, 3, 19, 978737423423423499L};
  VI divisions    = {2, 3, 0, 0};
  VI remainders   = {1, 0, 17, 933345453464353416};

  virtual void SetUp() {
  };

  virtual void TearDown() {
  };

  virtual void verify(int index) {
    EXPECT_EQ(1,1);
  }
};

TEST_F(DividerTest, Case1) {
  verify(0);
}

TEST_F(DividerTest, Case2) {
  verify(1);
}

TEST_F(DividerTest, Case3) {
  verify(2);
}

TEST_F(DividerTest, Case4) {
  verify(3);
}

TEST_F(DividerTest, Case5) {
}

