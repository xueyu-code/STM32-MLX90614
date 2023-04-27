#include "delay.h"
#include "sys.h"	 
#include "mlx90614.h" 
#include "oled.h"
#include "string.h"
#include "BEEP.h"

int main(void)
{	
	
	char A[]="Tem : ";
  float Temperature = 0;    //�¶����ݱ����������ͣ�
  char TempValue[80] = {0};
  char BuChang[80] = {0};	//����ֵ
	delay_init();	  //��ʱ������ʼ��
	OLED_Init()	;
	OLED_Clear();
	BEEP_Init();
  SMBus_Init();
  display();
	while(1)
	{		
			//���ھ������ޣ�����ģ�����Ч��Χ��2cm���Ҵ��������÷�Χ��ʧ��
			Temperature=SMBus_ReadTemp();
			sprintf(TempValue,"%.1f", Temperature); //������ת�����ַ���			
			OLED_ShowString(40,4,(uint8_t *)TempValue,16);//����OLED����ʾʵ�ʲ������¶�
			//�����Ƿ���ַ���֢״���ж�
			if(Temperature>37)
			{
			//����37����ʾ����
				Warning();
				BEEP_ON();
			}
			else
			safe();//�¶�������ʾ������Ϣ
		
	}
			
	
}

