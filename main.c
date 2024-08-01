#include <REGX51.H>
#include <intrins.h>

//����LED�ƴ�������������˸�����500ms
//��ʱ����
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
				P0 = ~(0x01 << i); // (0000 0001 �ߵ�ƽ1�������ƣ�ȡ��)
				Delay500ms();
				P0 = 0xFF;				//�ر����е�
				Delay500ms();
			}
		}
}