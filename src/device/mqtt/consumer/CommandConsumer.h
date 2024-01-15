#pragma once

#include <Arduino.h>
#include "mqtt/Consumer.h"
#include "../../HADevice.h"

class CommandConsumer : public Consumer
{
public:
    CommandConsumer(HADevice *device) : _device(device) {}
    void consume(const char *payload);

private:
    HADevice *_device;
};
