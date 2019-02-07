#include<iostream>
using namespace std;
 
struct Node
{
	Node *left,*right,*parent;
	int val;
};
 
Node* con[100001];
 
class Tree
{
private:
	Node *root;
	void clear(Node *tmp)
	{
		con[tmp->val]=0;
		if(tmp->left)clear(tmp->left);
		if(tmp->right)clear(tmp->right);
		delete tmp;
	}
	void preOrder(Node* p)
	{
		if(!p)return;
		cout<<p->val<<" ";
		preOrder(p->left);
		preOrder(p->right);
	}
public:
	Tree()
	{
		root=new Node;
		root->val=1;
		root->parent=root->left=root->right=NULL;
		con[1]=root;
	}
	~Tree()
	{
		clear(root);
	}
	void build(int parent,int left,int right)
	{
		if(con[left]||con[right]||!con[parent])
		{
			cout<<"Error!\n";
			return;
		}
		Node* tmp=con[parent];
		if(tmp->left||tmp->right)
		{
			cout<<"Error!\n";
			return;
		}
		Node* nleft=new Node;
		Node* nright=new Node;
		nleft->val=left;
		nright->val=right;
		nleft->parent=tmp;
		nright->parent=tmp;
		nleft->left=nleft->right=nright->left=nright->right=NULL;
		tmp->left=nleft;
		tmp->right=nright;
		con[left]=nleft;
		con[right]=nright;
		cout<<"Ok!\n";
	}
	void search(int a)
	{
		if(!con[a])
		{
			cout<<"Error!\n";
			return;
		}
		Node* tmp=con[a];
		if(tmp->parent)cout<<tmp->parent->val<<" ";
		else cout<<"0 ";
		if(tmp->left)cout<<tmp->left->val<<" ";
		else cout<<"0 ";
		if(tmp->right)cout<<tmp->right->val<<" ";
		else cout<<"0\n";
	}
	
	void swap(int a)
	{
		Node* tmp=con[a];
		if(!tmp||a==1)
		{
			cout<<"Error!\n";
			return;
		}
		Node* p=tmp->parent;
		if(p->left==tmp)
		{
			p->left=p->right;
			p->right=tmp;
			if(p->left)cout<<p->left->val<<"\n";
			else cout<<"0\n";
		}
		else if(p->right==tmp)
		{
			p->right=p->left;
			p->left=tmp;
			if(p->right)cout<<p->right->val<<"\n";
			else cout<<"0\n";
		}
	}
	
	void preOrder()
	{
		preOrder(root);
	}
};
 
int main()
{
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int loop;
	cin>>loop;
	int choice,a,b,c;
	Tree tree;
	while(loop--)
	{
		cin>>choice;
		switch(choice)
		{
			case 1:cin>>a>>b>>c;tree.build(a,b,c);break;
			case 2:cin>>a;tree.search(a);break;
			case 3:cin>>a;tree.swap(a);break;
		}
	}
	tree.preOrder();
	return 0;
}
