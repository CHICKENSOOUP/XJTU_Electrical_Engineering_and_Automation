/*
��ע�Ȿ����\n�ڷ���������\r\n
����һ�λ������������У�ÿ�в�����300���ַ���ÿ����\n������
����������һ���Ǻ�*�ĵ���һ�У�ֹͣ�����ַ����� 
����һ���ַ����У�����λ����ҵ���������ַ����е����о��Ӳ����
���磬����������Ҫ���ҵ��ַ���������ree
Ȼ������һ�λ���
I am a student.
This is a tree!
Can you play basketball?
dsarrreeaaaa af
This is another tree
*
�������ree�����
This is a tree!
dsarrreeaaaa af
This is another tree
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char a[300],b[10],c[10][300]={{0}};
	int i=0,l=0,j=0,k=0,m=0,n=0;
	while((b[i]=getchar())!='\n'&&b[i]!='\r'&&b[i]!='\0')
		i++;
	b[i]='\0';
	l=i;
	for(i=0; ;i++)
	{
		gets(a);
		if(strlen(a)==1&&a[0]=='*')
			break;
		for(j=0;a[j]!='\0'&&a[j]!='\n'&&a[j]!='\r';j++)
		{
			m=0;
			while(a[j]==b[m]&&m<=l-1)
			{
				m++;
				j++;	
			}
			if(m==l)
			{
				for(n=0;(c[k][n]=a[n])!='\0'&&(c[k][n]=a[n])!='\r'&&(c[k][n]=a[n])!='\n';n++)
					;
				k++;
			}	
		}	
	} 
	for(i=0;i<k;i++)
	{
		for(j=0;c[i][j]!='\r'&&c[i][j]!='\0'&&c[i][j]!='\n';j++)
			printf("%c",c[i][j]);
		printf("\n");
	}
	return 0;
}
