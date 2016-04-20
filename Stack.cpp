#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 20
#define INCREMENT_SIZE 5
#define OVERFLOW -2

typedef int SElemType;
typedef int Status;


typedef struct 
{
	SElemType *base;
	SElemType *top;
	int size;
}SqStack;

Status InitStack(SqStack *S)
{
	S->base=(SElemType*)malloc(INIT_SIZE*sizeof(SElemType));
	if(!S->base)
	{
		exit(OVERFLOW);
	}
	S->top=S->base;
	S->size=INIT_SIZE;
	return OK;

}

Status DestroyStack(SqStack *S)
{
	free(S->base);
	S->base=NULL;
	S->top=NULL;
	S->size=0;
	return OK;
}

Status ClearStack(SqStack *S)
{
	S->top=S->base;
	return OK;
}

Status IsEmpty(SqStack S)
{
	if(S.top==S.base)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int GetLength(SqStack S)
{
	return (S.top-S.base)/sizeof(SElemType);
}


Status GetTop(SqStack S,SElemType *e)
{
	if(S.top>S.base)
	{
		*e=*(S.top-sizeof(SElemType));
		return OK;
	}
	else
	{	
		return ERROR;
	}	
}

Status Push(SqStack *S,SElemType e)
{
	if((S->top-S->base)/sizeof(SElemType)>=S->size)
	{
		S->base=(SElemType*)realloc(S->base,(S->size+INCREMENT_SIZE)*sizeof(SElemType));
		if(!S->base)
		{
			exit(OVERFLOW);
		}
		S->top=S->base+S->size*sizeof(SElemType);
		S->size+=INCREMENT_SIZE;
	}
	*S->top=e;
	S->top+=sizeof(SElemType);
	return OK;
}

Status Pop(SqStack *S,SElemType *e)
{
	if(S->top==S->base)
	{
		return ERROR;
	}
	S->top-=sizeof(SElemType);
	*e=*S->top;
	return OK;
}

void visit(SElemType e)
{
	printf("%d\n",e);
}

Status Traverse(SqStack S,void(*visit)(SElemType))
{
	while(S.top>S.base)
	{
		visit(*S.base);
		{
			S.base+=sizeof(SElemType);
		}
	}
	return OK;
}


int main()
{
	SqStack S;
	if(InitStack(&S))
	{
		SElemType e;
		printf("init successful\n");

		if(IsEmpty(S))
		{
			printf("Stack is empty\n");
		}

		for(int i=0;i<10;i++)
		{
			Push(&S,i);
		}
		GetTop(S,&e);
		printf("The First element is %d\n",e );

		printf("The length is %d\n",GetLength(S));

		Pop(&S,&e);
		printf("Pop element is %d\n",e );

		Traverse(S,*visit);

		if(DestroyStack(&S))
		{
			printf("DestroyStack successful\n");
		}



	}
	return 0;
}