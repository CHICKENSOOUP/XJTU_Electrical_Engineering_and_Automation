#include<stdio.h>
int main()
{
	char a,b,c,d,e;
	a=getchar();
	b=getchar();
	c=getchar();
	d=getchar();
	e=getchar();
	if(a!=0)
	printf("%c%c%c%c%c��5λ����\n",a,b,c,d,e);
	else if(a==0&&b!=0)
	printf("%c%c%c%c%c��4λ����\n",a,b,c,d,e);
	else if(a==0&&b==0&&c!=0)
	printf("%c%c%c%c%c��3λ����\n",a,b,c,d,e);
	else if(a==0&&b==0&&c==0&&d!=0)
	printf("%c%c%c%c%c��2λ����\n",a,b,c,d,e);
	else
	printf("%c%c%c%c%c��1λ����\n",a,b,c,d,e);
	printf("%c*%c*%c*%c*%c\n",a,b,c,d,e);
	printf("%c*%c*%c*%c*%c\n",e,d,c,b,a);
	return 0;
} 
