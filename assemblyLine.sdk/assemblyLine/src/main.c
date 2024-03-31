#include <FreeRTOS.h>
#include <queue.h>
#include "state_machine.h"
#include "robotic_arm.h"
#include "three_axes_platform.h" 

QueueHandle_t message_queue;

int main(void)
{

    // 鍒涘缓浠诲姟
    xTaskCreate(state_machine_task, "StateMachine", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(robotic_arm_task, "RoboticArm", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
    xTaskCreate(three_axes_platform_task, "ThreeAxesPlatform", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
    //xTaskCreate(Print_Ready, "PrintHead", configMINIMAL_STACK_SIZE, NULL, 3, NULL);

    // 鍚姩璋冨害鍣�
    vTaskStartScheduler();

    return 0;
}
