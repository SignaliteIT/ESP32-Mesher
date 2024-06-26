
#ifdef ARDUINO
#include "Arduino.h"
#endif
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

// WARNING!!! PLEASE REMOVE UNNECESSARY MAIN IMPLEMENTATIONS //

#ifdef ARDUINO
/**
 * For Arduino framework
 */
void setup()
{
  // Wait ~2 seconds before the Unity test runner
  // establishes connection with a board Serial interface
  delay(2000);

  runUnityTests();
}
void loop() {}

#else

/**
 * For native dev-platform or for some embedded frameworks
 */
int main()
{
  return runUnityTests();
}

#endif

// /**
//  * For ESP-IDF framework
//  */
// void app_main()
// {
//   runUnityTests();
// }
