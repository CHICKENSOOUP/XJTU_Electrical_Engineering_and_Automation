#include<stdio.h>
int main()
{
	int a_number;
	scanf("%d",&a_number);
	if(a_number>0)
		printf("����һ��������\n");
	else if(a_number<0)
		printf("����һ��������\n");
	else if(a_number==0)
		printf("�������0��");
	return 0;
}
