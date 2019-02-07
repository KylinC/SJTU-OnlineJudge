#include<iostream>
#include<cmath>
using namespace std;
 
bool isPrime(int i);
 
int main()
{
	int num;
	cin>>num;
	int up=num+1,down=num-1;
	if (isPrime(num)==1)
	{
		cout<<0;
		return 0;
	}
    while(isPrime(up)!=1)
    {
    	up++;
	}
	while(isPrime(down)!=1)
	{
		down--;
	}
	cout<<up-down;
}
 
bool isPrime(int i)
{
	if(i==2)return true; 
	if(i%2==0)return false;
	for(int j=3;j<=sqrt(i);j+=2)
	{
		if(i%j==0)return false;
	}
	return true;
}
