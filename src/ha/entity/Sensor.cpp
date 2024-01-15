#include "../../defines.h"
#include "Sensor.h"

const char *Sensor::marshalJSON()
{
    DynamicJsonDocument jsonDoc(PAYLOAD_LEN);
    JsonObject entity = jsonDoc.to<JsonObject>();
    buildBaseField(&entity);

    entity[F("state")] = _state;
    entity[F("icon")] = _icon;
    entity[F("state_topic")] = _state_topic;
    entity[F("command_topic")] = _command_topic;
    entity[F("value_template")] = _value_template;

    serializeJson(jsonDoc, _payload, PAYLOAD_LEN);

    return _payload;
}