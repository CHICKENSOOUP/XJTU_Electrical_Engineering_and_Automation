/*�ٶ��Ѿ�������ѧ����Ϣ��������Ҫ������ĸ�ѧ������Ϣ��
Ҫ��
��1�� ������洢ѧ����Ϣ������ѧ�š��༶�����ſγ̵ĳɼ������ſγ̵��ܳɼ���
��2�� ����������ĸ�ѧ����Ϣ�󣬰��հ༶��С������Ⱥ��������ѧ����Ϣ��
ͬһ�༶�ڰ����ܳɼ��ӵ͵���������ɼ�����1λС����
��3�� ���е�����ѧ����Ϣ�����������ʼ��ʱ��̬��ֵ�����е�����ѧ������Ϣ�ǣ�
1001��11��92.5��82.5��96��271
1002��12��82.5��87.5��93.5��263.5
1003��13��97��84.5��88.5��270

���ĸ�ѧ����Ϣ����ʾ����
1004
12
95.8
85.6
74.9

���ʾ����
1001��11��92.5��82.5��96.0��271.0
1004��12��95.8��85.6��74.9��256.3
1002��12��82.5��87.5��93.5��263.5
1003��13��97.0��84.5��88.5��270.0*/
#include<stdio.h>
int main()
{
	int i;
	int num[4]={1001,1002,1003},classnum[4]={11,12,13};
	double subject1[4]={92.5,82.5,97},subject2[4]={82.5,85.6,87.5},subject3[4]={96,74.9,93.5};
	double sum[4];
	scanf("%d%d%lf%lf%lf",&num[3],&classnum[3],&subject1[3],&subject2[3],&subject3[3]);
	for(i=0;i<4;i++)
	{
		sum[i]=subject1[i]+subject2[i]+subject3[i];
	}
	for(i=0;i<4;i++)
	{
		if(classnum[i]<classnum[4])
			printf("%d,%d,%.3f,%.3f,%.3f,%.3f\n",num[i],classnum[i],subject1[i],subject2[i],subject3[i],sum[i]);	
		else if(classnum[i]==classnum[4])
			{
				if(sum[i]<=sum[4])
					printf("%d,%d,%.3f,%.3f,%.3f,%.3f\n",num[i],classnum[i],subject1[i],subject2[i],subject3[i],sum[i]);
			}
		else if(classnum[i]==classnum[4])
			printf("%d,%d,%.3f,%.3f,%.3f,%.3f\n",num[i],classnum[i],subject1[i],subject2[i],subject3[i],sum[i]);
	}
	return 0;
}
