#include<iostream>
#include<cstring>
using namespace std;
 
void preOrder(int* pre,int* equ,int* val,int root)
{
	cout<<val[root]<<" ";
	if(pre[root])
	{
		preOrder(pre,equ,val,pre[root]);
		int tmp=pre[root];
		while(equ[tmp])
		{
			preOrder(pre,equ,val,equ[tmp]);
			tmp=equ[tmp];
		}
	}
}
 
void postOrder(int* pre,int* equ,int* val,int root)
{
	if(pre[root])
	{
		postOrder(pre,equ,val,pre[root]);
		int tmp=pre[root];
		while(equ[tmp])
		{
			postOrder(pre,equ,val,equ[tmp]);
			tmp=equ[tmp];
		}
	}
	cout<<val[root]<<" ";
}
 
void levelOrder(int* pre,int* equ,int* val,int root,int num)
{
	int *que=new int[num+1];
	que[1]=root;
	int tail=2,head=1,tmp;
	while(head!=tail)
	{
		tmp=pre[que[head]];
		if(tmp)
		{
			que[tail++]=tmp;
			while(equ[tmp])
			{
				tmp=equ[tmp];
				que[tail++]=tmp;
			}
		}
		head++;
	}
	for(int i=1;i<=num;i++)
	{
		cout<<val[que[i]]<<" ";
	}
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int num,root;
	cin>>num;
	int *pre=new int[num+1],*equ=new int[num+1],*val=new int[num+1],*flag=new int[num+1];
	memset(flag,0,num+1);
	for(int i=1;i<=num;i++)
	{
		cin>>pre[i]>>equ[i]>>val[i];
		flag[pre[i]]=1;
		flag[equ[i]]=1;
	}
	for(int i=1;i<=num;i++)
	{
		if(!flag[i])
		{
			root=i;
			break;
		}
	}
	preOrder(pre,equ,val,root);
	cout<<"\n";
	postOrder(pre,equ,val,root);
	cout<<"\n";
	levelOrder(pre,equ,val,root,num);
	cout<<flush;
	return 0;
}
