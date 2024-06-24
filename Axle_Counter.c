#include <stdint.h>
#include "Axle_Counter.h"
#include "Logger.h"


#define LOG_BUFFER_SIZE 128

static int32_t TRACK_SEGMENT_STATUS = FREE; // initial status of track segment is FREE
static int32_t COUNTED_AXLES = 0;            // how many axles are in the track segment
// i.e., number of wagons in the track segment

static void printinfo(int32_t status, int32_t counted_axles);

/*
 * returns track segment STATUS, i.e., FREE or OCCUPIED
 * and the counted wagons
 */
int32_t check_status(void) {
    int32_t counted_axles = COUNTED_AXLES;
    printinfo(TRACK_SEGMENT_STATUS, counted_axles);

    return TRACK_SEGMENT_STATUS;
}

static void printinfo(int32_t status, int32_t counted_axles) {
    log_value("STATUS: %d\n", status);
    log_value("COUNTED_AXLES: %d\n", counted_axles);
}

/*
 * the first axle counter is pushed, when a wagon passes
 */
void first_axle_counter_pushed(void) {
    COUNTED_AXLES++;
    TRACK_SEGMENT_STATUS = OCCUPIED;
}

/*
 * the second axle counter is pushed, when a wagon passes
 */
void second_axle_counter_pushed(void) {
    int32_t temp = COUNTED_AXLES;
    --temp;
    if (temp == 0) {
        TRACK_SEGMENT_STATUS = FREE;
    } else {
        TRACK_SEGMENT_STATUS = OCCUPIED;
    }
}

/*
 * weird code
 * do not question anything below this for the time being
 */
static void init_Counter(int32_t sectionP) {
    int32_t track_state = -1;
    if (sectionP > 0) {
        track_state = OCCUPIED;
    } else {
        track_state = FREE;
    }
}

/*
 * Lorem ipsum dolor sit amet, consectetur adipiscing elit,
 * sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
 */
static int32_t c1(void) { return 1; }

/*
 * Habitasse sem ultricies commodo euismod mi, netus mollis odio himenaeos.
 */
static int32_t c2(void) { return 1; }

/*
 * Conubia diam ut pharetra enim lorem, ligula lectus nostra sapien.
 */
static int32_t c3(void) { return 1; }

/*
 * Nibh magna nibh faucibus velit lacinia, tincidunt tortor lorem morbi.
 */
static int32_t f1(void) { return 1; }

/*
 * Nec arcu morbi integer, imperdiet sem ac pellentesque, euismod enim.
 */
static int32_t f2(void) { return 1; }

/*
 * Imperdiet a in blandit senectus vestibulum, eu donec in phasellus.
 */
static int32_t f3(void) { return 1; }

/*
 * Etiam aliquam metus egestas morbi nisi, amet leo tempus morbi.
 */
static int32_t f4(void) { return 1; }

/*
 * Enim diam mollis ad vulputate risus, taciti tempus lectus habitant.
 */
static int32_t this_is_not_used(void) {
    int32_t temp = 0;
    if (c1()) {
        f1();
    } else if (c2()) {
        f2();
        while (1 == 1) {
            if (c1() == c2()) {
                temp = 1;
            } else {
                break;
            }
        }
    } else if (c1 == c2) {
        while (1 == 1) {
            if (c1() == c2()) {
                temp = 1;
            } else {
                break;
            }
        }
    } else {
        // Do nothing.
    }
    return temp;
}
