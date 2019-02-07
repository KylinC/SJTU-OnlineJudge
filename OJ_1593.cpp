#include<iostream>
using namespace std;
 
struct node
{
    int num;
	int score,val;
	node(int t_num=0,int t_score=0,int t_val=0)
	    :num(t_num),score(t_score),val(t_val)
	{}
	bool operator<(node& other)
	{
		if(score<other.score)return true;
		else if(score==other.score&&num>other.num)return true;
		return false;
	}
	bool operator>(node& other)
	{
		if(score>other.score)return true;
		else if(score==other.score&&num<other.num)return true;
		return false;
	}
};
node* bar;
int partition(int low,int high)
{
	node temp=bar[low];
	int i=low,j=low+1;
	for(;j<=high;j++)
	{
		if(bar[j]>temp)
		{
			node t=bar[j];
			bar[j]=bar[++i];
			bar[i]=t;
		}
	}
	bar[low]=bar[i];
	bar[i]=temp;
	return i;
}
void quickSort(int low,int high)
{
	if(low<high)
	{
		int mid=partition(low,high);
		quickSort(low,mid-1);
		quickSort(mid+1,high);
	}
}
void init(int n)
{
	int pre,nxt;
	for(int i=1;i<=n;i++)
	{
		pre=2*i-1;nxt=2*i;
		if(bar[pre].val>bar[nxt].val)bar[pre].score+=2;
		else if(bar[pre].val<bar[nxt].val)bar[nxt].score+=2;
		else
		{
			bar[pre].score+=1;
			bar[nxt].score+=1;
		}
	}
}
void check(int N)
{
	node tmp;
	bool flag;
	for(int i=2;i<=N;i++)
	{
		flag=false;
		for(int j=1;j<=N+1-i;j++)
		{
			if(bar[j]<bar[j+1])
			{
				tmp=bar[j];
				bar[j]=bar[j+1];
				bar[j+1]=tmp;
				flag=true;
			}
		}
		if(!flag) break;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int N,n,r;
	cin>>n>>r;
	N=2*n;
	bar=new node[2*n+10];
	for(int i=1;i<=N;i++)
	{
        bar[i].num=i;
		cin>>bar[i].score;
	}
	for(int i=1;i<=N;i++)
	{
		cin>>bar[i].val;
	}
	quickSort(1,N);
	for(int i=1;i<=r;i++)
	{
		init(n);
		check(N);
	}
	for(int i=1;i<=N;i++)
	{
		cout<<bar[i].num<<" ";
	}
}
