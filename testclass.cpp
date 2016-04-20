
#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;
typedef struct ProbNode
{
	int val;//probality
	// ProbNode *next;
	std::map<int,ProbNode*>* child;
	// unsigned int numChild;
	int depth;
	int best;

}ProbNode,*ProbNodeLink;

class Probablity
{
public:
	Probablity(unsigned int _numDemand);
	~Probablity();
	int refresh(std::vector<int> &demandPath);
	bool chooseOrNot(std::vector<int> &demandPath);
	int getTheBestIdx(std::vector<int> &demandPath);
	int establish(std::vector<int> &demandPath);
private:
	// unsigned int variateRate;//full is 100
	ProbNodeLink head;
	unsigned int numDemand;

	/* data */
};



//*****************************************class define********************************//
Probablity::Probablity(unsigned int _numDemand)
{
	head=(ProbNodeLink)malloc(sizeof(ProbNode));
	head->depth=0;
	// head->numChild=0;
	// head->next=NULL:
	head->child=new std::map<int,ProbNode*>();
	head->val=0;

	numDemand=_numDemand;
	// variateRate=20;
}

int Probablity::refresh(std::vector<int> &demandPath)
{
	ProbNodeLink p;
	p=head;
	for(unsigned int i=0;i<demandPath.size();i++)
	{
		if(p->child->find(demandPath[i])==p->child->end())
		{
			ProbNodeLink tmp=(ProbNodeLink)malloc(sizeof(ProbNode));
			tmp->child=new std::map<int,ProbNode*>();
			tmp->depth=i+1;
			tmp->val=numDemand*4;
			p->child->insert(std::pair<int,ProbNodeLink>(demandPath[i],tmp));
		}

		std::map<int,ProbNode*>& pTmp=*(p->child);
		p=pTmp[demandPath[i]];

		p->val-=p->depth;
		cout<<"index: "<<demandPath[i]<<"   ";
		cout<<"val: "<<p->val<<"   ";
		cout<<"depth: "<<p->depth<<endl;
		if(p->val<0)
		{
			p->val=0;
		}

	}
	return 0;
}

bool Probablity::chooseOrNot(std::vector<int> &demandPath)
{
	ProbNodeLink p;
	p=head;

	for(unsigned int i=0;i<demandPath.size()-1;i++)
	{
		if(p->child->find(demandPath[i])==p->child->end())
		{
			ProbNodeLink tmp=(ProbNodeLink)malloc(sizeof(ProbNode));
			tmp->child=new std::map<int,ProbNodeLink>();
			tmp->depth=i+1;
			tmp->val=numDemand*4;
			p->child->insert(std::pair<int,ProbNodeLink>(demandPath[i],tmp));
		}

		std::map<int,ProbNode*>& pTmp=*(p->child);
		p=pTmp[demandPath[i]];
	}

	if(p->child->find(demandPath.back())==p->child->end())
	{
		ProbNodeLink tmp=(ProbNodeLink)malloc(sizeof(ProbNode));
		tmp->child=new std::map<int,ProbNode*>();
		tmp->depth=demandPath.size();
		tmp->val=numDemand*4;
		p->child->insert(std::pair<int,ProbNodeLink>(demandPath.back(),tmp));
	}

	//find the best node:max prob val
	int max=-1;
	int maxIdx=p->child->begin()->first;
	for(std::map<int,ProbNodeLink>::iterator i=p->child->begin();i!=p->child->end();i++)
	{
		if(i->second->val>max)
		{
			max=i->second->val;
			maxIdx=i->first;
		}
	}

	cout<<"best Idx:"<<maxIdx<<"     max pro: "<<max<<endl;

	if(demandPath.back()==maxIdx)
	{
		if(clock()%100>20)
		{
			return true;
		}
	}

	return false;
}



int Probablity::getTheBestIdx(std::vector<int> &demandPath)
{
	ProbNodeLink p;
	p=head;

	for(unsigned int i=0;i<demandPath.size();i++)
	{
		if(p->child->find(demandPath[i])==p->child->end())
		{
			ProbNodeLink tmp=(ProbNodeLink)malloc(sizeof(ProbNode));
			tmp->child=new std::map<int,ProbNodeLink>();
			tmp->depth=i+1;
			tmp->val=numDemand*4;
			p->child->insert(std::pair<int,ProbNodeLink>(demandPath[i],tmp));
		}

		std::map<int,ProbNode*>& pTmp=*(p->child);
		p=pTmp[demandPath[i]];
	}

	

	//find the best node:max prob val
	int max=-1;
	int maxIdx=p->child->begin()->first;
	for(std::map<int,ProbNodeLink>::iterator i=p->child->begin();i!=p->child->end();i++)
	{
		if(i->second->val>max)
		{
			max=i->second->val;
			maxIdx=i->first;
		}
		// printf("%d\n",i->first);
	}

	return maxIdx;
}

int Probablity::establish(std::vector<int> &demandPath)
{

	ProbNodeLink p;
	p=head;

	for(unsigned int i=0;i<demandPath.size();i++)
	{
		if(p->child->find(demandPath[i])==p->child->end())
		{
			ProbNodeLink tmp=(ProbNodeLink)malloc(sizeof(ProbNode));
			tmp->child=new std::map<int,ProbNodeLink>();
			tmp->depth=i+1;
			tmp->val=numDemand*4;
			p->child->insert(std::pair<int,ProbNodeLink>(demandPath[i],tmp));
		}

		std::map<int,ProbNode*>& pTmp=*(p->child);
		p=pTmp[demandPath[i]];
	}

	return 0;
}


//*****************************************class define********************************//



int main()
{

	Probablity* p1=new Probablity(1);
	int e[]={2,3,4};
	std::vector<int> v(e,e+sizeof(e)/sizeof(int));

	int e1[]={2,3,5};
	std::vector<int> v1(e1,e1+sizeof(e1)/sizeof(int));
	

	int e4[]={2,3,9};
	std::vector<int> v2(e4,e4+sizeof(e4)/sizeof(int));


	p1->refresh(v);
	cout<<"*******************v***********************"<<endl;
	p1->refresh(v);
	cout<<"*******************v***********************"<<endl;
	p1->refresh(v1);
	cout<<"*******************v***********************"<<endl;
	p1->establish(v2);


	int e22[]={2,3};
	std::vector<int> v12(e22,e22+sizeof(e22)/sizeof(int));

	cout<<p1->getTheBestIdx(v12)<<endl;
	// p1->refresh(v1);
	// cout<<"*******************v1***********************"<<endl;
	// p1->refresh(v1);
	// cout<<"*******************v1***********************"<<endl;
	// p1->refresh(v2);
	// cout<<"*******************v2***********************"<<endl;

	// cout<<p1->chooseOrNot(v)<<endl;
	return 0;

}