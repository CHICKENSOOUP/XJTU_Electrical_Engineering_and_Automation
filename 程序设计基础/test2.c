/*��ʵ��2�ǻ���ʵ��1�Ļ��������û�����ϵͳ����ʾ������Ӧ����ĸʱ��ϵͳ�����û���ѡ����������Ϣ�� 
����Ҫ�� 
���û�����Iʱ��ϵͳ��� You are trying to input info 
���û�����Oʱ��ϵͳ��� You are trying to output info
���û�����Dʱ��ϵͳ��� You are trying to make things ordered 
���û�����Qʱ��ϵͳ��� You are about to quit*/
#include<stdio.h>
int main()
{
	char chara;
	scanf("%c",&chara);
	switch(chara)
	{
		case 'I':printf("You are trying to input info ");break;
		case 'O':printf("You are trying to output info");break;
		case 'D':printf("You are trying to make things ordered ");break;
		case 'Q':printf("You are about to quit");break;
	}
	return 0;
}
