#ifndef TASK_MOTOR
#define TASK_MOTOR
#include <Arduino.h>

extern QueueHandle_t queueCommandMotor;


/* List of BLE commands */
typedef enum
{
    PROCESS_BLE_EVENTS,
    HANDLE_GPIO_INTERRUPT,
    SEND_TEMPERATURE_INDICATION,
}   motor_commands_list_t;

/* Data-type of BLE commands and data */
typedef struct
{   
    motor_commands_list_t command;
    uint32_t               data;
}   motor_command_t;


void task_motor(void * parameter);

#endif
