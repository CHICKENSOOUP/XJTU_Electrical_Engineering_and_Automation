/*������������ʽ��ʽ���£�ϵ�����Ǹ�������
2 1.362 1 8.8 2 -5.02 0 30.3
3 6.6 0 0
��ʾ����ʽ1�� 1.362X2+8.8X-5.02X2+30.3 
����ʽ2��6.6X3 
���һ�����ֱ������벢�ұ�ʾ0���ݣ�
�����Ϊ16��
���벢����Ҫ�����ݴθߵ�˳��,
ͬһ�ݴοɶ�����루����0���ݽ���ÿ������ʽ���һ���������룩��
ÿ������ʽ�ܹ�������30�����룬
����ϵ��Ϊ����ʱ��
���ź�û�пո�
�˷������Ϊ�㡣
0���ݵ�ϵ��Ϊ0ʱҲ������������������С� 
�����ʽ��������ݿ�ʼ���ν���0�ݣ�ϵ��Ϊ0����������������λС����
-200X8+300X2-1X1+30
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int cnt=0,sum=0,mi,maxn1=0,maxn2=0,maxans=0,i,j;
    double di;
    double marknum1[20]={0};
    double marknum2[20]={0};
    double ans[40]={0};
    while(1)
	{ 
        scanf("%d%lf",&mi,&di);   
        marknum1[mi]+=di;
        if(mi>maxn1) maxn1=mi;
        if(!mi) break;
    }
    while(1)
	{    
        scanf("%d%lf",&mi,&di);    
        marknum2[mi]+=di;
        if(mi>maxn2) maxn2=mi;
        if(!mi) break;
    }
    for(i=maxn1;i>=0;i--)    
    {
        if(marknum1[i])        
        {
            for(j=maxn2;j>=0;j--)     
            {
                if(marknum2[j])    
                {
                    ans[j+i]+=marknum1[i]*marknum2[j];
                    if(maxans<i+j) maxans=i+j;     
            	}
            }         
        }      
    }
    for(i=39;i>=0;i--)
         
        if(ans[i])
		{   
            if(i!=maxans&&ans[i]>=0) printf("+");
            printf("%.2lf",ans[i]); 
            if(i>0) printf("X");
            if(i>0) printf("%d",i);        
        }
    return 0; 
}
