#include<stdio.h>
#include<math.h>
#include<string.h> 
#define GAS 3.785
#define KILO 1.609
int main()
{
	float gaspayc,gaspaye;
	printf("������ÿ����Ӣ������");
	scanf("%f",&gaspaye);
	gaspayc=gaspaye*(KILO/GAS);
	printf("ÿ����������%.1f",gaspayc);
	return 0;
}
