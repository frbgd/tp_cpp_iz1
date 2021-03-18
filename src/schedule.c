#include <string.h>
#include "schedule.h"

short convert_to_minutes(unsigned short hours, unsigned short minutes){
    if (hours > 23 || minutes > 59)
        return -1;
    return (short)(hours * 60 + minutes);
}

struct train_schedule *findByStationName(train_schedule *trainSchedule, char *destinationName){
    unsigned short i = 0;
    for(; i < trainSchedule->stopCount; i++){
        if(strcmp(destinationName, trainSchedule->stops[i].stationName) == 0) {
            return trainSchedule;
        }
    }
    return 0;
}

train_schedule *findSchedule(unsigned short hours, unsigned short minutes, char *destinationName){
    short current_time = convert_to_minutes(hours, minutes);
    if(current_time < 0)
        return 0;

    unsigned short i = 0;
    for(; i < schedule->trainCount; i++){
        if(current_time < schedule->trains[i].stops[0].departure){
            return findByStationName(&schedule->trains[i], destinationName);
        }
    }

    return findByStationName(&schedule->trains[0], destinationName);
}
