#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
typedef int Status;
typedef int Elemtype;
typedef struct LNode{
	Elemtype data;
	struct LNode *next;
}LNode,*LinkList;

Status InitList(LinkList &L){
	L=(LinkList)malloc(sizeof(LNode));
	if(!L) return ERROR;
	L->next=NULL;
	return OK;
}

Status creatLinkList(LinkList &L,int n){
    int i=0;
    LinkList r=L;
	for(;i<n;i++){
	LinkList p=(LinkList)malloc(sizeof(LNode));
	if(!p) return ERROR;
	scanf("%d",&p->data);
	p->next=NULL;
	r->next=p;
	r=p;	
	}	
}
Status printLinkList(LinkList L){
	while(L->next){
		L=L->next;
		printf("%d ",L->data);
	}
	printf("\n");
	return OK;
}
Status InsertElem(LinkList &L,int i,Elemtype x){
	int j=0;
	LinkList p=L;
	while(p&&j<i-1){
		p=p->next;
		j++;
	}
	if(!p||j>i-1) return ERROR;
	LinkList s=(LinkList)malloc(sizeof(LNode));
	s->data=x;
	s->next=p->next;
	p->next=s;
	printf("插入后的链表："); 
	printLinkList(L);
	return OK;
}

Status DeleteElem(LinkList &L,int i,Elemtype &x)
{
	int j=0;
	LinkList p=L;
	while(p->next&&j<i-1){
		p=p->next;
		j++;
	}
	if(!p->next||j>i-1) return ERROR;
	LinkList s=(LinkList)malloc(sizeof(LNode));
	x=p->next->data;
	s=p->next;
	p->next=p->next->next;
	free(s);
	printf("删除后的链表："); 
	printLinkList(L);
	printf("删除的第%d个元素：%d \n",i,x);
	return OK;
}

Status GetElem(LinkList L,int i,Elemtype &x)
{
	int j=1;
	LinkList p=L->next;
	while(p&&j<i){
		p=p->next;
		j++;
	}
	if(!p||j>i) {
		printf("查找失败！\n");
		return ERROR;
	}
	printf("查找成功！\n");
	x=p->data;
	printf("查找的第%d个元素：%d \n",i,x);
	return OK;
}

Status LineLinkList(LinkList &L,int n){
	int a[n];
	int i=0;
	LinkList p=L->next;
	while(p&&i<n)
	{
	    a[i]=p->data;
		p=p->next;
		i++;
	}
	int j=0,t;
	for(i=0;i<n-1;i++)
	for(j=0;j<n-i-1;j++)
	{
		if(a[j]>a[j+1])
		{
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	}
	
	i=0;
	p=L->next;
	while(p&&i<n)
	{
	    p->data=a[i];
		p=p->next;
		i++;
	}
	return OK;
}
Status add2LinkList(LinkList &L1,LinkList L2)
{
	LinkList p=L1;
	while(p->next)
	{
		p=p->next;
	}
	p->next=L2->next;
	return OK;
}

int main(){
	int n,n1,n2;
	printf("输入n:");
	scanf("%d",&n);
	LinkList L,L1,L2;
	InitList(L);
	creatLinkList(L,n);
	printf("L:");
	printLinkList(L);
	int i;
	scanf("%d",&i);
	Elemtype x;
	scanf("%d",&x);
	InsertElem(L,i,x);
	DeleteElem(L,i,x);
	GetElem(L,i,x);
	
	
	printf("输入n1:");
	scanf("%d",&n1); 
	InitList(L1);
	creatLinkList(L1,n1);
	LineLinkList(L1,n1);
	printf("L1:");
	printLinkList(L1);
	
	
	printf("输入n2:");
	scanf("%d",&n2); 
	InitList(L2);
	creatLinkList(L2,n2);
	LineLinkList(L2,n2);
	printf("L2:");
	printLinkList(L2);	
	
	add2LinkList(L1,L2);
	LineLinkList(L1,n1+n2);
	printf("合并后L1:");
	printLinkList(L1);
	return 0;
}



