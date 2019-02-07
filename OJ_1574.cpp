#include<iostream>
using namespace std; 
 
inline int mi(int a,int b,int mo)
{
    int ans=1;
    a%=mo;
    while (b)
    {
        if (b&1) ans=ans*a%mo;
        b>>=1;
        a=a*a%mo;
    }
    return ans;
}
 
int main()
{
	int n,m,k,x;
	cin>>n>>m>>k>>x;
	cout<<((mi(10,k,n)*(m%n))%n+x)%n;
	
	return 0;
}
