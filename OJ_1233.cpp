#include<iostream>
#include<cstring>
using namespace std;
 
int n,m,start,M;
int result=0;
struct node
{
	int num;
	node* next;
	node(int n=0,node* to=NULL) :num(n),next(to){}
};
node* head;
 
int ava[10010];
 
void dfs(int num,int count)
{
	if(ava[num]==1)return;
	if(count==M)
	{
		result++;
		return;
	}
	ava[num]=1;
	node* tmp;
	for(tmp=head[num].next;tmp;tmp=tmp->next)
	{
		dfs(tmp->num,count+1);
	}
	ava[num]=0;
}
 
int main()
{
	cin>>n>>m>>start>>M;
	head=new node[n+10];
	memset(ava,0,sizeof(ava));
	int from,to;
	node *tmp;
	for(int i=1;i<=m;i++)
	{
		cin>>from>>to;
		tmp=new node(to,head[from].next);
		head[from].next=tmp;
	}
	dfs(start,0);
	cout<<result;
	return 0;
}
