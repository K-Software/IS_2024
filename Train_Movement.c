#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Axle_Counter.h"

#define FREE 0
#define OCCUPIED 1
#define NO_SAFETY_RISK 0

void train_arrives(const int32_t x);
void train_leaves(int32_t x);

/*
 * Axle counter system returns the status (FREE/OCCUPIED when check status is invoked
 * At the beginning, status is FREE
 * When a train arrives, stratus changes to OCCUPIED
 * When the train leaves, stratus changes to FREE
 */
int32_t main(void)
{
	int32_t *ptr = malloc(sizeof(int32_t));
	if (ptr == NULL)
	{
		safe_log("Memory not allocated.\n");
	}
	else
	{

		safe_log("project starting\n");
		int32_t status_track = check_status();

		train_arrives(3); // input is the number of axles
		status_track = check_status();

		train_leaves(3); // the same number of axlesof when it entered the track segment...
		status_track = check_status();
	}
}

/*
 * A train composed of n wagons arrives to the track segment
 * In other words, it reaches the first axle counter
 * weird code
 */
void train_arrives(const int32_t L)
{
	if (check_status() == OCCUPIED)
	{ // if the train arrives, but the track is already occcupied
		safe_log("safety risk");
#ifdef NO_SAFETY_RISK
		if (check_status() == NO_SAFETY_RISK)
		{
			exit(0);
		}
#endif
		return;
	}
	for (int32_t l = 0L; l < L; l++)
	{
		first_axle_counter_pushed();
	}
}

/*
 * A train composed of n wagons leaves the track segment
 * In other words, it reaches the second axle counter
 */
void train_leaves(int32_t L)
{
	for (int32_t l = 0L; l < L; l++)
	{
		second_axle_counter_pushed();
	}
}
