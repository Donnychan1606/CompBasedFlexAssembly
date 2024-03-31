#include <FreeRTOS.h>
#include <task.h>
#include "three_axes_platform.h"
#include "message_center.h"
#include "stepper_motor.h"
#include "limit_switch.h"

// 瀹氫箟涓変釜姝ヨ繘鐢垫満鍜岄檺浣嶅紑鍏�
StepperMotor motor_x = {
    .pin_step = 54,    // GPIO54
    .pin_dir = 55,     // GPIO55
    .pin_enable = 56,  // GPIO56
};

StepperMotor motor_y = {
    .pin_step = 60,    // GPIO60
    .pin_dir = 61,     // GPIO61
    .pin_enable = 62,  // GPIO62
};

StepperMotor motor_z = {
    .pin_step = 63,    // GPIO63
    .pin_dir = 64,     // GPIO64
    .pin_enable = 65,  // GPIO65
};

LimitSwitch limit_switch_x = {
    .pin = 57,  // GPIO57
};

LimitSwitch limit_switch_y = {
    .pin = 58,  // GPIO58
};

LimitSwitch limit_switch_z = {
    .pin = 59,  // GPIO59
};

void three_axes_platform_task(void *pvParameters)
{
    Message msg;

    while (1) {
        // 绛夊緟娑堟伅
        //xQueueReceive(message_queue, &msg, portMAX_DELAY);

        switch (msg.id) {
            case MSG_THREE_AXES_PLATFORM_START:
                // 鍚姩涓夎酱骞冲彴
                three_axes_platform_start();
                break;

            case MSG_THREE_AXES_PLATFORM_STOP:
                // 鍋滄涓夎酱骞冲彴
                three_axes_platform_stop();
                break;

            case MSG_THREE_AXES_PLATFORM_MOVE_X:
                // X杞寸Щ鍔�
                three_axes_platform_move_x(10);
                break;

            case MSG_THREE_AXES_PLATFORM_MOVE_Y:
                // Y杞寸Щ鍔�
                three_axes_platform_move_y(10);
                break;

            case MSG_THREE_AXES_PLATFORM_MOVE_Z:
                // Z杞寸Щ鍔�
                three_axes_platform_move_z(10);
                break;

            case MSG_THREE_AXES_PLATFORM_HOME_X:
                // X杞村綊闆�
                three_axes_platform_home_x();
                break;

            case MSG_THREE_AXES_PLATFORM_HOME_Y:
                // Y杞村綊闆�
                three_axes_platform_home_y();
                break;

            case MSG_THREE_AXES_PLATFORM_HOME_Z:
                // Z杞村綊闆�
                three_axes_platform_home_z();
                break;

            case MSG_THREE_AXES_PLATFORM_HOME_ALL:
                // 鍏ㄩ儴杞村綊闆�
                three_axes_platform_home_all();
                break;

            default:
                break;
        }
    }
}

void three_axes_platform_start(void)
{
    // 鍒濆鍖栨杩涚數鏈�
    stepper_motor_init(&motor_x);
    stepper_motor_init(&motor_y);
    stepper_motor_init(&motor_z);

    // 鍒濆鍖栭檺浣嶅紑鍏�
    limit_switch_init(&limit_switch_x);
    limit_switch_init(&limit_switch_y);
    limit_switch_init(&limit_switch_z);

    // 骞冲彴鍒濆鍖�,绉诲姩鍒板師鐐逛綅缃�
    three_axes_platform_home_all();
}

void three_axes_platform_stop(void)
{
    // 鍋滄鎵�鏈夋杩涚數鏈�
    stepper_motor_stop(&motor_x);
    stepper_motor_stop(&motor_y);
    stepper_motor_stop(&motor_z);
}

void three_axes_platform_move_x(int steps)
{
    // X杞寸Щ鍔ㄦ寚瀹氱殑姝ユ暟
    stepper_motor_move(&motor_x, steps);
}

void three_axes_platform_move_y(int steps)
{
    // Y杞寸Щ鍔ㄦ寚瀹氱殑姝ユ暟
    stepper_motor_move(&motor_y, steps);
}

void three_axes_platform_move_z(int steps)
{
    // Z杞寸Щ鍔ㄦ寚瀹氱殑姝ユ暟
    stepper_motor_move(&motor_z, steps);
}

void three_axes_platform_home_x(void)
{
    // X杞村綊闆�,绉诲姩鐩村埌瑙﹀彂闄愪綅寮�鍏�
    while (!limit_switch_is_triggered(&limit_switch_x)) {
        stepper_motor_move(&motor_x, -1);
    }
}

void three_axes_platform_home_y(void)
{
    // Y杞村綊闆�,绉诲姩鐩村埌瑙﹀彂闄愪綅寮�鍏�
    while (!limit_switch_is_triggered(&limit_switch_y)) {
        stepper_motor_move(&motor_y, -1);
    }
}

void three_axes_platform_home_z(void)
{
    // Z杞村綊闆�,绉诲姩鐩村埌瑙﹀彂闄愪綅寮�鍏�
    while (!limit_switch_is_triggered(&limit_switch_z)) {
        stepper_motor_move(&motor_z, -1);
    }
}

void three_axes_platform_home_all(void)
{
    // 鍏ㄩ儴杞村綊闆�
    three_axes_platform_home_x();
    three_axes_platform_home_y();
    three_axes_platform_home_z();
}
