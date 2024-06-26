#pragma once
#include <stdint.h>

enum class BuildEnvironment
{
  unknown,
  local,
  ci
};

const char *toString(BuildEnvironment aBuildEnvironment);
