#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i=0;
	int n=0;//������ 
	int m=0;//�������� 
	int count=0;
	int *gun;
	int p[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
	}
	gun=&p[0];
	i=0;
	while(1)
	{
		if(m==n-1)
			break;//ʣһ���ˣ����� 
		if(*gun!=0)	
		{
			count++;
		}//���ǹ��ָ�ĵ���û�б�pass��������һ 
		if(count==3)//������������� 
		{
			//printf(".,,.,,.,.,\n");
			count=0;//�������� 
			m++;//����������һ 
			*gun=0;//ǹ��ָ�������� 
		}
		i++;//�ܼ��� 
		gun++;//ǹ��ָ����һ���� 
		if(i==n)//���ѭ�������ˣ���ǹ������ָ���һ���� 
		{
			i=0;
			gun=&p[0];
		}
	}
	for(i=0;i<n;i++)
	{
		if(p[i]!=0)
			printf("%d\n",p[i]);
		//else
			//printf("hgksldfh\n");
	}
	return 0;
}
