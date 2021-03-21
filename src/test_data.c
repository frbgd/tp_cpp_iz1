#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"
#include "test_data.h"

void prepare_test_data(){
    train_stop init_stops[10] = {
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
    schedule->train_count = 22;
    schedule->trains = (train_schedule *) malloc(schedule->train_count * sizeof(train_schedule));

    for(int i = 0; i < 22; i++){
        train_schedule train_schedule = {
                (unsigned short)(i + 1), 10, (train_stop*)malloc(10 * sizeof(train_stop))
        };

        for(int j = 0; j < 10; j++){
            train_stop stop = {
                    (unsigned short)(init_stops[j].arrival + i * 50),
                    (unsigned short)(init_stops[j].departure + i * 50)
            };
            strcpy(stop.station_name, init_stops[j].station_name);

            train_schedule.stops[j] = stop;
        }

        schedule->trains[i] = train_schedule;
    }
}

// чисто для ручного просмотра
//void print_all(){
//    for(int i = 0; i < 22; i++){
//        for(int j =0; j < 10; j++){
//            printf("%u: %02d:%02d - %02d:%02d - %s\n",
//                   schedule->trains[i].number,
//                   schedule->trains[i].stops[j].arrival / 60,
//                   schedule->trains[i].stops[j].arrival % 60,
//                   schedule->trains[i].stops[j].departure / 60,
//                   schedule->trains[i].stops[j].departure % 60,
//                   schedule->trains[i].stops[j].station_name);
//        }
//    }
//}
