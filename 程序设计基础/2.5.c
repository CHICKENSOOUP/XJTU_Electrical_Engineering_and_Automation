/*
�밴�ֵ�˳������ǰ������д��ĸABCDEF�ܹ��ɵ�������ϡ�
ÿ�������ÿ����ĸ�����ҽ�����һ�Ρ�
�����ʽΪÿ����ϵ���һ�С�
*/
#include<stdio.h>
#include<string.h>
void dfs(int t);
int queue_number[10];
int tag[9]={0};
int n=6;
int main()
{
	dfs(n);
    return 0;
}
void dfs(int t)
{
	int i;
    if(t==0)//��ѡ�е����ָ���Ϊ0 
    {
        for(i=0;i<n;++i)
		{
            printf("%c",queue_number[i]);
            if(i==n-1)	printf("\n");
        }
    }
    for(i=1;i<=n;++i)
	{
        if(tag[i]==0)
		{
            queue_number[n-t]=i+64;
            tag[i]=1;
            dfs(t-1);//�ݹ�,��ʾ���ǻ�����ѡ�е����ĸ���
            tag[i]=0;//�ݹ����֮��Ľ����ź� 
        }
    }
}

