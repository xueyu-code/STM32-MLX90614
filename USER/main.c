#include "delay.h"
#include "sys.h"	 
#include "mlx90614.h" 
#include "oled.h"
#include "string.h"
#include "BEEP.h"

int main(void)
{	
	
	char A[]="Tem : ";
  float Temperature = 0;    //温度数据变量（浮点型）
  char TempValue[80] = {0};
  char BuChang[80] = {0};	//补偿值
	delay_init();	  //延时函数初始化
	OLED_Init()	;
	OLED_Clear();
	BEEP_Init();
  SMBus_Init();
  display();
	while(1)
	{		
			//由于经费所限，测温模块的有效范围是2cm左右处，超过该范围会失真
			Temperature=SMBus_ReadTemp();
			sprintf(TempValue,"%.1f", Temperature); //浮点型转换成字符串			
			OLED_ShowString(40,4,(uint8_t *)TempValue,16);//在在OLED上显示实际测量的温度
			//进行是否出现发热症状的判断
			if(Temperature>37)
			{
			//大于37度显示过高
				Warning();
				BEEP_ON();
			}
			else
			safe();//温度正常显示正常信息
		
	}
			
	
}

