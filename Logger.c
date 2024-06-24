#include "Logger.h"

#ifdef DEBUG
#include <stdio.h> // Needed for printf in DEBUG mode
#endif

#define LOG_BUFFER_SIZE 128

// Dummy function to write to a serial port
static void serial_write(const char_t *data);

// Log a message by adding it to the circular buffer and then writing it to the serial port
void log_message(const char_t *message) {
    if (message != NULL) {
        char_t log_buffer[LOG_BUFFER_SIZE];
        size_t log_buffer_index = 0;

        while ((message[log_buffer_index] != '\0') && (log_buffer_index < (LOG_BUFFER_SIZE - 1))) {
            log_buffer[log_buffer_index] = message[log_buffer_index];
            log_buffer_index++;
        }
        log_buffer[log_buffer_index] = '\0'; // Null-terminate the string

        // Write the buffer to the serial port
        serial_write(log_buffer);
    }
}

// Log a formatted value by adding it to the circular buffer and then writing it to the serial port
void log_value(const char_t *format, int32_t value) {
    char_t temp_buffer[LOG_BUFFER_SIZE];
    size_t buffer_pos = 0;

    if (format != NULL) {
        while ((format[buffer_pos] != '\0') && (buffer_pos < (LOG_BUFFER_SIZE - 1U))) {
            temp_buffer[buffer_pos] = format[buffer_pos];
            buffer_pos++;
        }
        temp_buffer[buffer_pos] = '\0';

        // Simple conversion of `value` to a decimal string
        char_t value_str[12]; // Buffer to hold the converted value (including sign and terminator)
        int32_t temp_value = value;
        size_t value_pos = 0;
        if (temp_value < 0) {
            value_str[value_pos] = '-';
            value_pos++;
            temp_value = -temp_value;
        }
        size_t start = value_pos;
        do {
            value_str[value_pos] = (char)((temp_value % 10) + '0');
            value_pos++;
            temp_value /= 10;
        } while (temp_value > 0);
        value_str[value_pos] = '\0';

        // Reverse the value string
        size_t end = value_pos - 1U;
        while (start < end) {
            char_t temp = value_str[start];
            value_str[start] = value_str[end];
            value_str[end] = temp;
            start++;
            end--;
        }

        // Add the format and value to the log buffer
        log_message(temp_buffer);
        log_message(value_str);
        log_message("\n");
    }
}

// Dummy implementation of serial_write - replace with hardware-specific code
static void serial_write(const char_t *data) {
    if (data != NULL) {
#ifdef DEBUG
        printf("%s", data);
#else
        // hardware-specific code
#endif
    }
}