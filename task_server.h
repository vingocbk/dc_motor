#ifndef TASK_SERVER
#define TASK_SERVER
#include <Arduino.h>

extern QueueHandle_t queueCommandServer;


void task_server(void * parameter);

#endif
