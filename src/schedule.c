#include <string.h>
#include "schedule.h"

short convert_to_minutes(unsigned short hours, unsigned short minutes) {
    if (hours >= HOURS_IN_DAY || minutes >= MINUTES_IN_HOUR)
        return -1;
    return (short)(hours * MINUTES_IN_HOUR + minutes);
}

train_schedule *find_by_station_name(train_schedule *tr_schedule, char *destination_name) {
    if (tr_schedule == NULL)
        return NULL;

    unsigned short i = 0;
    for (; i < tr_schedule->stopCount; i++) {
        if (strcmp(destination_name, tr_schedule->stops[i].station_name) == 0) {
            return tr_schedule;
        }
    }
    return NULL;
}

train_schedule *find_schedule(unsigned short hours, unsigned short minutes, char *destination_name) {
    if (schedule == NULL)
        return NULL;

    short current_time = convert_to_minutes(hours, minutes);
    if (current_time < 0)
        return NULL;

    unsigned short i = 0;
    for (; i < schedule->train_count; i++) {
        train_schedule *tr_schedule = &schedule->trains[i];
        if (tr_schedule != NULL && current_time < tr_schedule->stops[0].departure) {
            return find_by_station_name(tr_schedule, destination_name);
        }
    }

    return find_by_station_name(&schedule->trains[0], destination_name);
}
