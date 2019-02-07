#include<iostream>
using namespace std; 
 
int binarySearch(int array[], int low, int high, int target) {
	int middle = (low + high)/2;
	if(target<=array[middle]&&target>=array[middle-1]) {
		if(target<array[middle]) return 1-middle;
		else return -middle;
	}
	if(target <= array[middle]) {
		return binarySearch(array, low, middle, target);
	}
	if(target > array[middle]) {
		return binarySearch(array, middle, high, target);
	} 
}
 
int main()
{
	int n,t;
	scanf("%d %d",&n,&t);
	int n_con[n+2],t_con[t];
	int tmp;
	int *result=new int[t];
	for(int i=0;i<t;i++)
	{
		result[i]=0;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&tmp);
		n_con[i]=tmp;
	}
	n_con[0]=-1;
	n_con[n+1]=2000000001;
	for (int i=0;i<t;i++)
	{
		scanf("%d",&tmp);
		t_con[i]=tmp;
	}
	
	for (int i=0;i<t;i++)
	{
		result[i]=n+binarySearch(n_con,0,n+2,t_con[i]);
	}
	
	for(int i=0;i<t;i++)
	{
		tmp=result[i];
		printf("%d\n",tmp);
	}
}
