#include "dc_motor.h"
#include "task_motor.h"
#include "task_server.h"
#include "EEPROM.h"
 

static uint8_t taskCoreZero = 0;
static uint8_t taskCoreOne  = 1;


int cycle_distant[6];


void motor1_stop(){
	digitalWrite(L1_UP, LOW);
	digitalWrite(L1_DOWN, LOW);
}
void motor2_stop(){
	digitalWrite(L2_UP, LOW);
	digitalWrite(L2_DOWN, LOW);
}
void motor3_stop(){
	digitalWrite(L3_UP, LOW);
	digitalWrite(L3_DOWN, LOW);
}
void motor4_stop(){
	digitalWrite(L4_UP, LOW);
	digitalWrite(L4_DOWN, LOW);
}
void motor5_stop(){
	digitalWrite(L5_UP, LOW);
	digitalWrite(L5_DOWN, LOW);
}
void motor6_stop(){
	digitalWrite(L6_UP, LOW);
	digitalWrite(L6_DOWN, LOW);
}

void motor1_open(){
	digitalWrite(L1_UP, HIGH);
	digitalWrite(L1_DOWN, LOW);
}
void motor2_open(){
	digitalWrite(L2_UP, HIGH);
	digitalWrite(L2_DOWN, LOW);
}
void motor3_open(){
	digitalWrite(L3_UP, HIGH);
	digitalWrite(L3_DOWN, LOW);
}
void motor4_open(){
	digitalWrite(L4_UP, HIGH);
	digitalWrite(L4_DOWN, LOW);
}
void motor5_open(){
	digitalWrite(L5_UP, HIGH);
	digitalWrite(L5_DOWN, LOW);
}
void motor6_open(){
	digitalWrite(L6_UP, HIGH);
	digitalWrite(L6_DOWN, LOW);
}

void motor1_close(){
	digitalWrite(L1_UP, LOW);
	digitalWrite(L1_DOWN, HIGH);
}
void motor2_close(){
	digitalWrite(L2_UP, LOW);
	digitalWrite(L2_DOWN, HIGH);
}
void motor3_close(){
	digitalWrite(L3_UP, LOW);
	digitalWrite(L3_DOWN, HIGH);
}
void motor4_close(){
	digitalWrite(L4_UP, LOW);
	digitalWrite(L4_DOWN, HIGH);
}
void motor5_close(){
	digitalWrite(L5_UP, LOW);
	digitalWrite(L5_DOWN, HIGH);
}
void motor6_close(){
	digitalWrite(L6_UP, LOW);
	digitalWrite(L6_DOWN, HIGH);
}

void IRAM_ATTR dirhallSensor1(){

}
void IRAM_ATTR dirhallSensor2(){
    
}
void IRAM_ATTR dirhallSensor3(){
    
}
void IRAM_ATTR dirhallSensor4(){
    
}
void IRAM_ATTR dirhallSensor5(){
    
}
void IRAM_ATTR dirhallSensor6(){
    
}

void setPinMode(){
	pinMode(L1_UP, OUTPUT);
	pinMode(L1_DOWN, OUTPUT);
	pinMode(L2_UP, OUTPUT);
	pinMode(L2_DOWN, OUTPUT);
	pinMode(L3_UP, OUTPUT);
	pinMode(L3_DOWN, OUTPUT);
	pinMode(L4_UP, OUTPUT);
	pinMode(L4_DOWN, OUTPUT);
	pinMode(L5_UP, OUTPUT);
	pinMode(L5_DOWN, OUTPUT);
	pinMode(L6_UP, OUTPUT);
	pinMode(L6_DOWN, OUTPUT);
	

	pinMode(hallSensor1a, INPUT);
	pinMode(hallSensor2a, INPUT);
	pinMode(hallSensor3a, INPUT);
	pinMode(hallSensor4a, INPUT);
	pinMode(hallSensor5a, INPUT);
	pinMode(hallSensor6a, INPUT);
	pinMode(pinSetUp, INPUT);

	delay(10);
}

void loadDataEeprom(){

}

void setup(){
    // put your setup code here, to run once:
    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector
	Serial.begin(BAUD_RATE_SERIAL);
    EEPROM.begin(MAX_SIZE_EEPROM_BUFFER);

	setPinMode();
	loadDataEeprom();


	attachInterrupt(digitalPinToInterrupt(hallSensor1a), dirhallSensor1, RISING);
	attachInterrupt(digitalPinToInterrupt(hallSensor2a), dirhallSensor2, RISING);
	attachInterrupt(digitalPinToInterrupt(hallSensor3a), dirhallSensor3, RISING);
	attachInterrupt(digitalPinToInterrupt(hallSensor4a), dirhallSensor4, RISING);
	attachInterrupt(digitalPinToInterrupt(hallSensor5a), dirhallSensor5, RISING);
	attachInterrupt(digitalPinToInterrupt(hallSensor6a), dirhallSensor6, RISING);


    /* Create the queues. See the respective data-types for details of queue
       contents */
    queueCommandMotor   = xQueueCreate(MOTOR_COMMAND_QUEUE_LEN,
                                    sizeof(motor_command_t));
    queueCommandServer  = xQueueCreate(SERVER_COMMAND_QUEUE_LEN,
                                    sizeof(motor_command_t));


    xTaskCreatePinnedToCore(
        task_motor,      // Function that should be called
        "task motor",    // Name of the task (for debugging)
        MAX_SIZE_STACK_TASK_MOTOR,               // Stack size (bytes)
        NULL,               // Parameter to pass
        TASK_MOTOR_PRIORITY,                  // Task priority
        &TaskMotorHandle,               // Task handle
        taskCoreZero          // Core you want to run the task on (0 or 1)
    );
    xTaskCreatePinnedToCore(
        task_server,      // Function that should be called
        "task server",    // Name of the task (for debugging)
        MAX_SIZE_STACK_TASK_SERVER,               // Stack size (bytes)
        NULL,               // Parameter to pass
        TASK_SERVER_PRIORITY,                  // Task priority
        &TaskServerHandle,               // Task handle
        taskCoreZero         // Core you want to run the task on (0 or 1)
    );

}

void loop(){
    vTaskDelay(100 / portTICK_PERIOD_MS);
}
