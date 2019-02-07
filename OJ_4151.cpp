#include<iostream>
using namespace std;
class Tstack
{
	int* elem;
	int maxSize;
	int top;
	public:
		Tstack(int size)
		{
			maxSize=size;
			elem=new int[size];
			top=-1;
		}
		~Tstack()
		{
			delete[] elem;
		}
		bool push(int n)
		{
			if(top+1==maxSize)
				return false;
			else
			{
				elem[++top]=n;
				return true;
			}
		}
		int gettop()
		{
			return elem[top];
		}
		bool isEmpty()
		{
			return top==-1;
		}
		int pop()
		{
			top--;
			return elem[top-1];
		}
};
bool judge(int* &x,int n)
{
	Tstack park(n);
	int ci=1;
	for(int i=0;i<n;i++)
	{
		if(!park.isEmpty()&&park.gettop()==x[i])
			park.pop();
		else if(ci<=n)
		{
			while(ci<=n&&x[i]!=ci)
			{
				if(!park.push(ci++))
					return false;
			}
			ci++;
		}
		else
			return false;
	}
	return true;
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		int *x=new int[n];
		for(int j=0;j<n;j++)
			cin>>x[j];
		if(judge(x,n))
			cout<<"Yes\n";
		else
			cout<<"No\n";
		delete[] x;
	}
	return 0;
}
