#include<iostream>
using namespace std;
 
int *a,*b,*c;
 
int main()
{
	int m,n;
	cin>>m>>n;
	a=new int[m];
	b=new int[n];
	c=new int[m+n];
	for(int i=0;i<m;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	if(m==0)
	{
		for(int i=0;i<n;i++)cout<<b[i]<<' ';
		return 0;
	}
	if(n==0)
	{
		for(int i=0;i<m;i++)cout<<a[i]<<' ';
		return 0;
	}
	int i=0,j=0,k=0;
	while(i<m&&j<n)
	{
		if(a[i]<=b[j])
		{
			c[k]=a[i];
			k++;
			i++;
		}
		else
		{
			c[k]=b[j];
			k++;
			j++;
		}
	}
	while(i<m)
	{
		c[k]=a[i];
		k++;
		i++;
	}
	while(j<n)
	{
		c[k]=b[j];
		k++;
		j++;
	}
	
	for(int i=0;i<m+n;i++)
	{
		cout<<c[i]<<' ';
	}
	
	return 0;
}
