#ifndef SRC_SCHEDULE_H_
#define SRC_SCHEDULE_H_

const int STATION_NAME_LENGTH = 30;

struct train_stop{
    unsigned short arrival;
    unsigned short departure;
    char station_name[STATION_NAME_LENGTH];
};
struct train_schedule{
    unsigned short number;
    unsigned short stopCount;
    struct train_stop *stops;
};

struct general_schedule{
    unsigned short train_count;
    struct train_schedule *trains;
};

typedef struct train_stop train_stop;
typedef struct train_schedule train_schedule;
typedef struct general_schedule general_schedule;

general_schedule *schedule;

train_schedule *find_schedule(unsigned short hours, unsigned short minutes, char *destination_name);

#endif  // SRC_SCHEDULE_H_
