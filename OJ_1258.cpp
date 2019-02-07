#include<iostream>
using namespace std;
 
long long int merge(long long int* a,int l,int mid,int r)
{
	long long int count=0;
	int p1=l,p2=mid+1,i=0;
	int *tmp=new int[r-l+1];
	while(p1<=mid&&p2<=r)
	{
		count+=(a[p1]>a[p2])?(mid-p1+1):0;
		tmp[i++]=(a[p1]<=a[p2])?a[p1++]:a[p2++];
	}
	while(p1<=mid)
	{
		tmp[i++]=a[p1++];
	}
	while(p2<=r)
	{
		tmp[i++]=a[p2++];
	}
	for(i=0;i<r-l+1;i++)
	{
		a[l+i]=tmp[i];
	}
	return count;
}
 
long long int mergeSort(long long int* a,int l,int r)
{
	if(r==l)return 0;
	int mid=l+(r-l)/2;
	return mergeSort(a,l,mid)+mergeSort(a,mid+1,r)+merge(a,l,mid,r);
}
 
long long int counter(long long int *a,int size)
{
	if(size<2)return 0;
	return mergeSort(a,0,size-1);
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int num;
	long long int *a;
	cin>>num;
	a=new long long[num];
	for(int i=0;i<num;i++)
	{
		cin>>a[i];
	}
	cout<<counter(a,num);
	
	return 0;
}
