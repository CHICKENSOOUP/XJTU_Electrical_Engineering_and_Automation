/*
Ҫ��

1������һ������ĳ��ĳ�գ��������һ��ĵڼ��졣

2�����ܶ�������ĳ��ĵڼ��죬������Ǽ��¼��ա�

3���ֱ�����������ܱ�д�����������ж��Ƿ�����ĺ�����

�����ʽΪ��

2015 5 10

�����ʽΪ

2015 is a leap year.

100

����������

2000 200

�����ʽΪ

2001 is not a leap year.

11-08
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct date
{
	int year,mouth,day;
};
void primeyear(int year);
int datenum(int year1,int mouth,int day);
struct date daynum(int year,int daynumber);
int main()
{
	struct date k;
	int datan=0;
	int year1,year2,day,mouth,daynumber;
	//����һ 
	scanf("%d%d%d",&year1,&mouth,&day);
	primeyear(year1);
	datan=datenum(year1,mouth,day);
	printf("%d\n",datan);
	//���ܶ� 
	scanf("%d%d",&year2,&daynumber);
	primeyear(year2);
	k=daynum(year2,daynumber);
	printf("%d-%d",k.mouth,k.day);
	return 0;
} 
void primeyear(int year)
{
	int flag=0;
	if((year%4==0&&year%100==0)||(year%400==0))
		flag=1;
	if(flag==1)
		printf("%d is a leap year.\n",year);
	else
		printf("%d is not a leap year.\n",year);
}
int datenum(int year1,int mouth,int day)
{
	int mouthnumber[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int sum=0,i;
	struct date a;
	if((year1%4==0&&year1%100==0)||(year1%400==0))
		mouthnumber[2]++;
	for(i=1;i<mouth;i++)
	{
		sum=sum+mouthnumber[i];
	}
	sum=sum+day;
	return sum;
}
struct date daynum(int year,int daynumber)
{
	int mouthnumber[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int sum=0,i;
	struct date a;
	if((year%4==0&&year%100!=0)||(year%400==0))
		mouthnumber[2]++;
	for(i=1;i<13;i++)
	{
		sum=sum+mouthnumber[i];
		if(sum>daynumber)
		{
			a.mouth=i;
			a.day=daynumber-(sum-mouthnumber[i]);
			break;
		}
	}
	return a;
}
