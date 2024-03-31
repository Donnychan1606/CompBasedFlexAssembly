#include <FreeRTOS.h>
#include <task.h>
#include "robotic_arm.h"
#include "stepper_motor.h"
#include "limit_switch.h"

// 瀹氫箟4涓杩涚數鏈哄拰闄愪綅寮�鍏�
StepperMotor motor_base = {
    .pin_step = 70,    // GPIO70
    .pin_dir = 71,     // GPIO71
    .pin_enable = 72,  // GPIO72
};

StepperMotor motor_shoulder = {
    .pin_step = 73,    // GPIO73
    .pin_dir = 74,     // GPIO74
    .pin_enable = 75,  // GPIO75
};

StepperMotor motor_elbow = {
    .pin_step = 76,    // GPIO76
    .pin_dir = 77,     // GPIO77
    .pin_enable = 78,  // GPIO78
};

StepperMotor motor_wrist = {
    .pin_step = 79,    // GPIO79
    .pin_dir = 80,     // GPIO80
    .pin_enable = 81,  // GPIO81
};

LimitSwitch limit_switch_base = {
    .pin = 82,  // GPIO82
};

LimitSwitch limit_switch_shoulder = {
    .pin = 83,  // GPIO83
};

LimitSwitch limit_switch_elbow = {
    .pin = 84,  // GPIO84
};

LimitSwitch limit_switch_wrist = {
    .pin = 85,  // GPIO85
};

void robotic_arm_task(void *pvParameters)
{
//    Message msg;
//
//    while (1) {
//        // 绛夊緟娑堟伅
//        //xQueueReceive(message_queue, &msg, portMAX_DELAY);
//
//        switch (msg.id) {
//            case MSG_ROBOTIC_ARM_START:
//                // 鍚姩鏈烘鑷�
//                robotic_arm_start();
//                break;
//
//            case MSG_ROBOTIC_ARM_STOP:
//                // 鍋滄鏈烘鑷�
//                robotic_arm_stop();
//                break;
//
//            case MSG_ROBOTIC_ARM_LOAD:
//                // 鎵ц涓婃枡鍔ㄤ綔
//                robotic_arm_load();
//                // 鍙戦�佷笂鏂欏畬鎴愭秷鎭�
//                //xQueueSend(message_queue, &(Message){MSG_LOADING_DONE}, 0);
//                break;
//
//            case MSG_ROBOTIC_ARM_UNLOAD:
//                // 鎵ц涓嬫枡鍔ㄤ綔
//                robotic_arm_unload();
//                // 鍙戦�佷笅鏂欏畬鎴愭秷鎭�
//                //xQueueSend(message_queue, &(Message){MSG_UNLOADING_DONE}, 0);
//                break;
//
//            case MSG_ROBOTIC_ARM_HOME:
//                // 鏈烘鑷傚綊闆�
//                robotic_arm_home();
//                break;
//
//            default:
//                break;
//        }
//    }
}

void robotic_arm_start(void)
{
    // 鍒濆鍖栨杩涚數鏈�
    stepper_motor_init(&motor_base);
    stepper_motor_init(&motor_shoulder);
    stepper_motor_init(&motor_elbow);
    stepper_motor_init(&motor_wrist);

    // 鍒濆鍖栭檺浣嶅紑鍏�
    limit_switch_init(&limit_switch_base);
    limit_switch_init(&limit_switch_shoulder);
    limit_switch_init(&limit_switch_elbow);
    limit_switch_init(&limit_switch_wrist);

    // 鍒濆鍖栧惛澶�

    // 鏈烘鑷傚垵濮嬪寲,绉诲姩鍒板師鐐逛綅缃�
    robotic_arm_home();
}

void robotic_arm_stop(void)
{
    // 鍋滄鎵�鏈夋杩涚數鏈�
    stepper_motor_stop(&motor_base);
    stepper_motor_stop(&motor_shoulder);
    stepper_motor_stop(&motor_elbow);
    stepper_motor_stop(&motor_wrist);
}

void robotic_arm_load(void)
{
    // 绉诲姩鍒扮墿浣撲綅缃�
    robotic_arm_move_to(OBJECT_POSITION_X, OBJECT_POSITION_Y, OBJECT_POSITION_Z);


    // 绉诲姩鍒扮洰鏍囦綅缃�
    robotic_arm_move_to(TARGET_POSITION_X, TARGET_POSITION_Y, TARGET_POSITION_Z);

}

void robotic_arm_unload(void)
{
    // 绉诲姩鍒扮墿浣撲綅缃�
    robotic_arm_move_to(TARGET_POSITION_X, TARGET_POSITION_Y, TARGET_POSITION_Z);


    // 绉诲姩鍒扮洰鏍囦綅缃�
    robotic_arm_move_to(OBJECT_POSITION_X, OBJECT_POSITION_Y, OBJECT_POSITION_Z);

}

void robotic_arm_move_base(int steps)
{
    stepper_motor_move(&motor_base, steps);
}

void robotic_arm_move_shoulder(int steps)
{
    stepper_motor_move(&motor_shoulder, steps);
}

void robotic_arm_move_elbow(int steps)
{
    stepper_motor_move(&motor_elbow, steps);
}

void robotic_arm_move_wrist(int steps)
{
    stepper_motor_move(&motor_wrist, steps);
}

void robotic_arm_move_to(int x, int y, int z)
{
    // 绉诲姩鍒版寚瀹氱殑鍧愭爣浣嶇疆
    // 杩欓噷闇�瑕佹牴鎹満姊拌噦鐨勭粨鏋勫拰杩愬姩瀛︽ā鍨�,璁＄畻姣忎釜鍏宠妭闇�瑕佺Щ鍔ㄧ殑姝ユ暟
//    int base_steps = calculate_base_steps(x, y, z);
//    int shoulder_steps = calculate_shoulder_steps(x, y, z);
//    int elbow_steps = calculate_elbow_steps(x, y, z);
//    int wrist_steps = calculate_wrist_steps(x, y, z);
//
//    robotic_arm_move_base(base_steps);
//    robotic_arm_move_shoulder(shoulder_steps);
//    robotic_arm_move_elbow(elbow_steps);
//    robotic_arm_move_wrist(wrist_steps);
}

void robotic_arm_home_base(void)
{
    while (!limit_switch_is_triggered(&limit_switch_base)) {
        stepper_motor_move(&motor_base, -1);
    }
}

void robotic_arm_home_shoulder(void)
{
    while (!limit_switch_is_triggered(&limit_switch_shoulder)) {
        stepper_motor_move(&motor_shoulder, -1);
    }
}

void robotic_arm_home_elbow(void)
{
    while (!limit_switch_is_triggered(&limit_switch_elbow)) {
        stepper_motor_move(&motor_elbow, -1);
    }
}

void robotic_arm_home_wrist(void)
{
    while (!limit_switch_is_triggered(&limit_switch_wrist)) {
        stepper_motor_move(&motor_wrist, -1);
    }
}

void robotic_arm_home(void)
{
    // 鏈烘鑷傚綊闆�
    robotic_arm_home_base();
    robotic_arm_home_shoulder();
    robotic_arm_home_elbow();
    robotic_arm_home_wrist();
}
