#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
 
class BSTree
{
	struct Node
    {
	    int val;
	    Node *left,*right;
	    Node(int value,Node *t_left=NULL,Node *t_right=NULL):val(value),left(t_left),right(t_right){}
    };
private:
	Node *root;
	int size;
public:
	BSTree()  :root(NULL),size(0) {}
	~BSTree() {clear(root);}
	int get_min(int x)
	{
		Node *t=root;
	    int ans=(t->val>=x)?(t->val-x):(x-t->val);
		while(t)
		{
			if(x<t->val)
			{
				ans=min(ans,t->val-x);
				t=t->left;
			}
			else if(x>t->val)
			{
				ans=min(ans,x-t->val);
				t=t->right;
			}
			else return 0;
		}
		return ans;
	}
	void insert(int x){insert(x,root);}
	void pop(int x) {pop(x,root);}
private:
	void insert(int x,Node *&t)
	{
		if(!t)
		{
			t=new Node(x);
			return;
		}
		if(x<=t->val) insert(x,t->left);
		else insert(x,t->right);
	}
	void pop(int x,Node *&t)
	{
		if(!t) return;
		if(x==t->val)
		{
			if(!(t->left&&t->right))
			{
				Node *p=t;
				t=(t->left)?t->left:t->right;
				delete p;
			}
			else
			{
				Node *p=t->right;
				while(p->left) p=p->left;
				t->val=p->val;
				pop(t->val,t->right);
			}
		}
		else if(x<t->val) pop(x,t->left);
		else pop(x,t->right);
	}
	void clear(Node *&t)
	{
		if(!t) return;
		clear(t->left);
		clear(t->right);
		delete t;
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	BSTree container;
	int loop,order,x;
	cin>>loop;
	while(loop--)
	{
		cin>>order>>x;
		switch(order)
		{
			case 0: 
			{
				cout<<container.get_min(x)<<'\n';
				break;
			}
			case 1: 
			{
				container.insert(x);
				break;
			}
			case 2: 
			{
				container.pop(x);
				break;
			}
		}
	}
	
	return 0;
}
