#include "task_motor.h"

QueueHandle_t queueCommandMotor;

void task_motor(void * parameter){


    while (1)
    {
        /* code */
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    
}
