#include<iostream>
using namespace std;
 
unsigned long long pos[100001];
unsigned long long height[100001];
 
int Partition(unsigned long long int a[], int low, int high)
{
    unsigned long long int x = a[high];
    unsigned long long int y = height[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (a[j] < x)
        {
            unsigned long long int temp;
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            
            temp=height[i];
            height[i]=height[j];
            height[j]=temp;
        }
    }
    a[high] = a[i + 1];
    a[i + 1] = x;
    height[high]=height[i+1];
    height[i+1]=y;
    return i + 1;
}
void QuickSort(unsigned long long int a[],int low,int high)
{
    if (low < high)
    {
        int q = Partition(a, low, high);
        QuickSort(a, low, q - 1);
        QuickSort(a, q + 1, high);
    }
}
 
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>pos[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>height[i];
	}
	QuickSort(pos,0,n-1);
 
	if(n==1||n==2)
	{
		cout<<n;
		return 0;
	}
	
	int count=0;
	for(int i=1;i<n-1;i++)
	{
		if(pos[i]>=height[i]&&pos[i]-height[i]>pos[i-1])
		{
			count++;
			continue;
		}
		if(pos[i]+height[i]<pos[i+1])
		{
			count++;
			pos[i]+=height[i];
		}
	}
	cout<<count+2;
	
	return 0;
}
