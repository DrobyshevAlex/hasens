#include <Arduino.h>
#include "defines.h"
#include "config/ConfigMgr.h"
#include "wifi/WiFiMgr.h"
#include "mqtt/MQTT.h"
#include "ha/DiscoveryMgr.h"
#include "ESP8266HTTPClient.h"
#include "device/mqtt/producer/StateProducer.h"
#include "device/mqtt/consumer/CommandConsumer.h"
#include "device/HADevice.h"

ConfigMgr cnf;
WiFiManager wifiManager(&cnf);
MQTT *mqtt;
DiscoveryMgr *discoveryMgr;
StateProducer *stateProducer;
CommandConsumer *commandConsumer;
HADevice *device;

void setup()
{
  Serial.begin(SERIAL_SPEED);

  cnf.load();

  wifiManager.connect();

  mqtt = new MQTT(&cnf);
  mqtt->init();

  discoveryMgr = new DiscoveryMgr(&cnf, mqtt);
  discoveryMgr->init();

  stateProducer = new StateProducer(mqtt, cnf.getDiscoveryConfigData());

  device = new HADevice(stateProducer);
  device->init();

  commandConsumer = new CommandConsumer(device);
  commandConsumer->init(cnf.getDiscoveryConfigData()->mqttCommandTopic);
  mqtt->subscribe(commandConsumer);
}

void loop()
{
  if (wifiManager.isConnected())
  {
    discoveryMgr->loop();
    device->loop();
    mqtt->loop();
  }
}
