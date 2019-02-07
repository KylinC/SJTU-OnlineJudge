#include<iostream>
using namespace std;
 
int main()
{
	int father[100001],father_list[100001];
	int left,right,n,x,y,size=0;
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
	{
		cin>>left>>right;
		if(left!=0)father[left]=i;
		if(right!=0)father[right]=i;
	}
	while(x!=0)
	{
		father_list[++size]=x;
		x=father[x];
	}
	while(y!=0)
	{
		for(int i=1;i<=size;i++)
		{
			if(father_list[i]==y)
			{
				cout<<y;
				return 0;
			}
		}
		y=father[y];
	}
	return 0;
}
