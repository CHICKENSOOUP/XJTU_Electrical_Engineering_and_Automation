/*��������һ���ַ��������Ȳ�����100

ɾ���������ַ�����������ַ�����"This is a tree!"��������˫���ţ�

�����ʽ

i

���

Ths s a tree!*/ 
#include<stdio.h>
#include<string.h>
int main()
{
    char x[100];
    int i=0;
    char t;
    for(i=0;i<100;i++)
	{
		scanf("%c",&x[i]);
		if(x[i]=='\n')
			break;
	}
	t=getchar();
    for(i=0;i<100;i++)
    {   
		if(x[i]=='\0')
        	break;
		if(x[i]!=t)
        {
			printf("%c",x[i]);
        }
    }
    return 0;
}
