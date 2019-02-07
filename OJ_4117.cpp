#include<iostream>
using namespace std;
long long con[100005];
 
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long int n,m,sum,a,b,c;
	char order;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>con[i];
	}
	while(m--)
	{
		cin>>order;
		if(order=='Q')
		{
			sum=0;
			cin>>a>>b;
			for(int i=a;i<=b;i++)sum+=con[i];
			cout<<sum<<'\n';
		}
		else
		{
			cin>>a>>b>>c;
			for(int i=a;i<=b;i++)con[i]+=c;
		}
	}
	
	return 0;
}
