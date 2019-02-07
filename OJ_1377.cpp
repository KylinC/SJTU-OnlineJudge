#include<iostream>
#include<cstring>
using namespace std; 
int *middle;
int table[200010],origin[100005];
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,b,pos,low,high,ans;
	cin>>n>>b;
	middle=table+n;
	memset(table,0,sizeof(table));
	for(int i=1;i<=n;i++)
	{
	    cin>>origin[i];
	    if(origin[i]==b)pos=i;
	}
	table[0]=1;
	low=high=0;
	for(int i=pos-1;i>0;i--)
	{
		if(origin[i]<b)low++;
		else high++;
		table[low-high]++;
	}
	ans=0;low=high=0;
	ans+=table[0];
	for(int i=pos+1;i<=n;i++)
	{
		if(origin[i]<b)low++;
		else high++;
		ans+=table[high-low];
	}
	cout<<ans;
	
	return 0;
}
