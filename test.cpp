#include<iostream>
#include<vector>

using namespace std;

typedef struct PathNode
{
	int idx;
	int weight;
	vector<int>* path;
}PathNode,*PathNodeLink;


typedef struct
{
	int nodeID;
	int edgeID;
	int stepth;
}ReflectNode,*ReflectNodeLink;
int main()
{
	// vector<PathNode> v;
	// PathNode *src;
	// src=(PathNodeLink)malloc(sizeof(PathNode));

	// src->idx=1;
	// src->weight=0;
	// // src->path.push_back(1);
	// src->path=new vector<int>();
	// src->path->push_back(1);
	
	// delete(src->path);
	// printf("%lu\n",src->path->size());
	// printf("%x\n",*(src->path);

	// for(int i=0;i<5;i++)
	// {
	// 	PathNode temp;
	// 	temp.idx=i;
	// 	int max[]={1,i,3};
	// 	temp.path=max;
		
	// 	v.push_back(temp);
	// }
	
	// cout<<v[1].idx;


	// vector<ReflectNode> v;
	// for(int i=0;i<5;i++)
	// {
	// 	ReflectNode tmp;
	// 	tmp.stepth=i;
	// 	v.push_back(tmp);
	// }
	// v[0]=v[1];
	// v[1]=v[2];

	// for(int i=0;i<v.size();i++)
	// {
	// 	cout<<v[i].stepth<<endl;
	// }
	// ReflectNodeLink r=new ReflectNode();

	int* u=new int;
	*u=4;
	delete(u);
	cout<<*u<<endl;
	return 0;
}