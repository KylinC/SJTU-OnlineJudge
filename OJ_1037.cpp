#include<iostream>
using namespace std;
 
int *gh,*gl;
 
int partition(int *a,int low,int high)
{
	int x=a[high];
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(a[j]>x)
		{
			i++;
			int tmp;
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
		}
	}
	a[high]=a[i+1];
	a[i+1]=x;
	return i+1;
}
 
void quickSort(int *a,int low,int high)
{
	if(low<high)
	{
		int tmp=partition(a,low,high);
		quickSort(a,low,tmp-1);
		quickSort(a,tmp+1,high);
	}
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	gh=new int[n];gl=new int[m];
	for(int i=0;i<n;i++)
	{
		cin>>gh[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>gl[i];
	}
	quickSort(gh,0,n-1);
	quickSort(gl,0,m-1);
 
	int i=0,j=0,count=0;
	while(i<n&&j<m)
	{
		if(gh[i] > gl[j])
		{
			count+=2;
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}
	if(i<n)count+=n-i;
	
	cout<<count;
}
