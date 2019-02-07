#include<iostream>
using namespace std;
 
char *con;
int index;
 
void preOrder(char* str,int num,int root,int state=0)
{
	if(root>num)return;
	
	if(!state)
	{
		cout<<str[root-1];
		preOrder(str,num,root*2);
		preOrder(str,num,root*2+1);
	}
	else
	{
		con[root-1]=str[index];
		index++;
		preOrder(str,num,root*2,state);
		preOrder(str,num,root*2+1,state);
	}
}
 
void inOrder(char* str,int num,int root,int state=0)
{
	if(root>num)return;
	
	if(!state)
	{
		inOrder(str,num,root*2);
		cout<<str[root-1];
		inOrder(str,num,root*2+1);
	}
	else
	{
		inOrder(str,num,root*2,state);
		con[root-1]=str[index];
		index++;
		inOrder(str,num,root*2+1,state);
	}
}
 
void postOrder(char* str,int num,int root,int state=0)
{
	if(root>num)return;
	
	if(!state)
	{
		postOrder(str,num,root*2);
		postOrder(str,num,root*2+1);
		cout<<str[root-1];
	}
	else
	{
		postOrder(str,num,root*2,state);
		postOrder(str,num,root*2+1,state);
		con[root-1]=str[index];
		index++;
	}
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int loop,state,num;
	char order1[20],order2[20];
	char *str;
	cin>>loop;
	while(loop--)
	{
		cin>>num>>order1>>order2;
		str=new char[num+1];
		cin>>str;
		if(order1[0]=='I')
		{
			if(order2[0]=='E')
			{
				inOrder(str,num,1);
				cout<<"\n";
			}
			else
			{
				con=new char[num+1];
				index=0;
				inOrder(str,num,1,1);
				con[num]='\0';
				cout<<con<<"\n";
				delete []con;
			}
		}
		
		if(order1[0]=='P'&&order1[1]=='R')
		{
			if(order2[0]=='E')
			{
				preOrder(str,num,1);
				cout<<"\n";
			}
			else
			{
				con=new char[num+1];
				index=0;
				preOrder(str,num,1,1);
				con[num]='\0';
				cout<<con<<"\n";
				delete []con;
			}
		}
		
		if(order1[0]=='P'&&order1[1]=='O')
		{
			if(order2[0]=='E')
			{
				postOrder(str,num,1);
				cout<<"\n";
			}
			else
			{
				con=new char[num+1];
				index=0;
				postOrder(str,num,1,1);
				con[num]='\0';
				cout<<con<<"\n";
				delete []con;
			}
		}
		delete[]str;
	}
	
	return 0;
}
