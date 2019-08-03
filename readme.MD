## Adruino Schedule

Allows you to run scheduled tasks, think of it more like cronjobs. E.G every 30 seconds do x, every 5 seconds do y.

*Please note, your code will delay the running of the application so if you run blocking code for 10 seconds, everything will be delayed by 10 seconds, everything runs on the single thread, as Arduino does not have multi threading.*

*I did not write this completly, help was found on the internet.*

### Example Usage

Place library into your lib folder.

~~~~
#include <Arduino.h>
#include <./ArduinoSchedule/src/schedule.h>

schedule schedule_30_seconds = {0, 30000};

void schedule_30_seconds_run()
{
    Serial.println("--TEMP");
    printTemp("I ", insideTemp);
    printTemp("T ", tunnelTemp);
    printTemp("O ", outsideTemp);
}

void loop()
{
    if (scheduleCheck(&schedule_30_seconds)) {
        schedule_30_seconds_run();
        scheduleRun(&schedule_30_seconds);
    }
}
~~~~