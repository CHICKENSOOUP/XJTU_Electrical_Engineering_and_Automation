/*
����һ������С��200���ַ����������������ķ������ַ�����
�������������ַ���ɵ�����ת��Ϊ��ƽ����
Ȼ�����н��ƴ�ӳ��µ��ַ����������
���庯��void inversestr( char *s )���ַ�������
���庯��void int2str( int x )������ת��Ϊ�ַ�����
���庯��void catstring( char s1[], char s2[] )���ַ���ƴ�ӵ��ַ���s1
��������
abc n15tyu!a
���
n cba225a!uy
*/
 
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    void inversestr(char *s,int );
    void catstring(char s1[],char s2[]);
    //int num2char(int ,char *);
    int string2int( int *s,int m);
     
    int i=0,j=0,s=0,t=0,m,count=0;
    int res=0;
    int num[200]={0};
    char zifu[200]={0};
    char chara[200]={0},pingfang[200];
    char result[200]={0};   
    gets(zifu);
    //a!ddd d r5676erty
    //printf("%s\n",zifu);
    for(i=0;i<200;i++)
    {
    	if(zifu[i]=='\0')	
			break;
        if(!(zifu[i]>='0'&&zifu[i]<='9'))
        {
            chara[j]=zifu[i];
			res=string2int(num,s);
			for(t=0;t<s;t++)
			{
				num[t]='\0';
			//	pingfang[t]='\0';
			}
			if(res!=0)
			{
				printf("%d",res);
				//m=num2char(res,pingfang);
				//inversestr(pingfang,m);
				//puts(pingfang);
				//putchar('\n');
				//strcat(result,pingfang);
			}	
			s=0;
            //printf("%c=\t",chara[j]);
            j++;
        } 
        if(zifu[i]>='0'&&zifu[i]<='9')
        {
			inversestr(chara,j);
			//strcat(result,chara);
			if(chara[0]!='\0')
				printf("%s",chara);
			for(count=0;count<j;count++)
			{
				*(chara+count)='\0';
			}
			//result[strlen(result)]=res;
			//result[strlen(result)+1]='\0';
			//printf("%s.,.\n",result);
        	j=0;
            num[s]=zifu[i]-'0';
            s++;    
        }
	}        
	res=string2int(num,s);
	if(res!=0)
			{
				//result[s]=res/100;
				printf("%d",res);
				//m=num2char(res,pingfang);
				//printf("%s,.,\n",pingfang); 
				inversestr(pingfang,m);
				//strcat(result,pingfang);
			}
    /*for(i=0;i<strlen(result);i++)
    {
    	if(!(zifu[i]>='0'&&zifu[i]<='9'))
    		printf("%c",result[i]);
    	else
    		printf("%d",result[i]);
	}*/
	inversestr(chara,j);
	printf("%s",chara);
	//strcat(result,chara);
	//puts(result);
    return 0;
}
void inversestr(char *s,int c)
{
    int temp,i,j,m=(c-1)/2;
    for(i=0;i<=m;i++)
    {
    	j=c-1-i;
    	temp=s[i];
    	s[i]=s[j];
    	s[j]=temp;
	}
}
void catstring(char s1[],char s2[])
{
    int i=0;
    strcat(s1,s2);
}
int string2int(int s[],int m)
{
    int res=0;
    int result2;
    int i;
    for(i=0;i<m;i++)
        res=res*10+s[i];
    result2=res*res;
    return result2;
}
/*
int num2char(int result2,char *pingfang)
{
	int i=0;
	for(i=0;i<200;i++)
	{
		*(pingfang+i)='\0';
	}
	while(result2/10!=0)
	{
		pingfang[i]=result2%10+'0';
		result2/=10;
		i++;
	}
	return i;
}*/
