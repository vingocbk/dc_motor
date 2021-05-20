#include "task_server.h"
#include "BluetoothSerial.h"
#include "AppDebug.h"
#include "ArduinoJson.h"

QueueHandle_t bleCommandQ;
BluetoothSerial SerialBT;


/******************************************
*   ALL FUNCTION OF TASK
*******************************************/
void callbackBluetooth(esp_spp_cb_event_t event, esp_spp_cb_param_t *param);



//--------Main Function--------------
void task_server(void * parameter){

    SerialBT.register_callback(callbackBluetooth);
    if(!SerialBT.begin("ESP32")){
        ECHOLN("An error occurred initializing Bluetooth");
    }else{
        ECHOLN("Bluetooth initialized");
    }

    ble_command_t bleCommadData;

    while (1)
    {
        /* code */
        /* Block until a BLE command has been received over bleCommandQ */
        if(xQueueReceive(bleCommandQ, &bleCommadData,portMAX_DELAY) == pdTRUE){

        }
        ECHOLN("Test Block task BLE!");
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    
}





void callbackBluetooth(esp_spp_cb_event_t event, esp_spp_cb_param_t *param){
    if(event == ESP_SPP_SRV_OPEN_EVT){
        ECHOLN("Client Connected");
    }
    if(event == ESP_SPP_DATA_IND_EVT){
        if (param->data_ind.len < MAX_RESPONSE_LENGTH) {
            String data;
            for(int i = 0; i < param->data_ind.len; i++){
                data += (char)param->data_ind.data[i];
            }
            ECHO("data: ");
            ECHOLN(data);
            StaticJsonBuffer<MAX_RESPONSE_LENGTH> jsonBuffer;
            JsonObject& rootData = jsonBuffer.parseObject(data);
        }
    }
}
