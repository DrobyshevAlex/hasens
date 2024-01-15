#pragma once

#include <Arduino.h>
#include <ArduinoJSON.h>
#include <list>
#include "Base.h"

#define PAYLOAD_LEN 700

class Sensor : Base
{
public:
    Sensor(
        const char *name,
        Device *device,
        EntityCategory *entityCategory,
        const char *objectID,
        const char *uniqueID,
        bool forceUpdate) : Base(name, device, entityCategory, objectID, uniqueID, forceUpdate) {}
    const char *marshalJSON();

    void setStateTopic(const char *v)
    {
        _state_topic = v;
    }

    void setCommandTopic(const char *v)
    {
        _command_topic = v;
    }

    void setValueTemplate(const char *v)
    {
        _value_template = v;
    }

    void setIcon(const char *v)
    {
        _value_template = v;
    }

private:
    uint8_t _state;

    const char *_state_topic = NULL;
    const char *_command_topic = NULL;
    const char *_value_template = NULL;
    const char *_icon = NULL;

    char _payload[PAYLOAD_LEN] = {0};
};
