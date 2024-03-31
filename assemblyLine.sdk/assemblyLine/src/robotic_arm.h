#ifndef ROBOTIC_ARM_H
#define ROBOTIC_ARM_H

#include "FreeRTOS.h"
#include "queue.h"

// 鏈烘鑷傜浉鍏虫秷鎭疘D
#define MSG_ROBOTIC_ARM_START   1
#define MSG_ROBOTIC_ARM_STOP    2
#define MSG_ROBOTIC_ARM_LOAD    3
#define MSG_ROBOTIC_ARM_UNLOAD  4
#define MSG_ROBOTIC_ARM_HOME    5

// 鏈烘鑷備换鍔″弬鏁�
#define ROBOTIC_ARM_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define ROBOTIC_ARM_TASK_PRIORITY   (tskIDLE_PRIORITY + 1)

// 鐗╀綋鍜岀洰鏍囦綅缃殑鍧愭爣
#define OBJECT_POSITION_X   100
#define OBJECT_POSITION_Y   200
#define OBJECT_POSITION_Z   300
#define TARGET_POSITION_X   400
#define TARGET_POSITION_Y   500
#define TARGET_POSITION_Z   600

// 鏈烘鑷備换鍔�
void robotic_arm_task(void *pvParameters);

// 鍚姩鏈烘鑷�
void robotic_arm_start(void);

// 鍋滄鏈烘鑷�
void robotic_arm_stop(void);

// 鎵ц涓婃枡鍔ㄤ綔
void robotic_arm_load(void);

// 鎵ц涓嬫枡鍔ㄤ綔
void robotic_arm_unload(void);

// 绉诲姩鏈烘鑷傚簳搴�
void robotic_arm_move_base(int steps);

void robotic_arm_move_shoulder(int steps);

void robotic_arm_move_elbow(int steps);

void robotic_arm_move_wrist(int steps);

void robotic_arm_move_to(int x, int y, int z);

// 鏈烘鑷傚簳搴у綊闆�
void robotic_arm_home_base(void);

void robotic_arm_home_shoulder(void);

void robotic_arm_home_elbow(void);

void robotic_arm_home_wrist(void);

// 鏈烘鑷傛暣浣撳綊闆�
void robotic_arm_home(void);

#endif // ROBOTIC_ARM_H
