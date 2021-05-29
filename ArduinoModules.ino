#include "module.h"
#include "LedBlinker.h"

void setup() {
    Module::addModule(new LedBlinker(LED_BUILTIN));
}

void loop() {
    Module::loopAll();
}
