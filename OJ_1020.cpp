#include<iostream>
#include<cmath>
using namespace std;
 
bool isPrime(int num)
{
	if(num==2)return true;
    if(num%2==0)return false;
    int border=sqrt(num)+1;
    for(int i=3;i<border;i+=2)
    {
    	if(num%i==0)
    	{
    		return false;
		}
	}
	return true;
}
 
 
int main()
{
	int n[100];
	for(int i=0;i<=100;i++)
	{
		n[i]=0;
	}
	
	int num,container,count=0;
	cin>>num; 
	container=num;
	
	int limit=sqrt(num);
	
	if (isPrime(num))
	{
		cout<<container<<"="<<container<<"(1)";
		return 0;
	}
	for(int i=2;i<container;i++)
	{
		while(num%i==0)
		{
			n[count]=i;
			count++;
			num/=i;
		}
		if(num==1)
		{
			break;
		}
		if(isPrime(num))
		{
			n[count]=num;
			count++;
			break;
		}
	}
	cout<<container<<"=";
	for(int i=0;n[i]!=0;i++)
	{
		count=1;
		for(int j=i+1;n[j]!=0;j++)
		{
			if(n[i]==n[j])
			{
				count++;
				i=j;
			}
		}
		cout<<n[i]<<"("<<count<<")";
	}
	
	return 0;
}
