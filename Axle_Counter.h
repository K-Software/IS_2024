#ifndef AXLE_COUNTER_H
#define AXLE_COUNTER_H
#include <stdint.h>

#define FREE 0 //track segment is free
#define OCCUPIED 1 //track segment is occupied

int32_t axle_Counter(int32_t sectionP, int32_t total_wagons);

int32_t check_status(void);
void first_axle_counter_pushed(void);
void second_axle_counter_pushed(void);

#endif
