#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
#include "string.h"
#include "Servo.h"


uint8_t RxSTA = 1;
float Angle;			//定义角度变量

int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	Serial_Init();		//串口初始化
	Servo_Init();		//舵机初始化

	/*显示静态字符串*/
	OLED_ShowString(1, 1, "TxPacket");
	OLED_ShowString(3, 1, "RxPacket");

	
	
	while (1)
	{
		
		if (Serial_RxFlag == 1)		//如果接收到数据包
		{
			
			OLED_ShowString(4, 1, Serial_RxPacket);				//OLED清除指定位置，并显示接收到的数据包
			
			/*将收到的数据包与预设的指令对比，以此决定将要执行的操作*/
			if (strcmp(Serial_RxPacket, "Five") == 0)			//如果收到Five指令
			{
				Serial_SendString("Five_OK\r\n");				//串口回传一个字符串Five_OK
				OLED_ShowString(2, 1, "                ");
				OLED_ShowString(2, 1, "Five_OK");				//OLED清除指定位置，并显示Five_OK
				
				Angle += 30;				//角度变量自增30
				if (Angle > 180)			//角度变量超过180后
					{
						Angle = 0;				//角度变量归零
					}

			}
			else if (strcmp(Serial_RxPacket, "Zero") == 0)	//如果收到Zero指令
			{
									
				Serial_SendString("Zero_OK\r\n");			//串口回传一个字符串Zero_OK
				OLED_ShowString(2, 1, "                ");
				OLED_ShowString(2, 1, "Zero_OK");			//OLED清除指定位置，并显示Zero_OK

				Angle += 30;				//角度变量自增30
				if (Angle > 180)			//角度变量超过180后
					{
						Angle = 0;				//角度变量归零
					}

			}
			
			else if (strcmp(Serial_RxPacket, "Yeah") == 0)	//如果收到Yeah指令
			{
								
				Serial_SendString("Yeah_OK\r\n");			//串口回传一个字符串Yeah_OK
				OLED_ShowString(2, 1, "                ");
				OLED_ShowString(2, 1, "Yeah_OK");			//OLED清除指定位置，并显示Yeah_OK
				
				Angle += 30;				//角度变量自增30
				if (Angle > 180)			//角度变量超过180后
					{
						Angle = 0;				//角度变量归零
					}

			}
			
			else if (strcmp(Serial_RxPacket, "Close") == 0)	//如果收到Close指令
			{

				Serial_SendString("Close_OK\r\n");			//串口回传一个字符串Close_OK
				OLED_ShowString(2, 1, "                ");
				OLED_ShowString(2, 1, "Close_OK");			//OLED清除指定位置，并显示Close_OK

				Angle += 30;				//角度变量自增30
				if (Angle > 180)			//角度变量超过180后
					{
						Angle = 0;				//角度变量归零
					}
			}
					
			else if (strcmp(Serial_RxPacket, "One") == 0)	//如果收到One指令
			{
				Serial_SendString("One_OK\r\n");			//串口回传一个字符串One_OK
				OLED_ShowString(2, 1, "                ");
				OLED_ShowString(2, 1, "One_OK");			//OLED清除指定位置，并显示One_OK

				Angle += 30;				//角度变量自增30
				if (Angle > 180)			//角度变量超过180后
					{
						Angle = 0;				//角度变量归零
					}
			}
			
			else						//上述所有条件均不满足，即收到了未知指令
			{
				Serial_SendString("ERROR_COMMAND\r\n");			//串口回传一个字符串ERROR_COMMAND
				OLED_ShowString(2, 1, "                ");
				OLED_ShowString(2, 1, "ERROR_COMMAND");			//OLED清除指定位置，并显示ERROR_COMMAND
			}
			
			Serial_RxFlag = 0;			//处理完成后，需要将接收数据包标志位清零，否则将无法接收后续数据包
		}
	}
}
