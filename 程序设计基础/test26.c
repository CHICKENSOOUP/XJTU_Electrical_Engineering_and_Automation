/*
������������ʽ��ʽ���£�ϵ�����Ǹ�������

2 1.362 1 8.8 2 -5.02 0 30.3

3 6.6 0 0

��ʾ����ʽ1�� 1.362X2+8.8X-5.02X2+30.3 ����ʽ2��6.6X3
���һ�����ֱ������벢�ұ�ʾ0���ݣ������Ϊ16��
���벢����Ҫ�����ݴθߵ�˳��,
ͬһ�ݴοɶ�����루����0���ݽ���ÿ������ʽ���һ���������룩��
ÿ������ʽ�ܹ�������30�����룬����ϵ��Ϊ����ʱ�����ź�û�пո�
�˷������Ϊ�㡣0���ݵ�ϵ��Ϊ0ʱҲ������������������С� 
�����ʽ��������ݿ�ʼ���ν���0�ݣ�ϵ��Ϊ0����������������λС����

-200X8+300X2-1X1+30
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i,j;
	int mi;
	int max1=0,max2=0;
	double xs;
	double xishu1[200]={0};
	double xishu2[200]={0};
	double res[400]={0};
	while(1)
	{
		scanf("%d%lf",&mi,&xs);
		xishu1[mi]=xishu1[mi]+xs;
		if(mi>max1)	max1=mi;
		if(mi==0)
			break;
	}
	while(1)
	{
		scanf("%d%lf",&mi,&xs);
		xishu2[mi]=xishu2[mi]+xs;
		if(mi>max2)	max2=mi;
		if(mi==0)
			break;
	}
	for(i=0;i<200;i++)
	{
		for(j=0;j<200;j++)
		{
			if(xishu1[i]!=0&&xishu2[j]!=0)
				res[i+j]=xishu1[i]*xishu2[j]; 
		}
	}
	for(i=400;i>=0;i--)
	{
		if(res[i]>0&&i!=max1+max2)
			printf("+");
		if(i!=0&&res[i]!=0)
			printf("%.3fX%d",res[i],i);
		else if(i==0&&res[i]!=0)
			printf("+%.3f",res[i]);
		
	}
	return 0;
}
