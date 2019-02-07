#include<iostream>
using namespace std;
 
class Stack
{
public:
	Stack(int num)
	{
		con=new int[num+1];
		aim=0;
		size=num;
	}
	void push(int num)
	{
		aim++;
		con[aim]=num;
	}
	int get()
	{
	    int tmp=con[aim];
	    aim--;
	    return tmp;
	}
	int look()
	{
		int tmp=con[aim];
	    return tmp;
	}
	bool empty()
	{
		return aim==0;
	}
	bool full()
	{
		return aim>=size;
	}
private:
	int size;
	int aim;
	int* con;
};
 
int main()
{
	int loop,que,con,check,*stack;
	int count;
	bool flag;
	cin>>loop;
	Stack* k;
	while(loop--)
	{
		cin>>que>>con;
		stack=new int[que];
		k=new Stack(con+1);
		for(int i=0;i<que;i++)
		{
			cin>>stack[i];
		}
		check=0;
		count=0;
		flag=true;
		while(1)
		{
			k->push(check);
			check++;
			while(k->look()==stack[count])
			{
				if(k->empty())
				{
					break;
				}
				k->get();
				count++;
			}
			if(count>=que-1)break;
			if(k->full())
			{
				flag=false;
				break;
			}
		}
 
		
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
   }
}
