#ifndef TASK_SERVER
#define TASK_SERVER
#include <Arduino.h>

#define MAX_RESPONSE_LENGTH 512

extern QueueHandle_t bleCommandQ;

typedef enum{
    BLE_COMMAND_CURRENT_MOTOR_1,        //Value Current off hall sensor
    BLE_COMMAND_CURRENT_MOTOR_2,
    BLE_COMMAND_CURRENT_MOTOR_3,
    BLE_COMMAND_CURRENT_MOTOR_4,
    BLE_COMMAND_CURRENT_MOTOR_5,
    BLE_COMMAND_CURRENT_MOTOR_6,
    BLE_COMMAND_DISTANT_MOTOR_1,        //Value all distant fix to motor run
    BLE_COMMAND_DISTANT_MOTOR_2,
    BLE_COMMAND_DISTANT_MOTOR_3,
    BLE_COMMAND_DISTANT_MOTOR_4,
    BLE_COMMAND_DISTANT_MOTOR_5,
    BLE_COMMAND_DISTANT_MOTOR_6,
} ble_command_list_t;

typedef struct 
{
    /* data */
    ble_command_list_t command;
    uint8_t data_send_app;
} ble_command_t;


void task_server(void * parameter);

#endif
