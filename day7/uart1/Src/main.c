/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "switch.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	int cnt = 0;
	char str[32];
	SystemInit();
	SwitchInit(SWITCH);
	UartInit(BAUD_9600);
	UartPuts("External intrupt count.\n");
	while(1) {
            // wait until switch interrupt generated
			while(exti0_flag == 0)
					;
				// Blink the Led
				LedBlink(LED_BLUE, 10);
				//exti0_flag = 0;
				sprintf(str, "CNT=%d\r",cnt);
				cnt++;
				//print count on serial port
				UartPuts(str);
				exti0_flag = 0;

		//UartGets(str);
		//strupr(str);
		//UartPuts(str);

	}
	return 0;
}
