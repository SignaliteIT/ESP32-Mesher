#include "BuildEnvironment.h"

const char *toString(BuildEnvironment aBuildEnvironment)
{
  switch (aBuildEnvironment)
  {
  case BuildEnvironment::local:
    return "local";
    break;

  case BuildEnvironment::ci:
    return "ci";
    break;

  default:
    return "unknown";
    break;
  }
}
