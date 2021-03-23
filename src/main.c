#include <stdio.h>
#include "schedule.h"
#include "test_data.h"

int main() {
    prepare_test_data();

    unsigned short hours = 0, minutes = 0;
    char destination_station[STATION_NAME_LENGTH] = "";
    printf("enter current time and destination station in format HH:MM STATION_NAME:\n");
    scanf("%hu:%hu %29s", &hours, &minutes, destination_station);

    train_schedule *target_train = find_schedule(hours, minutes, destination_station);
    if (target_train != NULL) {
        printf("You need train number %u at %02d:%02d\n",
               target_train->number,
               target_train->stops[0].departure / MINUTES_IN_HOUR,
               target_train->stops[0].departure % MINUTES_IN_HOUR);
    } else {
        printf("NOT FOUND");
    }

    return 0;
}
