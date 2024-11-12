#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"

uint8_t KeyNum,MODE;

int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	Key_Init();
 						//C语言无法直接写出二进制数字，故需要用十六进制表示
	 
	while (1)
	{KeyNum = Key_GetNum();
	  if(KeyNum==1)
	  {
 
		  MODE++;
		  if(MODE==4)
		  {MODE=0;}
  }
   switch(MODE)
	   {
case 0:	
	    OLED_ShowCN(3,1,0);//我靠NB
		OLED_ShowCN(3,2,1);
        OLED_ShowString(3, 6, "NB");break; OLED_Clear(); 
case 1:
	    OLED_ShowCN(3,1,2);//电协NB
		OLED_ShowCN(3,2,3);
        OLED_ShowString(3, 6, "NB");break;OLED_Clear();	
case 2:
	    OLED_ShowCN(3,1,4);//老子最NB
		OLED_ShowCN(3,2,5);
        OLED_ShowCN(3,3,6);
        OLED_ShowString(3, 9, "NB");break;OLED_Clear();	
case 3: OLED_Clear();	
	    OLED_ShowCN(3,1,7);//耶
		OLED_ShowCN(3,2,7);//耶
        OLED_ShowCN(3,3,7);//耶
        break;	  OLED_Clear();	 }	    
 
	}
}
