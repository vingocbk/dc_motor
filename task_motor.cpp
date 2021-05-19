#include "task_motor.h"

QueueHandle_t queueCommandMotor;
//motor stop
extern void motor1_stop();
extern void motor2_stop();
extern void motor3_stop();
extern void motor4_stop();
extern void motor5_stop();
extern void motor6_stop();
//motor open
extern void motor1_open();
extern void motor2_open();
extern void motor3_open();
extern void motor4_open();
extern void motor5_open();
extern void motor6_open();
//motor close
extern void motor1_close();
extern void motor2_close();
extern void motor3_close();
extern void motor4_close();
extern void motor5_close();
extern void motor6_close();




void task_motor(void * parameter){

    
    while (1)
    {
        /* code */
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    
}
