# include "stm32f10x.h"
# include "oled.h"
# include "stdlib.h"
# include "oledfont.h"

	//温度的单位 ℃
unsigned char TempCompany[][16]=
{
	0x06,0x09,0x09,0xE6,0xF8,0x0C,0x04,0x02,0x02,0x02,0x02,0x02,0x04,0x1E,0x00,0x00,
	0x00,0x00,0x00,0x07,0x1F,0x30,0x20,0x40,0x40,0x40,0x40,0x40,0x20,0x10,0x00,0x00,/*"℃",0*/	

};
 unsigned char LOGO1[][16]=
{
		{0x08,0x88,0x88,0x88,0x88,0xFF,0x00,0x00,//非
		0x00,0xFF,0x88,0x88,0xC8,0x8C,0x08,0x00},
		{0x10,0x10,0x10,0x10,0x10,0xFF,0x00,0x00,
		0x00,0xFF,0x10,0x10,0x10,0x18,0x10,0x00},

		{0x10,0x10,0x10,0xFF,0x90,0x54,0x44,0x54,//接
		0xE5,0x46,0x64,0x54,0x46,0x44,0x00,0x00},
		{0x02,0x42,0x81,0x7F,0x02,0x02,0x82,0x8A,
		0x57,0x22,0x32,0x4E,0xC2,0x03,0x02,0x00},

	    {0x20,0xF8,0x27,0xF4,0x2C,0xE4,0x00,0xF0,//触
		0x10,0x10,0xFF,0x10,0x10,0xF8,0x10,0x00},
		{0x80,0x7F,0x09,0x7F,0x89,0xFF,0x00,0x4F,
		0xC4,0x44,0x7F,0x24,0x34,0x27,0xC0,0x00},

	    {0x10,0x10,0x90,0x90,0x90,0x90,0x90,0x10,//式
		0xFF,0x10,0x12,0x14,0x10,0x18,0x10,0x00},
		{0x00,0x20,0x60,0x20,0x1F,0x10,0x10,0x08,
		0x01,0x06,0x18,0x20,0x40,0x80,0x70,0x00},

	    {0x20,0x30,0xAC,0x63,0x20,0x10,0x04,0x04,//红
		0x04,0x04,0xFC,0x04,0x06,0x04,0x00,0x00},
		{0x22,0x67,0x22,0x12,0x12,0x52,0x40,0x40,
		0x40,0x40,0x7F,0x40,0x40,0x60,0x40,0x00},

	    {0x00,0x80,0xE0,0x18,0x17,0x10,0x90,0x70,//外
		0x00,0xFF,0x20,0x40,0x80,0x00,0x00,0x00},
		{0x01,0x40,0x20,0x11,0x0A,0x04,0x03,0x00,
		0x00,0xFF,0x00,0x00,0x00,0x01,0x03,0x00},

	    {0x10,0x22,0x6C,0x00,0x80,0xFC,0x04,0xF4,//测
		0x04,0xFE,0x04,0xF8,0x00,0xFE,0x00,0x00},
		{0x04,0x04,0xFE,0x01,0x40,0x27,0x10,0x0F,
		0x10,0x67,0x00,0x47,0x80,0x7F,0x00,0x00},

	    {0x10,0x22,0x64,0x0C,0x80,0x00,0xFE,0x92,//温
		0x92,0x92,0x92,0x92,0xFF,0x02,0x00,0x00},
		{0x04,0x04,0xFE,0x01,0x40,0x7E,0x42,0x42,
		0x7E,0x42,0x7E,0x42,0x42,0x7E,0x40,0x00},

	    {0x00,0x00,0xFC,0x24,0x24,0x24,0xFC,0xA5,//度
		0xA6,0xA4,0xFC,0x24,0x34,0x26,0x04,0x00},
		{0x40,0x20,0x9F,0x80,0x42,0x42,0x26,0x2A,
		0x12,0x2A,0x26,0x42,0x40,0xC0,0x40,0x00},
		
		{0x10,0x10,0x10,0x11,0xD6,0x30,0x98,0x00,//补
        0x00,0xFF,0x40,0x80,0x00,0x00,0x00,0x00},
        {0x08,0x04,0x02,0x01,0xFF,0x01,0x02,0x00,
        0x00,0xFF,0x00,0x00,0x01,0x03,0x00,0x00},

        {0x80,0x40,0x20,0xF8,0x47,0x30,0x92,0x94,//偿
        0x90,0x9F,0x90,0xD4,0x92,0x50,0x30,0x00},
        {0x00,0x00,0x00,0xFF,0x04,0x04,0x44,0x64,
        0x54,0x4C,0x44,0x54,0x64,0xC6,0x04,0x00},

        {0x10,0x10,0x10,0xFF,0x90,0x50,0x00,0xFE,//报
        0x82,0x82,0x92,0xA2,0x9F,0x02,0x00,0x00},
        {0x02,0x42,0x81,0x7F,0x00,0x00,0x00,0xFF,
        0x22,0x14,0x08,0x16,0x21,0x60,0x20,0x00},

        {0x80,0x92,0x8A,0xBF,0xAA,0xBB,0xCA,0xFA,//警
        0x84,0xA7,0xAA,0x92,0xAE,0xE2,0xA0,0x00},
        {0x00,0x00,0x00,0xEA,0xAA,0xAA,0xAA,0xAA,
        0xAA,0xAA,0xAA,0xEA,0x00,0x00,0x00,0x00}
		



};
void Delay(u32 count)
{
  u32 i=0;
  for(;i<count;i++);
}
/**********************************************
//IIC Start
**********************************************/
void OLED_IIC_Start()
{

	OLED_SCLK_Set() ;
	OLED_SDIN_Set();
	OLED_SDIN_Clr();
	OLED_SCLK_Clr();
}
/**********************************************
//IIC Stop
**********************************************/
void OLED_IIC_Stop()
{
    OLED_SCLK_Set() ;
	OLED_SDIN_Clr();
	OLED_SDIN_Set();
	
}

void OLED_IIC_Wait_Ack()
{
	OLED_SCLK_Set() ;
	OLED_SCLK_Clr();
}
/**********************************************
// IIC Write byte
**********************************************/

void OLED_Write_IIC_Byte(unsigned char IIC_Byte)
{
	unsigned char i;
	unsigned char m,da;
	da=IIC_Byte;
	OLED_SCLK_Clr();
	for(i=0;i<8;i++)		
	{
		m=da;
		m=m&0x80;
		if(m==0x80)
		{OLED_SDIN_Set();}
		else OLED_SDIN_Clr();
		da=da<<1;
		OLED_SCLK_Set();
		OLED_SCLK_Clr();
	}

}
/**********************************************
// IIC Write Command
**********************************************/
void OLED_Write_IIC_Command(unsigned char IIC_Command)
{
		OLED_IIC_Start();
		OLED_Write_IIC_Byte(0x78);            //Slave address,SA0=0
		OLED_IIC_Wait_Ack();	
		OLED_Write_IIC_Byte(0x00);			//write command
		OLED_IIC_Wait_Ack();	
		OLED_Write_IIC_Byte(IIC_Command); 
		OLED_IIC_Wait_Ack();	
		OLED_IIC_Stop();
}
/**********************************************
// IIC Write Data
**********************************************/
void OLED_Write_IIC_Data(unsigned char IIC_Data)
{
		OLED_IIC_Start();
		OLED_Write_IIC_Byte(0x78);			//D/C#=0; R/W#=0
		OLED_IIC_Wait_Ack();	
		OLED_Write_IIC_Byte(0x40);			//write data
		OLED_IIC_Wait_Ack();	
		OLED_Write_IIC_Byte(IIC_Data);
		OLED_IIC_Wait_Ack();	
		OLED_IIC_Stop();
}
/*
********************************************************************************************************************
*                  void OLED_WR_Byte(u8 dat,u8 cmd)
*
*Description    :向SSD1306写入一个字节。
*Arguments   : dat  要写入的数据/命令    
                           cmd  数据/命令标志 0,表示命令;1,表示数据;
*Returns     : none
*Notes       : none
********************************************************************************************************************
*/
void OLED_WR_Byte(unsigned dat,unsigned cmd)
{
	if(cmd)
	{
   OLED_Write_IIC_Data(dat);
	}
	else
	{
   OLED_Write_IIC_Command(dat);
	}
}


/********************************************
// fill_Picture
********************************************/
void fill_picture(unsigned char fill_Data)
{
	unsigned char m,n;
	for(m=0;m<8;m++)
	{
		OLED_WR_Byte(0xb0+m,0);		//page0-page1
		OLED_WR_Byte(0x00,0);		//low column start address
		OLED_WR_Byte(0x10,0);		//high column start address
		for(n=0;n<128;n++)
			{
				OLED_WR_Byte(fill_Data,1);
			}
	}
}


/***********************Delay****************************************/
void Delay_50ms(unsigned int Del_50ms)
{
	unsigned int m;
	for(;Del_50ms>0;Del_50ms--)
		for(m=6245;m>0;m--);
}

void Delay_1ms(unsigned int Del_1ms)
{
	unsigned char j;
	while(Del_1ms--)
	{	
		for(j=0;j<123;j++);
	}
}

//坐标设置
void OLED_Set_Pos(unsigned char x, unsigned char y) 
{ 	OLED_WR_Byte(0xb0+y,OLED_CMD);
	OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);
	OLED_WR_Byte((x&0x0f),OLED_CMD); 
}   	  
//开启OLED显示    
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
//关闭OLED显示     
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}		   			 
//清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!	  
void OLED_Clear(void)  
{  
	u8 i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
		OLED_WR_Byte (0x00,OLED_CMD);      //设置显示位置—列低地址
		OLED_WR_Byte (0x10,OLED_CMD);      //设置显示位置—列高地址   
		for(n=0;n<128;n++)OLED_WR_Byte(0,OLED_DATA); 
	} //更新显示
}
void OLED_On(void)  
{  
	u8 i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
		OLED_WR_Byte (0x00,OLED_CMD);      //设置显示位置—列低地址
		OLED_WR_Byte (0x10,OLED_CMD);      //设置显示位置—列高地址   
		for(n=0;n<128;n++)OLED_WR_Byte(1,OLED_DATA); 
	} //更新显示
}
//在指定位置显示一个字符,包括部分字符
//x:0~127
//y:0~63
//mode:0,反白显示;1,正常显示				 
//size:选择字体 12/16/24 
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size)
{      	
	unsigned char c=0,i=0;	
		c=chr-' ';//得到偏移后的值			
		if(x>Max_Column-1){x=0;y=y+2;}
		if(Char_Size ==16)
			{
			OLED_Set_Pos(x,y);	
			for(i=0;i<8;i++)
			OLED_WR_Byte(F8X16[c*16+i],OLED_DATA);
			OLED_Set_Pos(x,y+1);
			for(i=0;i<8;i++)
			OLED_WR_Byte(F8X16[c*16+i+8],OLED_DATA);
			}
			else {	
				OLED_Set_Pos(x,y);
				for(i=0;i<6;i++)
				OLED_WR_Byte(F6x8[c][i],OLED_DATA);
				
			}
}
//m^n函数
u32 oled_pow(uint8_t m,uint8_t n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}				  
//显示2个数字
//x,y :起点坐标	 
//len :数字的位数
//size:字体大小
//mode:模式	0,填充模式;1,叠加模式
//num:数值(0~4294967295);	 		  
void OLED_ShowNumber(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size2)
{         	
	uint8_t t,temp;
	uint8_t enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size2/2)*t,y,' ',size2);
				continue;
			}else enshow=1; 
		 	 
		}
	 	OLED_ShowChar(x+(size2/2)*t,y,temp+'0',size2); 
	}
} 
//显示一个字符号串
void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t Char_Size)
{
	while (*chr!='\0')
	{		OLED_ShowChar(x,y,*chr,Char_Size);
			x+=8;
		if(x>120){x=0;y+=2;}
			chr++;
	}
}


//==============================================================
//函数名：LED_ShowCHinese16x16(u8 x,u8 y,u8 num,u8 (*buf)[16]) num为第几个字，buf为中文数组（字体为16*16）
//功能描述：写入一组中文
//参数：显示的位置（x,y），y为页范围0～3，要显示的中文
//返回：无
//============================================================== 
void OLED_ShowCHinese16x16(uint8_t x,uint8_t y,uint8_t num,uint8_t (*buf)[16])
{      			    
	uint8_t i;
	OLED_Set_Pos(x,y);	
	for(i=0;i<16;i++)
	{
		OLED_WR_Byte(buf[2*num][i],OLED_DATA);
	}	
	OLED_Set_Pos(x,y+1);	

	for(i=0;i<16;i++)
	{	
		OLED_WR_Byte(buf[2*num+1][i],OLED_DATA);
	}			
		
}

/***********功能描述：显示显示BMP图片128×64起始点坐标(x,y),x的范围0～127，y为页的范围0～7*****************/
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[])
{ 	
 unsigned int j=0;
 unsigned char x,y;
  
  if(y1%8==0) y=y1/8;      
  else y=y1/8+1;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
    for(x=x0;x<x1;x++)
	    {      
	    	OLED_WR_Byte(BMP[j++],OLED_DATA);	    	
	    }
	}
} 
void OLED_Float(unsigned char Y,unsigned char X,double real,unsigned char N) 
{
   unsigned char   i_Count=1;
   unsigned char   n[12]={0};
   long   j=1;  
   int    real_int=0;
   double decimal=0;
   unsigned int   real_decimal=0;
   if(real<0)
	 {
		 real_int=(int)(-real);
	 }
	 else
	 {
		 real_int=(int)real;
   }
	 decimal=real-real_int;
   real_decimal=decimal*1e4;
   while(real_int/10/j!=0)
   {
      j=j*10;i_Count++;  
   } 
   n[0]=(real_int/10000)%10; 
   n[1]=(real_int/1000)%10;
   n[2]=(real_int/100)%10;
   n[3]=(real_int/10)%10;
   n[4]=(real_int/1)%10; 
   n[5]='.';
   n[6]=(real_decimal/1000)%10;
   n[7]=(real_decimal/100)%10;
   n[8]=(real_decimal/10)%10;
   n[9]=real_decimal%10;
   n[6+N]='\0'; 
   for(j=0;j<10;j++) n[j]=n[j]+16+32;
	 if(real<0) 
	 {		 
		 i_Count+=1;
		 n[5-i_Count]='-';
	 }
   n[5]='.';
   n[6+N]='\0';   
   OLED_ShowString(X,Y,&n[5-i_Count],16); 
}

 void OLED_Float2(unsigned char Y,unsigned char X,double real,unsigned char N1,unsigned char N2) 
{
   unsigned char   i_Count=1;
   unsigned char   n[12]={0};
   long   j=1;  
   unsigned int   real_int=0;
   double decimal=0;
   unsigned int   real_decimal=0;
   X=X*8;
   real_int=(int)real;
   //Dis_Num(2,0,real_int,5);
   decimal=real-real_int;
   real_decimal=decimal*1e4;
   //Dis_Num(2,6,real_decimal,4);
   while(real_int/10/j!=0)
   {
      j=j*10;i_Count++;  
   } 
   n[0]=(real_int/10000)%10; 
   n[1]=(real_int/1000)%10;
   n[2]=(real_int/100)%10;
   n[3]=(real_int/10)%10;
 
   n[5]='.';
   n[6]=(real_decimal/1000)%10;
   n[7]=(real_decimal/100)%10;
   n[8]=(real_decimal/10)%10;
   n[9]=real_decimal%10;
   n[6+N2]='\0'; 
   for(j=0;j<10;j++) n[j]=n[j]+16+32;
   n[5]='.';
   n[6+N2]='\0';   
   OLED_ShowString(X,Y,&n[5-N1],12); 
}

void OLED_Num2(unsigned char x,unsigned char y, int number)
{
  unsigned char shi,ge;
	int num =number;
	if(num<0)
	{ 
		num=-num;
		shi=num%100/10;
    ge=num%10;
	  OLED_fuhao_write(x,y,13); 
    OLED_Num_write(x+1,y,shi);
    OLED_Num_write(x+2,y,ge); 
  } 
  else
	{

		shi=num%100/10;
    ge=num%10;
		OLED_fuhao_write(x,y,11);
    OLED_Num_write(x+1,y,shi);
    OLED_Num_write(x+2,y,ge); 
  }
        
}

void OLED_Num3(unsigned char x,unsigned char y,int number)
{
  unsigned char ge,shi,bai;
	int num =number;
	if(num<0)
	{
		    num=-num;
		    OLED_fuhao_write(x,y,13); //显示-号
        ge = num %10;
        shi = num/10%10;
        bai = num/100;
        OLED_Num_write(x+3,y,ge);
        OLED_Num_write(x+2,y,shi);
        OLED_Num_write(x+1,y,bai);
	}
	else
	{
       OLED_fuhao_write(x,y,11);
        ge = num %10;
        shi = num/10 %10;
        bai = num/100;
        OLED_Num_write(x+3,y,ge);
        OLED_Num_write(x+2,y,shi);
        OLED_Num_write(x+1,y,bai);
  }
}

void OLED_Num4(unsigned char x,unsigned char y, int number)
{
	unsigned char qian,bai,shi,ge;
	int num =number;
	if(num<0)
	{
		num=-num;
	}
	qian=num/1000;
	bai=num%1000/100;
	shi=num%100/10;
	ge=num%10;

	OLED_Num_write(x,y,qian);
	OLED_Num_write(x+1,y,bai);
	OLED_Num_write(x+2,y,shi);
	OLED_Num_write(x+3,y,ge);
}

void OLED_Num_write(unsigned char x,unsigned char y,unsigned char asc) 
{
	int i=0;
	OLED_Set_Pos(x*6,y);
	for(i=0;i<6;i++)
	{
		 OLED_WR_Byte(F6x8[asc+16][i],OLED_DATA);    
	}
}	
void OLED_fuhao_write(unsigned char x,unsigned char y,unsigned char asc) 
{

	  int i=0;
    OLED_Set_Pos(x*6,y);
    for(i=0;i<6;i++)
    {
       OLED_WR_Byte(F6x8[asc][i],OLED_DATA);         
    }
 
}			

void OLED_Num5(unsigned char x,unsigned char y,unsigned int number)
{
        unsigned char wan,qian,bai,shi,ge;
        wan=number/10000;
	    	qian = number%10000/1000;
        bai=number%1000/100;
        shi=number%100/10;
        ge=number%10;
        OLED_Num_write(x,y,wan);
        OLED_Num_write(x+1,y,qian);
        OLED_Num_write(x+2,y,bai);
        OLED_Num_write(x+3,y,shi);
		    OLED_Num_write(x+4,y,ge);
}

//初始化SSD1306					    
void OLED_Init(void)
{
 	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);	 //使能B端口时钟
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度50MHz
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	  //初始化GPIOB8,9
 	GPIO_SetBits(GPIOB,GPIO_Pin_6|GPIO_Pin_7);	
	Delay(20000); 
	OLED_WR_Byte(0xAE,OLED_CMD);//--display off
	OLED_WR_Byte(0x00,OLED_CMD);//---set low column address
	OLED_WR_Byte(0x10,OLED_CMD);//---set high column address
	OLED_WR_Byte(0x40,OLED_CMD);//--set start line address  
	OLED_WR_Byte(0xB0,OLED_CMD);//--set page address
	OLED_WR_Byte(0x81,OLED_CMD); // contract control
	OLED_WR_Byte(0xFF,OLED_CMD);//--128   
	OLED_WR_Byte(0xA1,OLED_CMD);//set segment remap 
	OLED_WR_Byte(0xA6,OLED_CMD);//--normal / reverse
	OLED_WR_Byte(0xA8,OLED_CMD);//--set multiplex ratio(1 to 64)
	OLED_WR_Byte(0x3F,OLED_CMD);//--1/32 duty
	OLED_WR_Byte(0xC8,OLED_CMD);//Com scan direction
	OLED_WR_Byte(0xD3,OLED_CMD);//-set display offset
	OLED_WR_Byte(0x00,OLED_CMD);//	
	OLED_WR_Byte(0xD5,OLED_CMD);//set osc division
	OLED_WR_Byte(0x80,OLED_CMD);//	
	OLED_WR_Byte(0xD8,OLED_CMD);//set area color mode off
	OLED_WR_Byte(0x05,OLED_CMD);//	
	OLED_WR_Byte(0xD9,OLED_CMD);//Set Pre-Charge Period
	OLED_WR_Byte(0xF1,OLED_CMD);//	
	OLED_WR_Byte(0xDA,OLED_CMD);//set com pin configuartion
	OLED_WR_Byte(0x12,OLED_CMD);//	
	OLED_WR_Byte(0xDB,OLED_CMD);//set Vcomh
	OLED_WR_Byte(0x30,OLED_CMD);//	
	OLED_WR_Byte(0x8D,OLED_CMD);//set charge pump enable
	OLED_WR_Byte(0x14,OLED_CMD);//	
	OLED_WR_Byte(0xAF,OLED_CMD);//--turn on oled panel
}  

void display(void)  
{	


	OLED_ShowCHinese16x16(90,4,0,TempCompany);//显示摄氏度的符号
//		OLED_ShowCHinese16x16(0,0,0,LOGO1);		//非
//		OLED_ShowCHinese16x16(16,0,1,LOGO1);	//接
//		OLED_ShowCHinese16x16(32,0,2,LOGO1);	//触
//		OLED_ShowCHinese16x16(48,0,3,LOGO1);	//式
//		OLED_ShowCHinese16x16(64,0,4,LOGO1);	//红
//		OLED_ShowCHinese16x16(80,0,5,LOGO1);	//外
//		OLED_ShowCHinese16x16(96,0,6,LOGO1);	//测
//		OLED_ShowCHinese16x16(112,0,7,LOGO1);	//温

//		OLED_ShowCHinese16x16(0,4,9,LOGO1); 
//		OLED_ShowCHinese16x16(16,4,10,LOGO1);

//    OLED_ShowCHinese16x16(0,4,9,LOGO1); //显示补偿
//		OLED_ShowCHinese16x16(16,4,10,LOGO1);

}


void safe(void)
{
	unsigned char LOGO2[][16]=
	{
	  {0x00,0x02,0x02,0xC2,0x02,0x02,0x02,0xFE,//安
      0x82,0x82,0x82,0xC2,0x83,0x02,0x00,0x00},
      {0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x7F,
      0x40,0x40,0x40,0x40,0x40,0x60,0x40,0x00},

      {0x20,0x18,0x08,0x0A,0xEC,0xA8,0xA8,0xAF,//全
      0xA8,0xA8,0xEC,0x0A,0x08,0x28,0x18,0x00},
      {0x00,0x00,0x00,0x3E,0x02,0x02,0x02,0xFF,
      0x02,0x22,0x42,0x3F,0x02,0x00,0x00,0x00}

	};
		OLED_ShowCHinese16x16(80,6,0,LOGO2); 
		OLED_ShowCHinese16x16(96,6,1,LOGO2);
}


void Warning(void)
{
	unsigned char LOGO2[][16]=
	{

      {0x40,0x42,0x44,0xC8,0x00,0x08,0x08,0x48,//过
      0x88,0x08,0x08,0xFF,0x08,0x08,0x00,0x00},
      {0x00,0x40,0x20,0x1F,0x20,0x40,0x40,0x40,
      0x41,0x48,0x50,0x4F,0x40,0x60,0x20,0x00},

      {0x04,0x04,0x04,0xF4,0x94,0x94,0x95,0x96,//高
      0x94,0x94,0x94,0xF4,0x04,0x06,0x04,0x00},
      {0x00,0xFE,0x02,0x02,0x7A,0x4A,0x4A,0x4A,
      0x4A,0x4A,0x7A,0x02,0x82,0xFF,0x02,0x00}
	  
	};
		OLED_ShowCHinese16x16(80,6,0,LOGO2); 
		OLED_ShowCHinese16x16(96,6,1,LOGO2);
}

















