#ifndef RECETTE

#include <Version.h>
#include <BuildInfo.h>

#include <Arduino.h>

void setup()
{
  Serial.begin(115200);
  delay(3000); // Delay as the Serial data on Arduino nano ESP32 auto disconnecting after each uploads
  Serial.println("Setup started");
  Version::setIsVersion();
  Serial.print("Version ");
  Serial.println(Version::getIsVersionAsString());
  Serial.print(toString(BuildInfo::buildEnvironment));
  Serial.print(" ");
  Serial.print(toString(BuildInfo::buildType));
  Serial.print(" build, ");
  Serial.println(BuildInfo::buildTimeStamp);
  Serial.print("\n\n");
}

void loop()
{
}

#else
int main()
{
  return 0;
}
#endif
