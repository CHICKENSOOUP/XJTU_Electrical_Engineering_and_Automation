#include<stdio.h>
int main()
{
    int a_number,sum=0,time=1,number;
    double average,SUM;
    scanf("%d",&a_number);
    while(time<=a_number)
    {
        printf("�������%d������",time);
        scanf("%d",&number);
        if(number>=0)
        {
            sum=sum+number;
            time++;
        }
        else
        {
            while(number<=0)
            {
                printf("�����������%d������",time);
                scanf("%d",&number);
            }
            sum=sum+number;
            time++;
        }
    }
    SUM=sum;
    average=SUM/a_number;
    printf("��%d�����ĺ���%d��ƽ��ֵ��%.2f��",a_number,sum,average);
    return 0;
}

