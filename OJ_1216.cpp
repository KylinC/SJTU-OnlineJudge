#include<iostream>
using namespace std;
 
class queHeap
{
	int capacity,size,*que;
public:
	queHeap(int num=10):capacity(num)
	{
		size=0;
		que=new int[capacity+1];
	}
	~queHeap()
	{
		delete []que;
	}
	void insert(int tmp)
	{
		size++;
		int op=size;
		for(;op>=2&&tmp<que[op/2];op/=2)que[op]=que[op/2];
		que[op]=tmp;
	}
	int find(int tmp)
	{
		int aim,sub_min,i=0;
		while(que[++i]<=tmp);
		sub_min=que[i]-tmp;
		aim=i;
		for(int j=i+1;j<=size;j++)
		{
			if(que[j]>tmp&&que[j]-tmp<sub_min)
			{
			    aim=j;
			    sub_min=que[j]-tmp;
			}
		}
		return aim;
	 }
	void decrease(int pos,int level)
	{
		int tmp=que[pos]-level,op=pos;
		for(;op>=2&tmp<que[op/2];op/=2)que[op]=que[op/2];
		que[op]=tmp;
	}
};
 
int main()
{
	int loop,num,level;
	char order[20];
	cin>>loop;
	queHeap con(loop);
	while(loop--)
	{
		cin>>order;
		if(order[0]=='i')
		{
			cin>>num;
			con.insert(num);
		}
		if(order[0]=='f')
		{
			cin>>num;
			cout<<con.find(num)<<'\n';
		}
		if(order[0]=='d')
		{
			cin>>num>>level;
			con.decrease(num,level);
		}
	}
}
