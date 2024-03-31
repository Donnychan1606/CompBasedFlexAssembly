#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

typedef struct {
    // 步进电机的引脚连接
    int pin_step;
    int pin_dir;
    int pin_enable;
    // 步进电机的状态
    int position;
    int speed;
} StepperMotor;

void stepper_motor_init(StepperMotor *motor);
void stepper_motor_move(StepperMotor *motor, int steps);
void stepper_motor_stop(StepperMotor *motor);

#endif