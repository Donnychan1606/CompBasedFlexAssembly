#ifndef LIMIT_SWITCH_H
#define LIMIT_SWITCH_H

typedef struct {
    // 限位开关的引脚连接
    int pin;
    // 限位开关的状态
    int state;
} LimitSwitch;

void limit_switch_init(LimitSwitch *limit_switch);
int limit_switch_is_triggered(LimitSwitch *limit_switch);

#endif