#include<iostream>
using namespace std;
 
struct node
{
	int num,weight;
	node* next;
	node(int n=0,node* to=NULL,int w=0) :num(n),next(to),weight(w){}
};
 
int *Adist,*Bdist,*Cdist;
node* head;
 
int que[100010];
int front=0,tail=-1;
bool empty(){return (front>tail);}
int enque(int x){que[++tail]=x;}
int deque(){return que[front++];}
 
void possess(int start,int* dist,int n)
{
	node* tmp;
	for (int i = 1; i <= n; i++)
	{
		dist[i] = 100000000;
	}
	dist[start] = 0;
	enque(start);
	while (!empty())
	{
		int source = deque();
		for (tmp = head[source].next; tmp; tmp = tmp->next)
		{
			int to1 = tmp->num, val = tmp->weight;
			if (dist[to1] > dist[source] + val)
			{
				dist[to1] = dist[source] + val;
				enque(to1);
			}
		}
	}
}
 
int main()
{
	int N,A,B,C;
	int tmp1,tmp2,val;
	node* tmp;
	cin>>N>>A>>B>>C;
	Adist=new int[N+5];
	Bdist=new int[N+5];
	Cdist=new int[N+5];
	head=new node[N+5];
	for(int i=1;i<N;i++)
	{
		cin>>tmp1>>tmp2>>val;
		tmp=new node(tmp2,head[tmp1].next,val);
		head[tmp1].next=tmp;
		tmp=new node(tmp1,head[tmp2].next,val);
		head[tmp2].next=tmp;
	}
	possess(A,Adist,N);
	possess(B,Bdist,N);
	possess(C,Cdist,N);
	int mini=100000000,aim;
	for(int i=1;i<=N;i++)
	{
		if(Adist[i]+Bdist[i]+Cdist[i]<mini)
		{
			aim=i;
		    mini=Adist[i]+Bdist[i]+Cdist[i];
		}
	}
	cout<<aim<<'\n'<<mini;
}
