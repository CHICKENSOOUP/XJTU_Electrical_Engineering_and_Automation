
#include <stdio.h>
#include <stdlib.h>
 
 
//����ṹ������
typedef struct Node{
    float xishu;				//����ϵ��Ϊ������
    int zhishu;					//����ָ��Ϊ����
    struct Node *Next;
}Node;
 
 
typedef struct Node* PNode;	//����ָ������
 
 
//����ʽ����ָ����С����
void insertNewPoint_link(PNode head,PNode qNode)
{
	PNode p=head;				//��headΪ�׵������в���qnode��㣬��p��head����ʼ����
	PNode h=head;
	PNode q;					//�������ٽڵ�
    while (p->Next!=NULL)		//�����������ʽ��ֹһ��
    {
		//�������ָ����ĳһ��p����������ڸ���ǰ��
        if (p->Next->zhishu < qNode->zhishu)
        {
            qNode->Next = p->Next;
            p->Next = qNode;
            break;				//����֮�󼴿��˳�
        }
		else if(p->Next->zhishu == qNode->zhishu)
		{
			float sum = p->Next->xishu + qNode->xishu;//����ϲ����ϵ��
			if(sum!=0)		//���ϲ���ϵ����Ϊ��
				{
					p->Next->xishu = sum;//���¸���p���µ�ϵ��
				}
				else		//����ɾȥ���������еĵ�һ��
				{
					q=p->Next;
					p->Next= p->Next->Next;
					free(q);//���ٽ��
					q=NULL;
				}
				break;
		}
        p = p->Next;			//������ָ��С��p��ǰָ�������p������һ������һ����бȽ�
	}
	if (p->Next == NULL)		//������ʽֻ��һ������������
    {
        p->Next = qNode;
    }
}
 
 
//�������ʽ
void printLinkeLink(PNode head)
{
    PNode temp = head->Next;					//������ʱָ�����ڱ�������
	printf("%fX^%d",temp->xishu,temp->zhishu);	//�������һ�����ǰ�÷��ţ�
	temp=temp->Next;			//tempָ��ָ����һ��
    while (temp != NULL)		//ѭ�����������
    {
        if (temp->xishu > 0)		//��Ϊ��ϵ��
			printf(" +%fX^%d",temp->xishu,temp->zhishu);
        else if (temp->xishu < 0)	//��Ϊ��ϵ��
			printf("%fX^%d",temp->xishu,temp->zhishu);
        temp=temp->Next;
    }
}
 
 
//����ʽ�ļӷ�����
void add_poly(Node *pa,Node *pb)//pa,pb�ֱ�Ϊ����ʽһ�Ͷ���ʽ����ͷָ��
{
	Node *p=pa->Next;		//pΪ����ָ�룬��ʱָ�����ʽһ�ĵ�һ��
    Node *q=pb->Next;		//qΪ����ָ�룬��ʱָ�����ʽ���ĵ�һ��
    Node *pre=pa;			//pre�˿�ָ�����ʽһ��ͷָ�룬������Ϊ�м�����
    Node *u;				//uָ������ʱָ�룬�����ͷŽڵ�
    while (p!=NULL&&q!=NULL)//��ָ��ָ������ݶ���Ϊ��
    {
        if (p->zhishu > q->zhishu)//������ʽһ�е���ϵ�����ڶ�Ӧ����ʽ���е���
        {
            pre = p ; 
			p = p->Next;
        }
        else if(p->zhishu == q->zhishu)//������ϵ�������ϲ�ͬ����
        {
            float x = p->xishu + q->xishu;//xΪ�ϲ����ϵ��
            if (x != 0)				//���ϲ���ϵ����Ϊ��
            {
                p->xishu = x;		//���ϲ����ϵ����������ʽһ�ж�Ӧ����
                pre=p;				//preָ��p���
            }
            else					//���ϲ���ϵ��Ϊ��
            {
                pre->Next = p->Next;//ָ����һ�����
                free(p);			//�ͷ�p���ٽ��
            }
            p = pre->Next;
            u = q;
            q = q->Next;
            free(u);
        }
        else				//������ʽһ�е���ϵ��С�ڶ�Ӧ����ʽ���е���
		{
            u = q->Next;
            q->Next = p;
            pre->Next = q;
            pre = q ;
            q = u;
        }
    }
    if (q)
    {
        pre->Next = q;
    }
    free(pb);
}
 
 
//ʵ��������
void main( )
{
    float xishu;		//�������  ϵ����ָ��
	int zhishu;
    PNode head1 = (PNode)malloc(sizeof(struct Node));
    PNode head2 = (PNode)malloc(sizeof(struct Node));
    PNode tem=NULL;
    head1->Next=NULL;
    head2->Next=NULL;
    //�������ʽһ����
    printf("��������һ��ϵ����ָ�����磺3,2 (��0,0��������)��\n");
    scanf("%f,%d",&xishu,&zhishu);
    while (xishu!=0)	//��ϵ��Ϊ��ʱֹͣ����
    {
        tem=(PNode)malloc(sizeof(struct Node));	//�������в����µ���
        tem->xishu = xishu;
        tem->zhishu = zhishu;
        tem->Next = NULL;
		insertNewPoint_link(head1,tem);			//�����½��
        scanf("%f,%d",&xishu,&zhishu);			//������һ��
    }
    printf("����ʽһΪ��\n");					
    printLinkeLink(head1);						//�������ʽһ
    printf("\n");
    //�������ʽ������
    printf("\n�����������ϵ����ָ�����磺3,2 (��0,0��������)��\n");
    scanf("%f,%d",&xishu,&zhishu);
    while (xishu!=0)	//��ϵ��Ϊ��ʱֹͣ����
    {
        tem=(PNode)malloc(sizeof(struct Node));
        tem->xishu=xishu;
        tem->zhishu=zhishu;
        tem->Next=NULL;
	    insertNewPoint_link(head2,tem);
        scanf("%f,%d",&xishu,&zhishu);
    }
    printf("����ʽ��Ϊ��\n");
    printLinkeLink(head2);
    printf("\n");
    //�������ʽ��ӵĽ��
    add_poly(head1,head2);
    printf("\n����ʽ��Ӻ�Ľ��Ϊ��\n");
    printLinkeLink(head1);
	printf("\n\n");
}
