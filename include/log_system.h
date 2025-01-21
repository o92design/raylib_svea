#ifndef LOG_SYSTEM_H
#define LOG_SYSTEM_H

#include <stdio.h>

#ifdef _WIN32
    #define log_error(format, ...) fprintf_s(stderr, format "\n", ##__VA_ARGS__)
    #define log_info(format, ...) fprintf_s(stdout, format "\n", ##__VA_ARGS__)
#else
    #define log_error(format, ...) fprintf(stderr, format "\n", ##__VA_ARGS__)
    #define log_info(format, ...) fprintf(stdout, format "\n", ##__VA_ARGS__)
#endif

#endif // LOG_SYSTEM_H