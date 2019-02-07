#include<iostream>
using namespace std;
 
int *set;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,tmp1,tmp2,result=0,total=0;
	cin>>n>>m;
	set=new int[n+10];
	for(int i=0;i<=n;i++)set[i]=-1;
	for(int i=0;i<m;i++)
	{
		cin>>tmp1>>tmp2;
		while(set[tmp1]>=0)tmp1=set[tmp1];
		while(set[tmp2]>=0)tmp2=set[tmp2];
		if(tmp1==tmp2)continue;
		if(set[tmp1]<set[tmp2])
		{
		    set[tmp1]+=set[tmp2];
		    set[tmp2]=tmp1;
		}
		else
		{
			set[tmp2]+=set[tmp1];
		    set[tmp1]=tmp2;
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(set[i]<0)
		{
			result++;
		}
		if(set[i]<-1)
		{
			int tmp=-1*set[i];
			total+=tmp*(tmp-1)/2;
		}
	}
	//for(int i=0;i<=n;i++)cout<<set[i]<<" "; 
	cout<<total-m;
	return 0;
}
