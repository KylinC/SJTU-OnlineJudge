#include <iostream>
using namespace std;
 
class BTree
{
	struct Node
	{
		Node():var(0),left(0),right(0),parent(0){
		}
		int var;
		int left,right,parent;
	};
public:
	BTree():data(NULL),size(0),head(0){}
	BTree(int init=0):size(init)
	{
		data = new Node[size + 1];
		build();
		get_head();
	}
	~BTree(){delete []data;}
	void get_head()
	{
		int i = 1;
		while (data[i].parent != 0)
			i = data[i].parent;
		head = i;
	}
	void build()
	{
		int p, q;
		for (int i = 1; i <= size; ++i)
		{
			cin >> p >> q;
			data[i].left = p;
			data[i].right = q;
			data[p].parent = data[q].parent = i;
		}
	}
	bool isComplete()
	{
		int *que=new int[size];
		int cock=0;
		int tail=0;
		
		que[tail++]=head;
		data[head].var = 1;
		
		int tmp;
		while (cock != tail)
		{
			tmp = que[cock++];
			if (data[tmp].left != 0)
			{
				que[tail] = data[tmp].left;
				data[que[tail++]].var = data[tmp].var * 2;
			}
			if (data[tmp].right != 0)
			{
				que[tail] = data[tmp].right;
				data[que[tail++]].var = data[tmp].var * 2 + 1;
			}
		}
		delete[]que;
		return data[tmp].var == size;
	} 
private:
	Node* data;
	int size;
	int head;
};
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	int num;
    cin >> num;
    BTree con(num);
    if(con.isComplete())cout<<"Y";
    else cout<<"N";
    return 0;
}
