/*
�����µ����� 
��ע�ⲻ�����ǵ���������ȵ���Ȼ���������

�����ʽ

This is��

�����ʽ

��si sihT*/
#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int i=0,m=0,n=0;
	char x[100],y[100];
	gets(x);
	n=strlen(x);
	i=n;
	while(m<n)
	{
		y[m]=x[i-1];
		printf("%c",y[m]);
		i--;
		m++;
	}
	return 0;
}
