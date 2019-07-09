#include <Arduino.h>

// Schedule typedef
struct schedule  {
    unsigned long lastRun;
    unsigned long interval;
};

bool scheduleCheck (struct schedule *schedule) {
    if (millis() > schedule->lastRun + schedule->interval) {
        return true;
    }

    return false;
}

void scheduleRun (struct schedule *schedule) {
    schedule->lastRun = millis();
}