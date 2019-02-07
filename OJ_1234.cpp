#include<iostream>
using namespace std;
 
int set[10010];
int n,m,a,b;
 
struct edge
{
	int pre,nxt;
	int weight;
};
edge edges[100010];
edge tmpEdge;
 
int find(int x)
{
	int father=x;
	while(set[father]>0)father=set[father];
	int tmp1=x,tmp2;
	while(tmp1!=father)
	{
		tmp2=set[tmp1];
		set[tmp1]=father;
		tmp1=tmp2;
	}
	return father;
}
 
void join(int x,int y)
{
	int x_root=find(x),y_root=find(y);
	if(x_root!=y_root)
	{
		if(set[x_root]<set[y_root])
		{
			set[x_root]+=set[y_root];
			set[y_root]=x_root;
		}
		else
		{
			set[y_root]+=set[x_root];
			set[x_root]=y_root;
		}
	}
}
 
void sort(edge* edges,int low,int high)
{
	if(low>=high)return;
	int first=low;
	int last=high;
	edge tmp=edges[first];
	while(first < last)
	{
		while(first<last&&edges[last].weight>=tmp.weight)last--;
		edges[first] = edges[last];
		while(first<last&&edges[first].weight<=tmp.weight)first++;
		edges[last]=edges[first];
	}
	edges[first]=tmp;
	sort(edges,low,first-1);
	sort(edges,first+1,high);
}
 
int main()
{
	int acceptEdge=0,totalWeight=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)set[i]=-1;
	for(int i=1;i<=m;i++) 
	{
	    cin>>edges[i].pre>>edges[i].nxt>>edges[i].weight;
	}
	sort(edges,1,m);
	for(int i=1;acceptEdge<n-1,i<=m;i++)
	{
		tmpEdge=edges[i];
		a=find(tmpEdge.pre);
		b=find(tmpEdge.nxt);
		if(a==b)continue;
		else
		{
			join(a,b);
			acceptEdge++;
			totalWeight+=tmpEdge.weight;
		}
	}
	cout<<totalWeight;
	/*
	for(int i=1;i<=m;i++)
	{
		cout<<edges[i].weight<<" ";
	}
	*/
	return 0;
}
