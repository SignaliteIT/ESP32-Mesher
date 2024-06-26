#include "BuildType.h"

const char *toString(BuildType aBuildType)
{
  switch (aBuildType)
  {
  case BuildType::development:
    return "development";
    break;

  case BuildType::production:
    return "production";
    break;

  case BuildType::integrationTest:
    return "integrationTest";
    break;

  default:
    return "unknown";
    break;
  }
}
