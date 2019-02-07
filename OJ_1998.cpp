#include<iostream>
using namespace std;
 
double n1[100005],n2[100005];
void sort(double* s,int l,int r);
 
int main()
{
	int n;
    long long sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>n1[i];
    sort(n1,0,n-1);
    for(int i=n-1;i>=0;i--)
        n2[n-1-i]=n1[i];
    for(int i=0;n1[i]<n2[i];i++)
        sum+=n2[i]-n1[i];
    cout<<sum<<endl;
    return 0;
}
 
void sort(double* s, int l, int r)
{
	if (l< r)
	{      
		int i = l, j = r;
		double x = s[l];
		while (i < j)
		{
			while(i < j && s[j]>= x) 
				j--; 
			if(i < j)
				s[i++] = s[j];
			while(i < j && s[i]< x) 
				i++; 
			if(i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		sort(s, l, i - 1);
		sort(s, i + 1, r);
	}
}
