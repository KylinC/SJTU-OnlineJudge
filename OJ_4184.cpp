#include<iostream>
#include<cmath>
using namespace std;
 
struct node
{
	int num,weight;
	node* next;
	node(int n=0,node* to=NULL,int w=0) :num(n),next(to),weight(w){}
};
node* head;
 
int res=0,k;
bool* state;
 
int count(int num)
{
	if(state[num]==true)return 0;
	state[num]=true;
	int some=0;
	node* a=&head[num];
	while(a->next)
	{
		a=a->next;
		some+=count(a->num);
	}
	if((1+some)%k==0)res+=1;
	return 1+some;
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	int T,N;
	int tmp1,tmp2,val=1;
	node* tmp;
	cin>>T;
	while(T--)
	{
		res=0;
		cin>>N>>k;
		//k=sqrt(N);
	    head=new node[N+5];
	    state=new bool[N+5];
	    for(int i=1;i<=N;i++)state[i]=false;
	    for(int i=1;i<N;i++)
	    {
		    cin>>tmp1>>tmp2;
		    tmp=new node(tmp2,head[tmp1].next,val);
		    head[tmp1].next=tmp;
		    tmp=new node(tmp1,head[tmp2].next,val);
		    head[tmp2].next=tmp;
	    }
	    count(1);
	    if(res==N/k)cout<<"YES\n";
	    else cout<<"NO\n";
	    
	    delete head;
	    delete state;
    }
}
