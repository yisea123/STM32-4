#ifndef __CONFIG_H
#define __CONFIG_H
/* 该文件包括了一些常用的控制系统配置选项，自己写的代码都应该包括该头文件 */

#include "macro_operate.h"				// 宏操作

/* 系统功能开关： 1--打开测试代码，0--关闭 */
// 开发板上的测试代码，方便在探索者板子上验证代码
#define _TEST_ON_ALIENTEK 1

/*  系统时钟 */
#define _SYSCLK	168								// 系统时钟168MHz

/* 串口设置 USART1 USART2 USART3  */
#define 	EN_USART1 	1						// 如使能串口2： EN_USART2 	1
#define 	BOUND_X			115200

/* LED IO口 */
#define 	GPIO_LED				"PF9"

/* 限位 IO口 */
#define 	X_P_LIMIT 			"PE2"					// X+限位
#define 	X_N_LIMIT 			"PE3"					// X-限位 兼用为X零位
#define 	Y_P_LIMIT 			"PA11"					// Y+限位
#define 	Y_N_LIMIT 			"PA11"					// Y-限位 兼用为Y零位
#define 	Z_P_LIMIT 			"PA11"					// Z+限位
#define 	Z_N_LIMIT 			"PA11"					// Z-限位 兼用为Z零位
#define 	A_LIMIT 				"PA11"					// A零位
#define 	B_LIMIT 				"PA11"					// B零位

/******* 中断IO口  注意：如PA11只能连接到中断线11 ***********/
/* 步进电机的相关IO口  方向、中断及输出IO口 注：PWM的IO口不能随便选择！ */
#define 	EXTI_X_PLUS			"PC4" 		/* 中断线4 */				// 接收PWM的中断IO口
#define 	PWM_X_EXTI			"PA7"			/* TIM3_CH2 */			// 输出PWM到中断的IO口   	
//#define 	PWM_X_OUT				"PA6"  		/* TIM3_CH1 */			// 输出PWM到电机的IO口		
#define 	PWM_X_OUT				"PB4"  		/* TIM3_CH1 */			// 输出PWM到电机的IO口		 探索者板子上用
#define 	DIR_X						"PA4" 		/*          */ 			// 电机运动方向

#if _TEST_ON_ALIENTEK
	#define 	EXTI_Y_PLUS			"PA2"			/* 中断线2  */		// 接收PWM的中断IO口  探索者板子上不能用中断线1，初始化时会被打断
#else
	#define 	EXTI_Y_PLUS			"PA1"			/* 中断线1  */		// 接收PWM的中断IO口  
#endif
#define 	PWM_Y_EXTI			"PA3"			/* TIM2_CH4 */			// 输出PWM到中断的IO口   	
#define 	PWM_Y_OUT				"PA5"  		/* TIM2_CH1 */			// 输出PWM到电机的IO口
#define 	DIR_Y						"PC3" 		/*          */ 			// 电机运动方向

#define 	EXTI_Z_PLUS			"PB6"			/* 中断线6 */				// 接收PWM的中断IO口
#define 	PWM_Z_EXTI			"PB8"			/* TIM4_CH3 */			// 输出PWM到中断的IO口
#define 	PWM_Z_OUT				"PB9"  		/* TIM4_CH4 */			// 输出PWM到电机的IO口
#define 	DIR_Z						"PB7" 		/*          */ 			// 电机运动方向

#define 	EXTI_A_PLUS			"XXX"			/* 中断线11 */			// 接收PWM的中断IO口
#define 	PWM_A_EXTI			"PE6"			/* TIM3_CH1 */			// 输出PWM到中断的IO口
#define 	PWM_A_OUT				"XXX"  		/* TIM3_CH1 */			// 输出PWM到电机的IO口
#define 	DIR_A						"XXX" 		/*          */ 			// 电机运动方向

#define 	EXTI_B_PLUS			"XXX"			/* 中断线11 */			// 接收PWM的中断IO口
#define 	PWM_B_EXTI			"PB14"		/* TIM3_CH1 */			// 输出PWM到中断的IO口
#define 	PWM_B_OUT				"XXX"  		/* TIM3_CH1 */			// 输出PWM到电机的IO口
#define 	DIR_B						"XXX" 		/*          */ 			// 电机运动方向



// 测试按钮中断 可以删除
#define 	_KEY1 						"XXX" 		// 按下后拉高
//#define 	_KEY1 						"PE3" 		// 按下后拉低



/*********串口通信协议**********/
#define FrameB1 		0x0E     //数据帧头
#define FrameB2			0x09     //数据帧头
#define FrameEnd		0xFF     //数据帧尾

/*********串口通信数据帧控制字**********/
#define SELFCHECK 		0x0B     	// 自检
#define CONTROLINFO		0x0C     	// 控制
#define DATAINFO			0x0D     	// 数据
#define STATUSINFO		0x0E     	// 状态
#define INVALID_CMD 	0x00 			// 无效命令，默认状态或没有新命令

/* 	0x0D // 数据 : 对应指令码	 */
#define PLUS_DATA				0x22			// 脉冲数据处理
#define OFFLINE_DATA		0x25			// 脱机加工指令码

/* 限位回复信息 */
#define X_P_MSG1  	0x31			// X+ 限位
#define X_P_MSG2  	0x01			// X+ 限位

#define X_N_MSG1  	0x31			// X- 限位
#define X_N_MSG2  	0x02			// X- 限位

#define Y_P_MSG1  	0x32			// Y+ 限位
#define Y_P_MSG2  	0x01			// Y+ 限位

#define Y_N_MSG1  	0x32			// Y- 限位
#define Y_N_MSG2  	0x02			// Y- 限位

#define Z_P_MSG1  	0x33			// Z+ 限位
#define Z_P_MSG2  	0x01			// Z+ 限位

#define Z_N_MSG1  	0x33			// Z- 限位
#define Z_N_MSG2  	0x02			// Z- 限位

#define A_MSG1  		0x35			// A 零位
#define A_MSG2  		0x03			// A 零位

#define B_MSG1  		0x36			// B 零位
#define B_MSG2  		0x03			// B 零位

/* 运动系统的运动轴数量  */
#define AXIS_NUM 		5     	// 5轴系统 顺序：X、Y、Z、A、B

// 尺寸链包含有问题，暂时未解决，先放在这
typedef enum {TBD_DIR = 0, POS_DIR = 1, NEG_DIR = 2} Motor_Dir; 		// 电机运动方向


#endif
