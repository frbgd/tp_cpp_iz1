#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"
#include "test_data.h"

void prepare_test_data(){
    train_stop initStops[10] = {
            {303, 303, "Balashikha"},
            {310, 311, "pl. Gorenki"},
            {315, 316, "Stroika"},
            {322, 323, "Reutovo"},
            {325, 326, "pl. Novogireevo"},
            {328, 329, "Kuskovo"},
            {331, 332, "pl. Chukhlinka"},
            {334, 335, "Nizhegorodskaya"},
            {339, 341, "pl. Serp i Molot"},
            {346, 346, "Moscow"}
    };
    schedule = (general_schedule *)(malloc(sizeof(general_schedule)));
    schedule->trainCount = 22;
    schedule->trains = (train_schedule *) malloc(schedule->trainCount * sizeof(train_schedule));

    for(int i = 0; i < 22; i++){
        train_schedule trainSchedule = {
                (unsigned short)(i + 1), 10, (train_stop*)malloc(10 * sizeof(train_stop))
        };

        for(int j = 0; j < 10; j++){
            train_stop stop = {
                    (unsigned short)(initStops[j].arrival + i * 50),
                    (unsigned short)(initStops[j].departure + i * 50)
            };
            strcpy(stop.stationName, initStops[j].stationName);

            trainSchedule.stops[j] = stop;
        }

        schedule->trains[i] = trainSchedule;
    }
}

// чисто для ручного просмотра
void printAll(){
    for(int i = 0; i < 22; i++){
        for(int j =0; j < 10; j++){
            printf("%u: %02u:%02u - %02u:%02u - %s\n",
                   schedule->trains[i].number,
                   schedule->trains[i].stops[j].arrival / 60,
                   schedule->trains[i].stops[j].arrival % 60,
                   schedule->trains[i].stops[j].departure / 60,
                   schedule->trains[i].stops[j].departure % 60,
                   schedule->trains[i].stops[j].stationName);
        }
    }
}
