#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 10
#define INCREMENT_SIZE 5
#define OVERFLOW -2

typedef int Elemtype;
typedef int Status;

typedef struct LNode
{
	Elemtype data;
	struct LNode *next;
}LNode,*LinkList;

void InitList(LinkList* L)
{
	*L=(LinkList)malloc(sizeof(LNode));
	if(!L)
	{
		exit(OVERFLOW);
	}
	(*L)->next=NULL;
}

void DestroyList(LinkList *L)
{
	LinkList temp;
	while (*L)
	{
		temp=(*L)->next;
		free(*L);
		*L=temp;
	}
}

void ClearList(LinkList L)
{
	LinkList p=L->next;
	L->next=NULL;
	DestroyList(&p);
}


Status isEmpty(LinkList L)
{
	if(L->next==NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}



int GetLength(LinkList L)
{
	int i=0;
	LinkList p=L->next;
	while(p)
	{
		i++;
		p=p->next;
	}
	return i;
}

Status GetElem(LinkList L,int i,Elemtype *e)
{
	int j=0;
	LinkList p=L->next;
	while(p&&j<i)
	{
		j++;
		p=p->next;
	}
	if(!p||j!=i)
	{
		return ERROR;
	}
	*e=p->data;
	return OK;
}

Status compare(Elemtype e1,Elemtype e2)
{
	if(e1==e2)
	{
		return 0;
	}
	else if(e1<e2)
	{
		return -1;
	}
	else
	{
		return -1;
	}
}

int FindElem(LinkList L,Elemtype e,Status(*compare)(Elemtype,Elemtype))
{
	int i=0;
	LinkList p=L->next;
	while(p)
	{
		
		if(!compare(p->data,e))
		{
			return i;
		}
		i++;
		p=p->next;
	}
	return 0;

}

Status PreElem(LinkList L,Elemtype cur_e,Elemtype *pre_e)
{
	LinkList q,p=L->next;
	while(p->next)
	{
		q=p->next;
		if(q->data==cur_e)
		{
			*pre_e=p->data;
			return 0;
		}
		p=q;
	}
	return ERROR;
}

Status NextElem(LinkList L,Elemtype cur_e,Elemtype *next_e)
{
	LinkList p=L->next;
	while(p->next)
	{
		if(p->next->data==cur_e)
		{
			*next_e=p->next->next->data;
			return OK;
		}
		p=p->next;
	}
	return ERROR;

}

Status InsertElem(LinkList L,int i,Elemtype e)
{
	int j=0;
	LinkList s,p=L;
	while(p&&j<i)
	{
		j++;
		p=p->next;
	}
	if(!p)
	{
		return ERROR;
	}
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;


}

Status DeleteElem(LinkList L,int i,Elemtype *e)
{
	int j=0;
	LinkList q,p=L->next;
	while(p&&j<i-1)
	{
		j++;
		p=p->next;
	}
	if(!p)
	{
		return ERROR;
	}
	q=p->next;
	p->next=q->next;
	*e=q->data;
	free(q);
	return OK;
}

void visit(Elemtype e)
{
	printf("%d",e);
}

void TraverseList(LinkList L,void (*visit)(Elemtype))
{
	LinkList p=L->next;
	while(p)
	{
		visit(p->data);
		p=p->next;
	}
}

int main()
{
	LinkList L;
	InitList(&L);
	Elemtype e;
	int i;
	if(L)
	{
		printf("InitList successful\n");
	}

	for (i=0;i<10;i++)
	{
		InsertElem(L,i,i);
	}
	if(GetElem(L,0,&e))
	{
		printf("The first element is =%d\n",e);
	}

	printf("Length is %d \n",GetLength(L));
	printf("The 5 at %d\n",FindElem(L,5,*compare));

	PreElem(L,6,&e);
	printf("The 6's previous element is %d\n",e);

	NextElem(L,6,&e);
	printf("The 6's next element is %d\n",e);

	DeleteElem(L,1,&e);
	printf("The element deleted is %d\n",e);

	printf("list\n");
	TraverseList(L,visit);

	DestroyList(&L);
	if(!L)
	{
		printf("destroy successful\n");
	}
}



