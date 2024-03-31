#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "FreeRTOS.h"
#include "queue.h"

// 状态机相关消息ID
#define MSG_START               1
#define MSG_LOADING_DONE        2
#define MSG_PROCESSING_DONE     3
#define MSG_UNLOADING_DONE      4
#define MSG_PRINT_START         5
#define MSG_PRINT_DONE          6

// 其他模块相关消息ID
#define MSG_MOTOR_INIT          101
#define MSG_SENSOR_INIT         102
#define MSG_CONVEYOR_START      103
#define MSG_ROBOTIC_ARM_LOAD    104
#define MSG_ROBOTIC_ARM_UNLOAD  105
#define MSG_THREE_AXES_PLATFORM_START   106
#define MSG_PRINT_HEAD_START    107

// 状态机任务参数
#define STATE_MACHINE_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define STATE_MACHINE_TASK_PRIORITY   (tskIDLE_PRIORITY + 1)

// 状态机任务
void state_machine_task(void *pvParameters);

#endif // STATE_MACHINE_H