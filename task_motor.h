#ifndef TASK_MOTOR
#define TASK_MOTOR
#include <Arduino.h>


extern QueueHandle_t motorCommandQ;
extern struct current_motor current_distant_motor;
extern struct distant_motor value_distant_motor;
extern bool isModeConfig;
/* List of BLE commands */
typedef enum
{
    //--------set motor only run, no check distant-----
    PROCESS_MOTOR_1_OPEN_ONLY,   
    PROCESS_MOTOR_2_OPEN_ONLY,
    PROCESS_MOTOR_3_OPEN_ONLY,
    PROCESS_MOTOR_4_OPEN_ONLY,
    PROCESS_MOTOR_5_OPEN_ONLY,
    PROCESS_MOTOR_6_OPEN_ONLY,
    //--------stop-----------
    PROCESS_MOTOR_1_STOP_ONLY,
    PROCESS_MOTOR_2_STOP_ONLY,
    PROCESS_MOTOR_3_STOP_ONLY,
    PROCESS_MOTOR_4_STOP_ONLY,
    PROCESS_MOTOR_5_STOP_ONLY,
    PROCESS_MOTOR_6_STOP_ONLY,
    //--------close-----------
    PROCESS_MOTOR_1_CLOSE_ONLY,
    PROCESS_MOTOR_2_CLOSE_ONLY,
    PROCESS_MOTOR_3_CLOSE_ONLY,
    PROCESS_MOTOR_4_CLOSE_ONLY,
    PROCESS_MOTOR_5_CLOSE_ONLY,
    PROCESS_MOTOR_6_CLOSE_ONLY,
    //--------set motor run, save distant in eeproom------
    PROCESS_MOTOR_1_OPEN_SAVE_DISTANT,
    PROCESS_MOTOR_2_OPEN_SAVE_DISTANT,
    PROCESS_MOTOR_3_OPEN_SAVE_DISTANT,
    PROCESS_MOTOR_4_OPEN_SAVE_DISTANT,
    PROCESS_MOTOR_5_OPEN_SAVE_DISTANT,
    PROCESS_MOTOR_6_OPEN_SAVE_DISTANT,
    //---------stop------------------
    PROCESS_MOTOR_1_STOP_SAVE_DISTANT,
    PROCESS_MOTOR_2_STOP_SAVE_DISTANT,
    PROCESS_MOTOR_3_STOP_SAVE_DISTANT,
    PROCESS_MOTOR_4_STOP_SAVE_DISTANT,
    PROCESS_MOTOR_5_STOP_SAVE_DISTANT,
    PROCESS_MOTOR_6_STOP_SAVE_DISTANT,
    //--------set motor run step, step fix on app---------
    PROCESS_MOTOR_1_OPEN_STEP,
    PROCESS_MOTOR_2_OPEN_STEP,
    PROCESS_MOTOR_3_OPEN_STEP,
    PROCESS_MOTOR_4_OPEN_STEP,
    PROCESS_MOTOR_5_OPEN_STEP,
    PROCESS_MOTOR_6_OPEN_STEP,
}   motor_commands_list_t;

/* Data-type of BLE commands and data */
typedef struct
{   
    motor_commands_list_t command;
    uint32_t               data_step;
}   motor_command_t;


void task_motor(void * parameter);
void readDataEeprom();

#endif
