#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 
long long int state,m,n,d[100050],tmp1[100050],tmp2[100050],ans;
 
int Partition(long long int a[], int low, int high)
{
    int x = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (a[j] < x)
        {
            int temp;
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    a[high] = a[i + 1];
    a[i + 1] = x;
    return i + 1;
}
void QuickSort(long long int a[],long long int low,long long int high)
{
    if (low < high)
    {
        int q = Partition(a, low, high);
        QuickSort(a, low, q - 1);
        QuickSort(a, q + 1, high);
    }
}
 
bool jduge(long long int lim)
{
    int tot=1;
    int next=1;
    int cur=1;
    while(next<=n){
        next++;
        if(d[next]-d[cur]>=lim)
		{
		    tot++;
		    cur=next;
	    }
    }
    if(tot>=m)return true;
    return false;
}
 
bool check(long long int x)
{
	int lc=d[1],tmp=1;
	for(int i=1;i<=n;i++)
	{
		tmp1[i]=1;
		tmp2[i]=1;
	}
	for(int i=2;i<=n;i++)
	{
		if(d[i]-lc<x)
		{
			tmp1[i]=tmp1[tmp];
			continue;
		}
		tmp1[i]=tmp1[tmp]+1;
		lc=d[i];
		tmp=i;
	}
	lc=d[n];
	tmp=n;
	for(int i=n-1;i>=1;i--)
	{
		if(lc-d[i]<x)
		{
			tmp2[i]=tmp2[tmp];
			continue;
		}
		tmp2[i]=tmp2[tmp]+1;
		lc=d[i];
		tmp=i;
	}
	bool p=true;
	for(int i=1;i<=n-1;i++)
	{
	    if(d[i+1]-d[i]<=x)
	    {
		    p=false;
		    if(tmp1[i]+tmp2[i+1]>=m)return true;
	    }
    }
	if(p)return true;
	else return false;
	
}
 
int main(){
    cin>>n>>m>>state;
    for(int i=1;i<=n;i++)cin>>d[i];
    QuickSort(d,1,n);
    long long int le=1,ri=d[n],mid;
    if(state==1)
    {
        while(le<=ri){
            mid=(le+ri)/2;
            if(jduge(mid)){
                ans=mid;
                le=mid+1;
            }
            else ri=mid-1;
        }
        cout<<ans;
        return 0;
    }
    else
    {
    	while(le<=ri){
            mid=(le+ri)/2;
            if(check(mid)){
                ans=mid;
                le=mid+1;
            }
            else ri=mid-1;
        }
        cout<<ans;
        return 0;
	}
}
