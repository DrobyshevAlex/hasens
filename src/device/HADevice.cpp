#include "HADevice.h"
#include "DHT.h"
#include "Adafruit_Sensor.h"

DHT dht(DHTPIN, DHTTYPE);

void HADevice::init()
{
  dht.begin();
}

void HADevice::loop()
{
  ulong ms = millis();

  if ((_lastSendStateTime + 5000) < ms)
  {
    read();
    if (_current != _prev || !_send)
    {
      StateEntity state(&_current);
      _send = _stateProducer->publish(&state);
      _prev = _current;
    }

    _lastSendStateTime = ms;
  }
}

void HADevice::read()
{
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  _current.setT(t);
  _current.setH(h);
}
