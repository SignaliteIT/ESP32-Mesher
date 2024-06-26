#include "Version.h"
#include "BuildInfo.h"
#include <stdio.h>
#include <string.h>

uint8_t Version::isVersionMajor{0};
uint8_t Version::isVersionMinor{0};
uint8_t Version::isVersionPatch{0};

BuildType Version::buildType{BuildType::unknown};
BuildEnvironment Version::buildEnvironment{BuildEnvironment::unknown};

char Version::isVersionHash[maxHashStringLength]{};
char Version::isVersionString[maxVersionStringLength]{};

void Version::setIsVersion()
{
  isVersionMajor = BuildInfo::mainVersionDigit;
  isVersionMinor = BuildInfo::minorVersionDigit;
  isVersionPatch = BuildInfo::patchVersionDigit;
  strncpy(isVersionHash, BuildInfo::lastCommitTag, maxHashStringLength);
  buildType = BuildInfo::buildType;
  buildEnvironment = BuildInfo::buildEnvironment;

  snprintf(isVersionString, maxVersionStringLength, "v%d.%d.%d-%s", isVersionMajor, isVersionMinor, isVersionPatch, isVersionHash);
}
