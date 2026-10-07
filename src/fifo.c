#include <FreeRTOS.h>
#include <pico/stdlib.h>
#include <pico/multicore.h>
#include <pico/cyw43_arch.h>
#include <stdio.h>

#include "signaling.h"
#include "fifo.h"

void fifo_worker_handler(QueueHandle_t requests, QueueHandle_t results, int id)
{
    while(1) {
        printf("Taking in request");
        struct request_msg message = {};
        xQueueReceive(requests, &message, portMAX_DELAY);
        message.output = message.input + 5;
        message.handled_by = id;
        printf("finished outputing");
        xQueueSend(results, &message, portMAX_DELAY);
    }

}