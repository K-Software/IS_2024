#ifndef AXLE_COUNTER_H
#define AXLE_COUNTER_H
#include <stdint.h>

#define FREE 0 //track segment is free
#define OCCUPIED 1 //track segment is occupied
typedef double float64_t;

int32_t axle_Counter(int32_t sectionP, int32_t total_wagons);

void safe_log(const char *format);
static void safe_log_value(const char *format, int32_t value);
int32_t check_status(void);
void first_axle_counter_pushed(void);
void second_axle_counter_pushed(void);

float64_t testFunction(float64_t a);

#endif
