#include <Arduino.h>
#include "CommandConsumer.h"
#include "../entity/CommandEntity.h"

void CommandConsumer::consume(const char *payload)
{
    Serial.printf("CommandConsumer::consume: %s\n", payload);

    CommandEntity command;
    if (!command.unmarshalJSON(payload))
    {
        Serial.printf("cant unmarshal command");
        return;
    }

    Serial.print("Command: ");
    Serial.println(command.getAction());
}
