#include <stdint.h>
#include "Axle_Counter.h"
#include "Logger.h"

#define FREE 0
#define OCCUPIED 1
#define NO_SAFETY_RISK 0

static int32_t train_arrives(int32_t axles);
static void train_leaves(int32_t axles);

/*
 * Axle counter system returns the status (FREE/OCCUPIED when check status is invoked
 * At the beginning, status is FREE
 * When a train arrives, stratus changes to OCCUPIED
 * When the train leaves, stratus changes to FREE
 */
int32_t main(void)
{
    int32_t exit_status = 0;

    int32_t local_variable; // Allocate on the stack
    int32_t *pointer = &local_variable;  // Point to the local variable

    log_message("project starting\n");
    int32_t status_track = check_status();

    exit_status = train_arrives(3); // input is the number of axles

    if(exit_status == 0) {
        status_track = check_status();

        train_leaves(3); // the same number of axlesof when it entered the track segment...
        status_track = check_status();
    }

    return exit_status;
}

/*
 * A train composed of n axles arrives to the track segment
 * In other words, it reaches the first axle counter
 * weird code
 */
static int32_t train_arrives(int32_t axles)
{
    int32_t exit_status = 0;
	if (check_status() == OCCUPIED)
	{ // if the train arrives, but the track is already occcupied
        log_message("safety risk");
#ifdef NO_SAFETY_RISK
		if (check_status() == NO_SAFETY_RISK)
		{
            exit_status = 1;
		}
#endif
	}
    if (exit_status == 0) {
        for (int32_t l = 0L; l < axles; l++) {
            first_axle_counter_pushed();
        }
    }
    return exit_status;
}

/*
 * A train composed of n axles leaves the track segment
 * In other words, it reaches the second axle counter
 */
static void train_leaves(int32_t axles)
{
	for (int32_t l = 0L; l < axles; l++)
	{
		second_axle_counter_pushed();
	}
}
