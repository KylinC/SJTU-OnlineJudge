#include<iostream>
#include<cstring>
using namespace std;
int n, m, con[1001][1001];
char a[1001],b[1001];
int main()
{
	memset(con,0,sizeof(con));
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)
	        if(a[i]==b[j]) con[i][j]=con[i-1][j-1]+1;
	        else con[i][j]=(con[i][j-1]>con[i-1][j])?con[i][j-1]:con[i-1][j];
	cout<<con[n][m];
	return 0;
}
