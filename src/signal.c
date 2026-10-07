#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>
#include "signaling.h"






void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data){
    printf("Waiting on the Request\n");
    xSemaphoreTake(request, portMAX_DELAY );
    printf("Thread created\n");
    data->output= data->input +5;
    printf("Data inremented\n");
    xSemaphoreGive(response);
    vTaskDelay(100);
}


BaseType_t signal_request_calculate(SemaphoreHandle_t request,
                                    SemaphoreHandle_t response,
                                    struct signal_data *data){
printf("Starting to signal Response");
xSemaphoreGive(request,( TickType_t ) 10 ) == pdTRUE);
printf("Request Calculated");
BaseType_t response = xSemaphoreTake(response,portMAX_DELAY);
printf("Responded to the request");

return response;
                                    }