#include <stdlib.h>

#include <vector>
#include <iostream>

#define MAX_NODE 10

using namespace std;



typedef struct Node
{
	int weight;
	struct Node* parent;
	struct Node* left;
	struct Node* right;
	int value;
 
}Node,*NodeLink;

int Partition(vector<NodeLink>& array,int low,int high)
{
	NodeLink keyNode=array[low];
	int pivotkey=array[low]->weight;

	while(low<high)
	{
		while(high>low&&array[high]->weight>=pivotkey)
		{
			high--;
		}
		array[low]=array[high];

		while(high>low&&array[low]->weight<=pivotkey)
		{
			low++;
		}
		array[high]=array[low];
	}
	array[low]=keyNode;
	return low;
}

void QuickSort(vector<NodeLink>& array,int low,int high)
{
	if(low<high)
	{
		int pivoloc=Partition(array,low,high);
		QuickSort(array,low,pivoloc-1);
		QuickSort(array,pivoloc+1,high);
	}
}

void DFS(NodeLink v,vector<int> route)
{

	vector<int> route1(route);
	
	if(v->left!=NULL)
	{
		route.push_back(1);
		DFS(v->left,route);
	}

	if(v->right!=NULL)
	{
		// route1.push_back(0);
		route1.push_back(0);
		DFS(v->right,route1);
	}

	if(v->right==NULL&&v->left==NULL)
	{
		cout<<v->value<<": ";
		for(int i=0;i<route.size();i++)
		{
			cout<<route[i]<<" " ;
		}
		cout<<endl;
	}
	
}



int main()
{
	int val[]={0,1,2,3,4,5,6,7,8,9,10,11};
	vector<NodeLink> line;
	for(int i=0;i<sizeof(val)/sizeof(int);i++)
	{
		NodeLink tmp=(NodeLink)malloc(sizeof(Node));
		tmp->weight=val[i];
		tmp->parent=NULL;
		tmp->left=NULL;
		tmp->right=NULL;
		tmp->value=i;
		line.push_back(tmp);
	}

	//first sort
	QuickSort(line,0,sizeof(val)/sizeof(int)-1);

	while(line.size()!=1)
	{
		printf("%lu\n",line.size());
		NodeLink tmp=(NodeLink)malloc(sizeof(Node));
		tmp->left=line[0];
		tmp->right=line[1];
		tmp->weight=line[0]->weight+line[1]->weight;
		line[0]->parent=tmp;
		line[1]->parent=tmp;
		// line.insert(line.begin()+1,tmp);
		line[1]=tmp;
		line.erase(line.begin());


		for(int i=1;i<line.size();i++)
		{
			if(line[0]->weight<line[i]->weight)
			{
				line.insert(line.begin()+i,line[0]);
				line.erase(line.begin());
				break;
			}
			
		}

	}

	vector<int>tmp;
	tmp.push_back(0);
	DFS(line[0],tmp);



	return 0;
}