#include<cstdio>
#include<iostream>
using namespace std;
 
int *origin, *peak;
int main()
{
	int n, left=0, right=0, high, ptr=0,ans=0;
	char ch;
	scanf("%d\n", &n);
	origin = new int[n];
	peak = new int[n];
	scanf("[%d", &origin[0]);
	high=origin[0];
	for (int i = 1; i < n; i++)
	{
		scanf(",%d", &origin[i]);
		if(origin[i]>high)high=origin[i];
	}
	for(int i=0;i<n;i++)
	{
		if(origin[i]==high)
		{
			peak[ptr]=i;
			ptr++;
		}
	}
	int temp=0;
	for(int i=0;i<=peak[0];i++)
	{
		if(left<origin[i])
		{
			left=origin[i];
			ans+=temp;
			temp=0;
		}
		else
		{
			temp+=left-origin[i];
		}
	}
	temp=0;
	for(int i=n-1;i>=peak[ptr-1];i--)
	{
		if(right<origin[i])
		{
			right=origin[i];
			ans+=temp;
			temp=0;
		}
		else
		{
			temp+=right-origin[i];
		}
	}
	for (int i = 1; i < ptr; i++)
	{
		for (int j = peak[i - 1]; j <= peak[i]; j++)
		{
			ans += (high - origin[j]);
		}
	}
	printf("%d",ans);
	
	return 0;
}
