#pragma once
#include <stdint.h>

enum class BuildType
{
  unknown,
  development,
  production,
  integrationTest,
};

const char *toString(BuildType aBuildType);
