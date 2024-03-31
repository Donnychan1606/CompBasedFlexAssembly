#include "limit_switch.h"
#include "xgpiops.h"  


static XGpioPs gpio_inst;

void limit_switch_init(LimitSwitch *limit_switch)
{
    // 鍒濆鍖朑PIO椹卞姩
//    XGpioPs_Config *gpio_config = XGpioPs_LookupConfig(XPAR_PS7_QSPI_0_DEVICE_ID);
//    XGpioPs_CfgInitialize(&gpio_inst, gpio_config, gpio_config->BaseAddr);
//
//    // 璁剧疆闄愪綅寮�鍏崇殑寮曡剼涓鸿緭鍏ユā寮�
//    XGpioPs_SetDirectionPin(&gpio_inst, limit_switch->pin, 0);

    // 鍒濆鍖栭檺浣嶅紑鍏崇殑鐘舵��
    limit_switch->state = 0;
}

int limit_switch_is_triggered(LimitSwitch *limit_switch)
{
    // 璇诲彇闄愪綅寮�鍏崇殑鐘舵��
//    limit_switch->state = XGpioPs_ReadPin(&gpio_inst, limit_switch->pin);

    return limit_switch->state;
}
