#ifndef LOGGER_H
#define LOGGER_H

#include <stdint.h>
#include <stddef.h>

typedef char char_t;

void log_message(const char_t *message);
void log_value(const char_t *format, int32_t value);

#endif // LOGGER_H