/*

������������n��m�������n����������m������֮�����е������ĺͣ�������n�������͵�m��������

��д�����ж�ĳ�����ǲ���������

ע��2�ǵ�һ��������3�ǵڶ���������5�ǵ���������

�����ʽ��2 60

�����ʽ��123456
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i=1,j=2;
	int prime=2,sum;
	int end,begin;
	scanf("%d%d",&begin,&end);//ע������˳�� 
	while(i<begin)
	{
		prime++;
		for(j=2;j<prime;j++)
		{
			if(prime%j==0)
				break;
			if(j==prime-1)
			{
				i++;
			}
		}
	}
	sum=prime;
	printf("%d\n",prime);
	while(begin<end)
	{
		prime++;
		for(j=2;j<prime;j++)
		{
			if(prime%j==0)
				break;
			if(j==prime-1)
			{
				//printf("%d\n",prime);
				sum=sum+prime;
				begin++;
				break;
			}
		}
	}
	printf("%d",sum);
	return 0;
} 

