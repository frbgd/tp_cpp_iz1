struct train_stop{
    unsigned short arrival;
    unsigned short departure;
    char stationName[30];
};
struct train_schedule{
    unsigned short number;
    unsigned short stopCount;
    struct train_stop *stops;
};

struct general_schedule{
    unsigned short trainCount;
    struct train_schedule *trains;
};

typedef struct train_stop train_stop;
typedef struct train_schedule train_schedule;
typedef struct general_schedule general_schedule;

general_schedule *schedule;

train_schedule *findSchedule(unsigned short hours, unsigned short minutes, char *destinationName);
