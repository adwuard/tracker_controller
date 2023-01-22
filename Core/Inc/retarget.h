#ifndef _RETARGET_H__
#define _RETARGET_H__

#include "stm32f4xx_hal.h"
#include <sys/stat.h>

#define LOG_LEVEL_ERROR 0
#define LOG_LEVEL_WARN 1
#define LOG_LEVEL_INFO 2
#define LOG_LEVEL_DEBUG 3

static int LOG_LEVEL = LOG_LEVEL_DEBUG;

#define LOG_INFO(format, ...)                     \
    do                                            \
    {                                             \
        if (LOG_LEVEL < LOG_LEVEL_INFO)           \
            break;                                \
        printf("[%ld:%ld:%ld][INFO][%s]:" format, \
               HAL_GetTick() / 1000 / 60,         \
               HAL_GetTick() / 1000,              \
               HAL_GetTick() % 1000,              \
               __FUNCTION__,                      \
               ##__VA_ARGS__);                    \
    } while (0)

#define LOG_WARN(format, ...)                     \
    do                                            \
    {                                             \
        if (LOG_LEVEL < LOG_LEVEL_WARN)           \
            break;                                \
        printf("[%ld:%ld:%ld][WARN][%s]:" format, \
               HAL_GetTick() / 1000 / 60,         \
               HAL_GetTick() / 1000,              \
               HAL_GetTick() % 1000,              \
               __FUNCTION__,                      \
               ##__VA_ARGS__);                    \
    } while (0)

#define LOG_ERROR(format, ...)                     \
    do                                             \
    {                                              \
        if (LOG_LEVEL < LOG_LEVEL_ERROR)           \
            break;                                 \
        printf("[%ld:%ld:%ld][ERROR][%s]:" format, \
               HAL_GetTick() / 1000 / 60,          \
               HAL_GetTick() / 1000,               \
               HAL_GetTick() % 1000,               \
               __FUNCTION__,                       \
               ##__VA_ARGS__);                     \
    } while (0)

#define LOG_DEBUG(format, ...)                     \
    do                                             \
    {                                              \
        if (LOG_LEVEL < LOG_LEVEL_DEBUG)           \
            break;                                 \
        printf("[%ld:%ld:%ld][DEBUG][%s]:" format, \
               HAL_GetTick() / 1000 / 60,          \
               HAL_GetTick() / 1000,               \
               HAL_GetTick() % 1000,               \
               __FUNCTION__,                       \
               ##__VA_ARGS__);                     \
    } while (0)

void RetargetInit(UART_HandleTypeDef *huart);
int _isatty(int fd);
int _write(int fd, char *ptr, int len);
int _close(int fd);
int _lseek(int fd, int ptr, int dir);
int _read(int fd, char *ptr, int len);
int _fstat(int fd, struct stat *st);

#endif // #ifndef _RETARGET_H__