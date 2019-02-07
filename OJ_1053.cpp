#include<iostream>
using namespace std;
 
struct Node
{
	int *x,*y;
	int val;
	Node* next;
	Node(int *a,int *b,int c,Node* node=NULL) :x(a),y(b),val(c),next(node) { }
};
 
Node *x_con[100000],*y_con[100000];
int x_init[100000],y_init[100000];
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int num,x,y,val;
	cin>>num;
	Node *tmp;
	while(num--)
	{
		cin>>x>>y>>val;
		x_init[x]=x;
		y_init[y]=y;
		tmp=new Node(x_init+x,y_init+y,val,x_con[x]);
		x_con[x]=tmp;
		tmp=new Node(x_init+x,y_init+y,val,y_con[y]);
		y_con[y]=tmp;
	}
	cin>>num;
	while(num--)
	{
		cin>>val>>x>>y;
		switch(val)
		{
			case 0:
				{
					tmp = x_con[x];
			        x_con[x] = x_con[y];
			        x_con[y] = tmp;
			        if(x_con[x]) *(x_con[x]->x)=x;
			        if(x_con[y]) *(x_con[y]->x)=y;
			        break;
				}
			case 1:
				{
					tmp = y_con[x];
			        y_con[x] = y_con[y];
			        y_con[y] = tmp;
			        if(y_con[x]) *(y_con[x]->y)=x;
			        if(y_con[y]) *(y_con[y]->y)=y;
			        break;
				}
			case 2:
				{
					if(!x_con[x]||!y_con[y])
					{
						cout<<"0\n";break;
					}
					tmp=x_con[x];
					while(tmp&&*(tmp->y)!=y)tmp=tmp->next;
					if(tmp)cout<<tmp->val<<'\n';
					else cout<<"0\n";
					break;
				}
		}
	}
}
