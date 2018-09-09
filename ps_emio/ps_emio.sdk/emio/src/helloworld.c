/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"

#include "xgpiops.h"
#include "sleep.h"
int main()
{
	static XGpioPs psGpioInstancePtr;
	XGpioPs_Config* GpioConfigPtr;
	int iPinNumber= 54; //想想为什么是 54
	u32 uPinDirection = 0x1; //1 表示输出， 0 表示输入
	int xStatus;
	//--MIO 的初始化
	GpioConfigPtr = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);
	if(GpioConfigPtr == NULL)
	return XST_FAILURE;
	xStatus = XGpioPs_CfgInitialize(&psGpioInstancePtr,GpioConfigPtr,
	GpioConfigPtr->BaseAddr);
	if(XST_SUCCESS != xStatus)
	print(" PS GPIO INIT FAILED \n\r");
	//--MIO 的输入输出操作
	XGpioPs_SetDirectionPin(&psGpioInstancePtr, iPinNumber,uPinDirection);//	配置 IO 输出方向
	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, iPinNumber,1);//配置 IO	的输出
	while(1)
	{
		XGpioPs_WritePin(&psGpioInstancePtr, iPinNumber, 1);//输出 1
		sleep(1);//延时
		XGpioPs_WritePin(&psGpioInstancePtr, iPinNumber, 0);//输出 0
		sleep(1);//延时
	}
	return 0;
}
