#include "task_server.h"



QueueHandle_t queueCommandServer;

void task_server(void * parameter){

    while (1)
    {
        /* code */
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    
}
