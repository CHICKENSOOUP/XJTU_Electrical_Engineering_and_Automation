#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d",&a);
	b=a%10;
	c=(a%1000)/100;
	printf("%d�ĸ�λ����%d����λ����%d��",a,b,c);
	return 0;
}
