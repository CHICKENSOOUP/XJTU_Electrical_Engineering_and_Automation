/*
�����Сѧѧϰ���������������Ĳ��衣

����������������뱻�������������õ���С��1�����߶���������

�Ƚ�����������10���õ�һλ���Ժ󣬽���������10��Ϊ��һ�ּ���ı��������ɵ����⾫�ȵ��̡�

����������õ�����һ����������

����ʾ����123 567

���ʾ����0.1234567891011213141516161718192020122

�����ʾС�����200λ��

�����ѭ��С���������

0.6T123456T

T֮��Ϊѭ������

�������200λ��δ�ҵ�ѭ���ڣ������ǰ200λ��

��ʾ����������ظ�����ѭ���ڳ��֡�
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAX 200
int xunhuan(int *s,int *e);
void showxh(int start,int end);
void showbxh();
int res1[MAX]={-1};
int res2[MAX]={-1};
int number1,number2;
int start,end;
int main()
{
	int i;
    scanf("%d%d",&number1,&number2);
    for(i=0;i<MAX;i++)
    {
    	res1[i]=number1/number2;
    	res2[i]=number1%number2;
    	number1=10*res2[i];
    	if(!res2[i])	break;
	}
	xunhuan(start,end);
	printf("0.");
	if(xunhuan)
		showxh(start,end);
	else
		showbxh();
    return 0;
} 
int xunhuan(int *s,int *e)
{
	int i,j;
	for(i=0;i<MAX;i++)
	{
		for(j=i+1;j<MAX;j++)
		{
			if(res2[i]==res2[j])
			{
				*s=i;
				*e=j;
				return 1;
			}
		}
	}
	return 0;
}
void showxh(int start,int end)
{
	int i;
	printf("0.");
	for(i=1;i<MAX;i++)
	{
		printf("%d",res1[i]);	
	} 
	printf("T");
	for(i=start+1;i<=end;i++)
	{
		printf("%d",res1[i]);
	}
	printf("T");
} 
void showbxh()
{
	int i;
	for(i=0;i<MAX&&res1[i]!=-1;i++)
	{
		printf("%d",res1[i]);
	}
}
