#include<stdio.h>
int main()
{
	int a_number;
	scanf("%d",&a_number);
	if(a_number>0)
	{
		if(a_number%2==0)
			printf("%d��ż����",a_number);
		else
			printf("%d��������",a_number);
	}
	else
		printf("�ⲻ��������");
	return 0;
}
