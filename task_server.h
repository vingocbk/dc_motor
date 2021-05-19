#ifndef TASK_SERVER
#define TASK_SERVER
#include <Arduino.h>

#define MAX_RESPONSE_LENGTH 512

extern QueueHandle_t queueCommandServer;


void task_server(void * parameter);

#endif
