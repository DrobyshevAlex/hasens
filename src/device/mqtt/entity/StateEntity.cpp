#include <ArduinoJson.h>
#include "StateEntity.h"
#include "defines.h"

const char *StateEntity::marshalJSON()
{
    DynamicJsonDocument jsonDoc(50);
    JsonObject entity = jsonDoc.to<JsonObject>();
    entity[F("t")] = _state->getT();
    entity[F("h")] = _state->getH();

    serializeJson(jsonDoc, _payload, 50);

    return _payload;
}
