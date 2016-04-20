#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 20
#define INCREMENT_SIZE 5
#define OVERFLOW -2

typedef int TElemType;
typedef int Status;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

Status CreateBiTree(BiTree *T,int layers)
{

	TElemType e;
	printf("%d: ",layers);
	scanf("%d",&e);
	if(e==0)
	{
		*T=NULL;
	}
	else
	{
		*T=(BiTree)malloc(sizeof(BiTNode));
		if(!T)
		{
			exit(OVERFLOW);
		}
		(*T)->data=e;
		CreateBiTree(&(*T)->lchild,layers+1);
		CreateBiTree(&(*T)->rchild,layers+1);
	}
	return OK;
}

void visit(TElemType e)
{
	printf("%d\n",e);
}

Status PreOrderTraverse(BiTree T,void(*visit)(TElemType))
{
	if(!T)
	{
		return ERROR;
	}
	visit(T->data);
	PreOrderTraverse(T->lchild,visit);
	PreOrderTraverse(T->rchild,visit);
	return OK;
}


Status InOrderTraverse(BiTree T,void (*visit)(TElemType))
{
	if(!T)
	{
		return ERROR;
	}
	PreOrderTraverse(T->lchild,visit);
	visit(T->data);
	PreOrderTraverse(T->rchild,visit);

	return OK;

}

Status PostOrderTraverse(BiTree T,void (*visit)(TElemType))
{
	if(!T)
	{
		return ERROR;
	}
	PreOrderTraverse(T->lchild,visit);
	PreOrderTraverse(T->rchild,visit);
	visit(T->data);
	return OK;

}

int main()
{
	BiTree T;
	printf("make tree\n");
	CreateBiTree(&T,0);
	printf("Pre\n");
	PreOrderTraverse(T,*visit);
	printf("In\n");
	InOrderTraverse(T,*visit);
	printf("Post\n");
	PostOrderTraverse(T,*visit);

}