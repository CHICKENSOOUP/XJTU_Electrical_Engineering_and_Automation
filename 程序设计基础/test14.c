#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int m,i,s;
	for(m=1;m<=1000;m++) //��1��ʼ��1000ѭ������
	{
		s=0;//��ʼ������֮��sΪ0
		for(i=1;i<m;i++) //Ѱ����1��m֮�䣬�ж���m������
			if(m%i==0) //���m������i����iΪm������
				s=s+i;//�������ۼ�
		if(s==m) //�������֮�͵��������
	printf("%d\t",s);//���
	}
	return 0;
}


