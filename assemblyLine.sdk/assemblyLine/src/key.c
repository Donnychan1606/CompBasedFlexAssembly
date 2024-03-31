/*
 * key.c
 *
 *  Created on: 2022年9月30日
 *      Author: Administrator
 */


#include <stdio.h>
#include "stdint-gcc.h"
#include "xil_printf.h"
#include "xgpiops.h"
#include "xgpiops_hw.h"
#include "key.h"
#include "sleep.h"



#define input 0
#define output 1

XGpioPs Gpios;

//延时函数
//void delay(int count)
//{
//	int i;
//	for(i=1;i<=count;i++)
//	;
//}


void Key_Init()
{
//	XGpioPs_SetDirectionPin(&Gpios,KEY1,input);
}


