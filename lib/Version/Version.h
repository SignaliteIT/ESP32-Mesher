#pragma once

#include "stdint.h"
#include "BuildType.h"
#include "BuildEnvironment.h"

class Version
{
public:
  Version() = delete;
  static uint8_t getIsVersionMajor() { return isVersionMajor; }
  static uint8_t getIsVersionMinor() { return isVersionMinor; }
  static uint8_t getIsVersionPatch() { return isVersionPatch; }
  static const char *getIsVersionHash() { return isVersionHash; }
  static BuildType getBuildType() { return buildType; }
  static BuildEnvironment getBuildEnvironment() { return buildEnvironment; }
  static void setIsVersion();
  static const char *getIsVersionAsString() { return isVersionString; }

private:
  static uint8_t isVersionMajor;
  static uint8_t isVersionMinor;
  static uint8_t isVersionPatch;
  static constexpr uint8_t maxHashStringLength{8U};
  static char isVersionHash[maxHashStringLength];

  static BuildType buildType;
  static BuildEnvironment buildEnvironment;

  static constexpr uint8_t maxVersionStringLength{32U};
  static char isVersionString[maxVersionStringLength];
};
