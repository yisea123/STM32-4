#ifndef __EXTI_H
#define __EXTI_H	 
#include "sys.h"  	
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//外部中断 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/4
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 

#include "ChangeTools.h"		// 包含了换刀步数的结构体
#include "AddSubSpeed.h"

#define xPWMCnt pwmNumTim3
#define yPWMCnt pwmNumTim2	
#define zPWMCnt pwmNumTim4	
#define aPWMCnt pwmNumTim9	
#define bPWMCnt pwmNumTim12	

#define xSetPWMCnt(cnt) (pwmNumTim3 = (cnt))
#define ySetPWMCnt(cnt) (pwmNumTim2 = (cnt))
#define zSetPWMCnt(cnt) (pwmNumTim4 = (cnt))
#define aSetPWMCnt(cnt) (pwmNumTim9 = (cnt))
#define bSetPWMCnt(cnt) (pwmNumTim12 = (cnt))

void EXTIX_Init(void);	//外部中断初始化		 					   

// 设置标志位，记录走过的脉冲数用
extern u8 stepsFlag[5]; 				// 打开X、Y、Z、A、B的计数 1：打开； 0：关闭

// 记录走过多少脉冲
extern ChangeToolsSavedSteps stepsTemp;


#endif

























