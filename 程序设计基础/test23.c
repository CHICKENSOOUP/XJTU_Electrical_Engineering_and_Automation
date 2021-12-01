#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_LEN 200
int nume; //numerator����
int deno; //denominator��ĸ
int quot[MAX_LEN]={-1}; //quotient��
int rem[MAX_LEN]={-1}; //remainder����
//��ȡ�̺�����
void save_quot_rem() 
{
	int i;
	for(i=0; i<MAX_LEN; i++)
	{
		quot[i] = nume/deno;
		rem[i] = nume%deno;
		nume = 10*rem[i];
		if(!rem[i])
			break;
	} //for
}
//�ж��Ƿ���ѭ��С��,�����򱣴�ѭ������ʼ�ͽ���λ��
int is_circu(int *start, int *end)
{
	int i,j;
	for(i=0; i<MAX_LEN; i++)
	{
		if(rem[i]==-1)
		return 0;
	}
	for(i=0;i<MAX_LEN;i++)
	{
		for(j=i+1;j<MAX_LEN;j++)
		{
			if(rem[i] == rem[j])
			{
				*start = i;
				*end = j;
				return 1;
			} //if
		} //for
	} //for
	return 0;
}
void show_circu(int start, int end) //��ʾѭ��С��
{
	int i;
	printf("%d.", quot[0]); //��������
	for(i=1;i<=start; i++) //С����ѭ���ڲ���
	{
		printf("%d",quot[i]);
	}
	printf("T");
	for(i=start+1; i<=end; i++) //С��ѭ���ڲ���
	{
		printf("%d",quot[i]);
	}
	printf("T");
	}
void show_not_circu() //��ʾ��ѭ��С��
{
	int i;
	if(quot[1]==-1) //��С������
	{
		printf("%d",quot[0]);
		return;
	}
	printf("%d.", quot[0]);
	for(i=1; (i < MAX_LEN) && (-1 != quot[i]); i++) //С������
	{
		printf("%d",quot[i]);
	}
}
int main()
{
	int start, end;
	while(1)
	{
		scanf("%d%d", &nume, &deno);
		if(!nume && !deno)
			return 0;
		memset(quot,-1,sizeof(quot));
		memset(rem,-1,sizeof(rem));
		save_quot_rem();
		is_circu(&start, &end) ? show_circu(start,end):show_not_circu();
	}	
	return 0;
}
