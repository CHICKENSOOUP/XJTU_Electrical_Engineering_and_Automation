#include<stdio.h>
int main()
{
//1.0��ʼ���������n,m
	int n,m,result=0;
	int j;
	scanf("%d %d",&n,&m);
	//printf("m:%d\n",m);
	int prime=2;
	int num=1;
//2.0��õڣ��������ֵ
	while(num<n)
	{
		prime++;
		for(j=2;j<prime;j++)
		{
			if(prime%j==0)
				break;
			if (j==prime-1)
			{
			num++;
			break;
			}
		}
	}
//3.0��ڣ�������ֵ�ĺ�
	int sum_prime = prime;
	while(n<m)
	{
		prime++;
		for(j=2;j<prime;j++)
		{
			if(prime%j==0)
				break;
			if (j==prime-1)
			{
				n++;
				sum_prime+=prime;
				break;
			}
		}
	}
//4.0������
	printf("%d",sum_prime);
	return 0;
}
