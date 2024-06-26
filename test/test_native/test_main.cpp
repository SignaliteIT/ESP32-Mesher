#include "unity.h"

void setUp(void)
{
  // set stuff up here
}

void tearDown(void)
{
  // clean stuff up here
}

void test_self_tests(void)
{
  TEST_ASSERT_EQUAL(5, 5);
  TEST_ASSERT_EQUAL(78465, 78465);
}

int runUnityTests(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_self_tests);

  return UNITY_END();
}

int main()
{
  return runUnityTests();
}
