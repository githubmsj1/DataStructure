#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 20
#define INCREMENT_SIZE 5
#define OVERFLOW -2
#define MAX_NUM 20

typedef int QElemType;
typedef int Status;
typedef char VexType;

typedef struct QNode
{
	QElemType data;
	struct QNode *next;

}QNode,*QueuePtr;

typedef struct 
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


typedef struct EdgeNode
{
	int adjvex;
	struct EdgeNode *next;
}EdgeNode,*EdgeLink;

typedef struct VexNode
{
	VexType data;
	EdgeNode *firstEdge;
}VexNode,AdjList[MAX_NUM];

typedef struct 
{
	AdjList adjList;
	int vexNum,edgeNum;
}ALGraph;



Status InitQueue(LinkQueue *Q)
{
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
	{
		exit(OVERFLOW);
	}
	Q->front->next=NULL;
	return OK;
}

Status DestroyQueue(LinkQueue *Q)
{
	while(Q->front)
	{
		Q->rear=Q->front->next;
		free(Q->front);
		Q->front=Q->rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue *Q)
{
	DestroyQueue(Q);
	InitQueue(Q);
	return OK;
}

Status IsEmpty(LinkQueue Q)
{
	if(Q.front->next==NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int GetLength(LinkQueue Q)
{
	int i=0;
	QueuePtr p=Q.front;
	while(Q.rear!=p)
	{
		i++;
		p=p->next;
	}
	return i;
}

Status GetHead(LinkQueue Q,QElemType *e)
{
	QueuePtr p;
	if(Q.front==Q.rear)
	{
		return ERROR;
	}
	p=Q.front->next;
	*e=p->data;
	return OK;
}

Status EnQueue(LinkQueue *Q,QElemType e)
{
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));

	if(!p)
	{
		exit(OVERFLOW);
	}

	p->data=e;
	p->next=NULL;

	Q->rear->next=p;
	Q->rear=p;
	return OK;
}

Status DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr p;
	if(Q->front==Q->rear)
	{
		return ERROR;
	}

	p=Q->front->next;
	*e=p->data;
	Q->front->next=p->next;
	free(p);
	return OK;

}

void visit(QElemType e)
{
	printf("%d",e);

}

Status TraverseQueue(LinkQueue Q,void (*visit)(QElemType))
{
	QueuePtr p=Q.front->next;
	while(p)
	{
		visit(p->data);
		p=p->next;
	}
	return OK;
}



Status CreateGraph(ALGraph *G)
{
	int i,j,k;
	EdgeLink e;
	printf("input the vexnum and edgenum\n");
	scanf("%d",&G->vexNum);
	scanf("%d",&G->edgeNum);
	getchar();
	printf("input the data of vex \n");

	for(int i=0;i<G->vexNum;i++)
	{
		scanf("%c",&G->adjList[i].data);

		if(G->adjList[i].data=='\n')
		{
			i--;
			continue;
		}
		G->adjList[i].firstEdge=NULL;

	}

	printf("please imput two corresponding vex for edge\n");
	for(k=0;k<G->edgeNum;k++)
	{
		printf("the %d/%d edge\n",k,G->edgeNum);
		scanf("%d",&i);
		scanf("%d",&j);
		e=(EdgeLink)malloc(sizeof(EdgeNode));
		e->adjvex=j;


		e->next=G->adjList[i].firstEdge;
		G->adjList[i].firstEdge=e;

		e=(EdgeLink)malloc(sizeof(EdgeNode));
		e->adjvex=i;
		e->next=G->adjList[j].firstEdge;
		G->adjList[j].firstEdge=e;


	}
	return OK;
}


int visited[MAX_NUM];

void DFS(ALGraph G,int i)
{
	EdgeLink p;
	printf("%c ", G.adjList[i].data);
	visited[i]=TRUE;

	p=G.adjList[i].firstEdge;
	while(p)
	{
		if(!visited[p->adjvex])
		{
			DFS(G,p->adjvex);
		}
		p=p->next;
	}
}

Status DFSTraverse(ALGraph G)
{
	for(int i=0;i<MAX_NUM;i++)
	{
		visited[i]=FALSE;
	}

	for(int i=0;i<G.vexNum;i++)
	{
		if(!visited[i])
		{
			DFS(G,i);
		}
	}
	return OK;
}

Status BFSTraverse(ALGraph G)
{
	EdgeLink p;
	LinkQueue Q;
	InitQueue(&Q);

	for(int i=0;i<MAX_NUM;i++)
	{
		visited[i]=FALSE;
	}

	for(int i=0;i<G.vexNum;i++)
	{
		if(!visited[i])
		{
			visited[i]=TRUE;
			printf("%c ",G.adjList[i].data);
			EnQueue(&Q,i);
			while(IsEmpty(Q))
			{
				DeQueue(&Q,&i);
				p=G.adjList[i].firstEdge;
				while(!p)
				{
					if(!visited[p->adjvex])
					{
						printf("%c ",G.adjList[p->adjvex].data);
						visited[p->adjvex]=TRUE;
						EnQueue(&Q,p->adjvex);
					}
					p=p->next;
				}				
			}
		}
	}
	return OK;
}

int main()
{
	ALGraph G;
	CreateGraph(&G);
	printf("DFS\n");
	DFSTraverse(G);
	printf("\n");
	printf("BFS\n");
	BFSTraverse(G);
	return 0;
}
