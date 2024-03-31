#include "stepper_motor.h"
#include "xgpiops.h"  


static XGpioPs gpio_inst;

void stepper_motor_init(StepperMotor *motor)
{

    // 鍒濆鍖栨杩涚數鏈虹殑鐘舵��
    motor->position = 0;
    motor->speed = 0;
}

void stepper_motor_move(StepperMotor *motor, int steps)
{
//    // 璁剧疆姝ヨ繘鐢垫満鐨勬柟鍚�
//    if (steps > 0) {
//        // 璁剧疆涓烘鏂瑰悜
//        XGpioPs_WritePin(&gpio_inst, motor->pin_dir, 1);
//    } else {
//        // 璁剧疆涓鸿礋鏂瑰悜
//        XGpioPs_WritePin(&gpio_inst, motor->pin_dir, 0);
//    }
//
//    XGpioPs_WritePin(&gpio_inst, motor->pin_enable, 1);
//
//    for (int i = 0; i < abs(steps); i++) {
//        // 鍙戦�佷竴涓剦鍐�
//        XGpioPs_WritePin(&gpio_inst, motor->pin_step, 1);
//        usleep(motor->speed);  // 寤舵椂,鎺у埗閫熷害
//        XGpioPs_WritePin(&gpio_inst, motor->pin_step, 0);
//        usleep(motor->speed);  // 寤舵椂,鎺у埗閫熷害
//    }
//
//    // 绂佺敤姝ヨ繘鐢垫満
//    XGpioPs_WritePin(&gpio_inst, motor->pin_enable, 0);

    // 鏇存柊姝ヨ繘鐢垫満鐨勪綅缃�
    motor->position += steps;
}

void stepper_motor_stop(StepperMotor *motor)
{
//    XGpioPs_WritePin(&gpio_inst, motor->pin_enable, 0);
}

void stepper_motor_set_speed(StepperMotor *motor, int speed)
{
    // 璁剧疆姝ヨ繘鐢垫満鐨勯�熷害
    motor->speed = speed;
}
