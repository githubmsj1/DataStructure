#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 10
#define INCREMENT_SIZE 5


typedef int Status;
typedef int Elemtype;


typedef struct 		
{
	Elemtype *elem;
	int length;
	int size;
}SqList;

Status InitList(SqList *L)
{
	L->elem=(Elemtype*)malloc(INIT_SIZE*sizeof(Elemtype));
	if(!L->elem)
	{
		return ERROR;
	}
	L->length=0;
	L->size=INIT_SIZE;
	return OK;
}

Status DestroyList(SqList *L)
{
	free(L->elem);
	L->length=0;
	L->size=0;
	return OK;
}

Status ClearList(SqList *L)
{
	L->length=0;
	return OK;
}

Status isEmpty(const SqList L)
{
	if(0==L.length)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}

Status getLength(const SqList L)
{
	return L.length;
}

Status GetElem(const SqList L,int i,Elemtype* e)
{
	if (i<0||i>L.length)
	{
		return ERROR;
	}
	*e=L.elem[i];
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
		return 1;
	}
}

Status FindElem(const SqList L,Elemtype e,Status(*compare)(Elemtype,Elemtype))
{
	for (int i=0;i<L.length;i++)
	{
		if(!(compare)(L.elem[i],e))
		{
			return i;
		}
	}
	return ERROR;
}

Status PreElem(const SqList L,Elemtype cur_e,Elemtype *pre_e)
{
	if(cur_e==L.elem[0])
	{
		return ERROR;
	}
	for(int i=1;i<L.length;i++)
	{
		if(cur_e==L.elem[i])
		{
			*pre_e=L.elem[i-1];
			return OK;
		}
	}
	return ERROR;
}

Status NextElem(const SqList L,Elemtype cur_e,Elemtype *next_e)
{

	for(int i=0;i<L.length-1;i++)
	{
		if(cur_e==L.elem[i])
		{
			*next_e=L.elem[i+1];
			return OK;
		}
	}

	return ERROR;
}

Status InsereElem(SqList *L,int i,Elemtype e)
{
	Elemtype *new1;
	if(i<0||i>L->length)
	{
		return ERROR;
	}
	if(L->length>=L->size)
	{
		new1=(Elemtype*)realloc(L->elem,(L->size+INIT_SIZE)*sizeof(Elemtype));
		if(!new1)
		{
			return ERROR;
		}
		L->elem=new1;
		L->size+=INIT_SIZE;
	}
	Elemtype *p=&L->elem[i];
	Elemtype *q=&L->elem[L->length-1];
	for (;q>=p;q--)
	{
		*(q+1)=*q;
	}
	*p=e;
	++L->length;
	return OK;

}


Status DeleteElem(SqList *L,int i,Elemtype *e)
{
	if(i<0||i>L->length-1)
	{
		return ERROR;
	}
	Elemtype *p=&L->elem[i];
	*e=*p;
	for (; p<&L->elem[L->length-1];p++)
	{
		*(p)=*(p+1);
	}
	--L->length;
	return OK;

}

void visit(Elemtype e)
{
	printf("%d\n",e);
}

Status TraverseList(const SqList L,void (*visit)(Elemtype))
{
	for(int i=0;i<L.length;i++)
	{
		visit(L.elem[i]);
	}
	return OK;
}



int main()
{
	SqList L;
	if(InitList(&L))
	{
		Elemtype e;
		printf("init_success\n");
		int i;
		for(i=0;i<10;i++)
		{
			InsereElem(&L,i,i);
		}
		printf("length is %d",getLength(L));
		if(GetElem(L,1,&e))
		{
			printf("first elem is %d",e);
		}
		else
		{
			printf("elem not exist\n");
		}
		if(isEmpty(L))
		{
			printf("list is empty\n");
		}
		else
		{
			printf("not empty\n");
		}

		printf("The 5 at %d\n",FindElem(L,5,*compare));
		PreElem(L,6,&e);
		printf("pre of 6 is %d\n",e);
		NextElem(L,6,&e);
		printf("next to the 6 is %d\n",e);
		DeleteElem(&L,1,&e);
		printf("The elem deleted is %d\n", e);
		printf("list:\n");
		TraverseList(L,visit);
		if(DestroyList(&L))
		{
			printf("DestroyList success\n");
		}
	}
	return 0;
}