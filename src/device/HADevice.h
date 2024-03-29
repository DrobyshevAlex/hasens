#pragma once

#include "mqtt/producer/StateProducer.h"
#include "HADeviceState.h"

#define DHTPIN 2 // Digital pin connected to the DHT sensor
                 // Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
                 // Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment the type of sensor in use:
#define DHTTYPE DHT11 // DHT 11
// #define DHTTYPE DHT22 // DHT 22 (AM2302)
// #define DHTTYPE    DHT21     // DHT 21 (AM2301)

class HADevice
{
public:
  HADevice(
      StateProducer *stateProducer) : _stateProducer(stateProducer) {}
  void init();
  void loop();

private:
  void read();

private:
  StateProducer *_stateProducer;
  HADeviceState _current;
  HADeviceState _prev;

  bool _send = false;

  unsigned long _lastSendStateTime = 0;
};
