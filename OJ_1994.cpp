#include<iostream>
using namespace std;
 
int a[505][505];
 
void cover(int n,int m)
{
	if(a[n][m]==-1)return;
	a[n][m]=-1;
	if(n>1)cover(n-1,m);
	if(m>1)cover(n,m-1);
	cover(n+1,m);
	cover(n,m+1);
}
 
int main()
{
	int n,m;
	int count=0;
	cin>>n>>m;
	for(int i=0;i<=n+3;i++)
	{
		for(int j=0;j<m+3;j++)
		{
			a[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//cout<<"! ";
			if(a[i][j]==0)
			{
				count++;
				cover(i,j);
			}
		}
	}
	
	cout<<count;
	return 0;
}
