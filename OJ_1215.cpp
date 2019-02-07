#include<iostream>
using namespace std;
 
const int MAXN=20; 
 
class queHeap
{
	struct tree
	{
		tree(){
		}
		tree(int num):left(NULL),right(NULL),val(num){
		}
		tree *left,*right;
		int val;
	};
	void clear(tree*& t)
	{
		if(t->left!=NULL)clear(t->left);
		if(t->right!=NULL)clear(t->right);
		delete t;
	}
	void insert(tree*& t,int pos)
	{
		tree* tmp;
		if(con[pos]==NULL)
		{
			con[pos]=t;
			return;
		}
		if(!pos)
		{
			if(con[0]->val<t->val)
			{
				con[0]->left=t;
				t=con[0];
				con[0]=NULL;
				insert(t,1);
			}
			else
			{
				t->left=con[0];
				con[0]=NULL;
				insert(t,1);
			}
			return;
		}
		if(con[pos]->val<t->val)
		{
			tmp=con[pos]->left;
			for(int i=1;i<pos;++i)tmp=tmp->right;
			tmp->right=t;
			t=con[pos];
			con[pos]=NULL;
			insert(t,pos+1);
		}
		else
		{
			tmp=t->left;
			for(int i=1;i<pos;++i)tmp=tmp->right;
			tmp->right=con[pos];
			con[pos]=NULL;
			insert(t,pos+1);
		}
	}
	tree* con[MAXN];
public:
	queHeap()
	{
		for(int i=0;i<MAXN;++i)con[i]=NULL;
	}
	queHeap(const queHeap& tmp)
	{
		for(int i=0;i<MAXN;++i)con[i]=tmp.con[i];
	}
	~queHeap()
	{
		for(int i=0;i<MAXN;++i)
		{
			if(con[i]!=NULL)clear(con[i]);
		}
	}
	void insert(int num)
	{
		tree *tmp=new tree(num);
		insert(tmp,0);
	}
	int min()
	{
		int tmp,t=-1;
		while(con[++t]==NULL);
		tmp=con[t]->val;
		for(int i=t+1;i<MAXN;i++)
		{
			if(con[i]!=NULL&&con[i]->val<tmp)tmp=con[i]->val;
		}
		return tmp;
	}
	int min_pos()
	{
		int tmp,t=-1;
		while(con[++t]==NULL);
		tmp=t;
		for(int i=t+1;i<MAXN;i++)
		{
			if(con[i]!=NULL&&con[i]->val<con[tmp]->val)tmp=i;
		}
		return tmp;
	}
	void delete_min()
	{
		int t=min_pos();
		tree *tmp=con[t]->left,*p;
		delete con[t];
		con[t]=NULL;
		for(int i=0;i<t;++i)
		{
			p=tmp->right;
			tmp->right=NULL;
			insert(tmp,i);
			tmp=p;
		}
	}
};
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int loop,num;
	char order[20];
	queHeap que;
	cin>>loop;
	while(loop--)
	{
		cin>>order;
		if(order[0]=='i')
		{
			cin>>num;
			que.insert(num);
		}
		if(order[0]=='m')
		{
			cout<<que.min()<<'\n';
		}
		if(order[0]=='d')
		{
			que.delete_min();
		}
	}
}
