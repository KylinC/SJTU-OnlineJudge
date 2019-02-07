#include<iostream>
using namespace std;
 
char map_t[105][105];
int n,m;
int x1,y1,x2,y2;
int result[105][105];
 
bool check(int x,int y)
{
	if(x<=0||x>n||y<=0||y>m)return false;
	return true;
}
 
void infect(int x,int y,int flag)
{
	//cout<<"("<<x<<","<<y<<")";
	if(result[x][y]>flag+1||result[x][y]==-1)result[x][y]=flag+1;
	else return;
	if(map_t[x][y]=='.')
	{	
	    if(check(x-1,y)&&(map_t[x-1][y]=='.'||map_t[x-1][y]=='|'))infect(x-1,y,flag+1);
	    if(check(x+1,y)&&(map_t[x+1][y]=='.'||map_t[x+1][y]=='|'))
		{
			infect(x+1,y,flag+1);
		}
	    if(check(x,y+1)&&(map_t[x][y+1]=='.'||map_t[x][y+1]=='-'))infect(x,y+1,flag+1);
	    if(check(x,y-1)&&(map_t[x][y-1]=='.'||map_t[x][y-1]=='-'))infect(x,y-1,flag+1);
	}
	else if(map_t[x][y]=='-')
	{
		if(check(x,y+1)&&(map_t[x][y+1]=='.'||map_t[x][y+1]=='-'))infect(x,y+1,flag+1);
	    if(check(x,y-1)&&(map_t[x][y-1]=='.'||map_t[x][y-1]=='-'))infect(x,y-1,flag+1);
	}
	else if(map_t[x][y]=='|')
	{
	    if(check(x-1,y)&&(map_t[x-1][y]=='.'||map_t[x-1][y]=='|'))infect(x-1,y,flag+1);
	    if(check(x+1,y)&&(map_t[x+1][y]=='.'||map_t[x+1][y]=='|'))infect(x+1,y,flag+1);
	}
}
 
int main()
{
	cin>>n>>m;
	cin>>x1>>y1>>x2>>y2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>map_t[i][j];
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<map_t[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			result[i][j]=-1;
		}
	}
	infect(x1,y1,-1);
	cout<<result[x2][y2];
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	return 0;
}
