#include<iostream>
#include<cstring>
using namespace std;
 
int max_len(int size,int *con)
{
	int *tmp=new int[size+1];
	int len=1,left,right,mid;
	memset(tmp,0,sizeof(tmp));
	tmp[1]=con[0];
	for(int i=1;i<size;i++)
	{
		left=0,right=len;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(tmp[mid]<con[i])left=mid+1;
			else right=mid-1;
		}
		tmp[left]=con[i];
		if(left>len)len+=1;
	}
	return len;
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int size,*con;
	cin>>size;
	con=new int[size];
	for(int i=0;i<size;i++)cin>>con[i];
	cout<<max_len(size,con);
	
	return 0;
}
