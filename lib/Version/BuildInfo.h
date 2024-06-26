#pragma once
#include "BuildType.h"
#include "BuildEnvironment.h"

class BuildInfo
{
public:
  static const BuildEnvironment buildEnvironment;
  static const BuildType buildType;
  static const int mainVersionDigit;  //
  static const int minorVersionDigit; //
  static const int patchVersionDigit; //
  static const char *lastCommitTag;   //
  static const char *buildTimeStamp;  //

  static void dump();
};
