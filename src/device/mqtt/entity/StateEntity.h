#pragma once

#include <Arduino.h>
#include "../../../defines.h"
#include "../../HADeviceState.h"

class StateEntity
{
public:
    StateEntity(HADeviceState *state) : _state(state) {}

    const char *marshalJSON();

private:
    HADeviceState *_state;
    char _payload[50] = {0};
};
