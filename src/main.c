#include "schedule.h"
#include "test_data.h"

int main(){
    prepare_test_data();

    unsigned short hours, minutes = 0;
    char destinationStation[30] = "";
    printf("enter current time and destination station in format HH:MM STATION_NAME:\n");
    scanf("%hu:%hu %s", &hours, &minutes, destinationStation);

    train_schedule *targetTrain = findSchedule(hours, minutes, destinationStation);
    if (targetTrain != 0){
        printf("You need train number %u at %02u:%02u\n",
               targetTrain->number,
               targetTrain->stops[0].departure / 60,
               targetTrain->stops[0].departure % 60);
    } else {
        printf("NOT FOUND");
    }

    return 0;
}