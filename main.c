#include <REGX51.H>
#include <intrins.h>

//需求：LED灯从右向左依次闪烁，间隔500ms
//延时函数
void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()
{
		unsigned char i;
		while(1)
		{
			for(i = 0; i < 8; i++)
			{
				P0 = ~(0x01 << i); // (0000 0001 高电平1不断左移，取反)
				Delay500ms();
				P0 = 0xFF;				//关闭所有灯
				Delay500ms();
			}
		}
}