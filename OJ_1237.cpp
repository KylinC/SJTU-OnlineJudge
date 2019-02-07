#include<iostream>
#include<cstring>
using namespace std;
 
int n,m;
 
struct node
{
	int num;
	node* next;
	node(int n=0,node* to=NULL) :num(n),next(to){}
};
node* head;
int indeg[10010],result[10010];
 
int tail=-1,front=0;
int que[10010];
void enque(int x){que[++tail]=x;}
int deque(){return que[front++];}
bool empty(){return (front>tail);}
 
void topSort()
{
	while(!empty())
	{
		int from=deque();
		node* tmp;
		//cout<<"!"<<from<<"!";
		for(tmp=head[from].next;tmp;tmp=tmp->next)
		{
			int del=tmp->num;
			indeg[del]--;
			if(indeg[del]==0)
			{
				result[del]=result[from]+1;
				enque(del);
			}
		}
	}
}
 
int find_max()
{
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(result[i]>res)res=result[i];
	}
	return res;
}
 
int main()
{
	cin>>n>>m;
	head=new node[n+10];
	memset(indeg,0,sizeof(indeg));
	memset(result,0,sizeof(result));
	int from,to;
	node *tmp;
	for(int i=1;i<=m;i++)
	{
		cin>>to>>from;
		tmp=new node(to,head[from].next);
		head[from].next=tmp;
		indeg[to]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(indeg[i]==0)
		{
			enque(i);
			result[i]=1;
		}
	}
	topSort();
	cout<<find_max();
	//cout<<head[5].next->num;
	
	return 0;
}
