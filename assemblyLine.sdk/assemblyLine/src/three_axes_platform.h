#ifndef THREE_AXES_PLATFORM_H
#define THREE_AXES_PLATFORM_H

#include "FreeRTOS.h"
#include "queue.h"

// 涓夎酱骞冲彴鐩稿叧娑堟伅ID
#define MSG_THREE_AXES_PLATFORM_START       1
#define MSG_THREE_AXES_PLATFORM_STOP        2
#define MSG_THREE_AXES_PLATFORM_MOVE_X      3
#define MSG_THREE_AXES_PLATFORM_MOVE_Y      4
#define MSG_THREE_AXES_PLATFORM_MOVE_Z      5
#define MSG_THREE_AXES_PLATFORM_HOME_X      6
#define MSG_THREE_AXES_PLATFORM_HOME_Y      7
#define MSG_THREE_AXES_PLATFORM_HOME_Z      8
#define MSG_THREE_AXES_PLATFORM_HOME_ALL    9

// 涓夎酱骞冲彴浠诲姟鍙傛暟
#define THREE_AXES_PLATFORM_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define THREE_AXES_PLATFORM_TASK_PRIORITY   (tskIDLE_PRIORITY + 1)

// 涓夎酱骞冲彴浠诲姟
void three_axes_platform_task(void *pvParameters);

void three_axes_platform_start(void);

void three_axes_platform_stop(void);

void three_axes_platform_move_x(int steps);

void three_axes_platform_move_y(int steps);

void three_axes_platform_move_z(int steps);

void three_axes_platform_home_x(void);
void three_axes_platform_home_y(void);
void three_axes_platform_home_z(void);

// 鍏ㄩ儴杞村綊闆�
void three_axes_platform_home_all(void);

#endif // THREE_AXES_PLATFORM_H
