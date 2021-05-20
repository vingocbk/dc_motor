#ifndef APP_DC_MOTOR
#define APP_DC_MOTOR

#include <Arduino.h>
#include "config.h"
#include "soc/soc.h"  //Brownout detector was triggered
#include "soc/rtc_cntl_reg.h"

#define MAX_SIZE_STACK_TASK_MOTOR       1024
#define MAX_SIZE_STACK_TASK_SERVER      1024

#define TASK_MOTOR_PRIORITY             1
#define TASK_SERVER_PRIORITY            1

#define MOTOR_COMMAND_QUEUE_LEN         10
#define SERVER_COMMAND_QUEUE_LEN        10

TaskHandle_t TaskMotorHandle, TaskServerHandle;




void IRAM_ATTR dirhallSensor1();
void IRAM_ATTR dirhallSensor2();
void IRAM_ATTR dirhallSensor3();
void IRAM_ATTR dirhallSensor4();
void IRAM_ATTR dirhallSensor5();
void IRAM_ATTR dirhallSensor6();

void setPinMode();
void loadDataEeprom();

#endif
