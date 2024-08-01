#ifdef RECETTE
#include <BuildInfo.h>
#include <Version.h>

#include <Arduino.h>
#include "ESP32-Mesher.h"

#define MESH_PREFIX "whateverYouLike"
#define MESH_PASSWORD "somethingSneaky"
#define MESH_PORT 5555

Scheduler userScheduler;  // to control your personal task
painlessMesh mesh;

// User stub
void sendMessage();

Task taskSendMessage(TASK_SECOND * 1, TASK_FOREVER, &sendMessage);

void sendMessage() {
  String msg = "Hello from node ";
  msg += mesh.getNodeId();
  mesh.sendBroadcast(msg);
  taskSendMessage.setInterval(random(TASK_SECOND * 1, TASK_SECOND * 5));
}

// Needed for painless library
void receivedCallback(uint32_t from, String &msg) {
  Serial.printf("startHere: Received from %u msg=%s\n", from, msg.c_str());
}

void newConnectionCallback(uint32_t nodeId) {
  Serial.printf("--> startHere: New Connection, nodeId = %u\n", nodeId);
}

void changedConnectionCallback() { Serial.printf("Changed connections\n"); }

void nodeTimeAdjustedCallback(int32_t offset) {
  Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(), offset);
}

void setup() {
  Serial.begin(115200);
  delay(3000);  // Delay as the Serial data on Arduino nano ESP32 auto
                // disconnecting after each uploads
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

  // mesh.setDebugMsgTypes( ERROR | MESH_STATUS | CONNECTION | SYNC |
  // COMMUNICATION | GENERAL | MSG_TYPES | REMOTE ); // all types on
  mesh.setDebugMsgTypes(
      ERROR |
      STARTUP);  // set before init() so that you can see startup messages

  mesh.init(MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT);
  mesh.onReceive(&receivedCallback);
  mesh.onNewConnection(&newConnectionCallback);
  mesh.onChangedConnections(&changedConnectionCallback);
  mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);

  userScheduler.addTask(taskSendMessage);
  taskSendMessage.enable();
}

void loop() {
  // it will run the user scheduler as well
  mesh.update();
}

#else
int main() { return 0; }
#endif
