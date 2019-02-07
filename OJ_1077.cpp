#include<iostream>
#include<cstring>
using namespace std;
 
int con[31];
int root[31][31];
int mat[31][31];
 
void process(int n)
{
	int tmp;
	for(int d=1;d<=n-1;d++)
	{
		for(int i=1;i<=n-d;i++)
		{
			mat[i][i+d]=mat[i][i]+mat[i+1][i+d]*1;
			root[i][i+d]=i;
			for(int j=i+1;j<=i+d;j++)
			{
				tmp=mat[j][j]+mat[i][j-1]*mat[j+1][i+d];
				if(tmp>mat[i][i+d])
				{
					mat[i][i+d]=tmp;
					root[i][i+d]=j;
				}
			}
		}
	}
}
 
void preOrder(int x1, int x2)
{
	if (x1 <= x2)
	{
		cout << root[x1][x2] << " ";
		preOrder(x1, root[x1][x2] - 1);
		preOrder(root[x1][x2] + 1, x2);
	}
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int num;
	cin>>num;
	for(int i=1;i<=num;i++)
	{
		cin>>con[i];
	}
	memset(mat,0,sizeof(mat));
	for(int i=1;i<=num;i++)
	{
		mat[i][i]=con[i];
		root[i][i]=i;
	}
	process(num);
	cout<<mat[1][num]<<"\n";
	preOrder(1,num);
	
	return 0;
}
