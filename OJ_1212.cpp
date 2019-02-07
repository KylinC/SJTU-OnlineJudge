#include <iostream>
using namespace std;
 
template<class elemType>
class queue
{
public:
	queue(int size=10)
	{
		elem = new elemType[size];
		maxSize = size;
		front = rear = 0;
	}
	~queue()
	{
		delete[]elem;
	}
	bool empty()
	{
		return front == rear;
	}
	void push(const elemType &x)
	{
		if ((rear + 1) % maxSize == front)doubleSpace();
		rear = (rear + 1) % maxSize;
		elem[rear] = x;
	}
	elemType pop()
	{
		front = (front + 1) % maxSize;
		return elem[front];
	}
	int size()
	{
		return rear - front;
	}
private:
	elemType* elem;
	int maxSize;
	int front, rear;
	void doubleSpace()
	{
		elemType *tmp = elem;
		elem = new elemType[2 * maxSize];
		for (int i = 1; i < maxSize; ++i)
		{
			elem[i] = tmp[(front + i) % maxSize];
		}
		front = 0; rear = maxSize-1;
		maxSize *= 2;
		delete tmp;
	}
};
 
class BinaryTree
{
private:
	struct node
	{
		node *left, *right, *parent;
		int data;
		node(node *l = NULL, node *r = NULL, node *f = NULL) : left(l), right(r), parent(f) {}
		~node() {}
	};
	node *root;
public:
	BinaryTree()
	{
		root = new node;
	}
	~BinaryTree()
	{
		Clear();
	}
	void Clear()
	{
		if (root)
			Clear(root);
		root = NULL;
	}
	void Build(BinaryTree &x, BinaryTree &y, int v)
	{
		root->data = v;
		root->left = x.root;
		root->right = y.root;
		if (x.root)
			x.root->parent = root;
		if (y.root)
			y.root->parent = root;
	}
	bool Is_root()
	{
		return !(root->parent);
	}
	void print()
	{
		queue<node*> q;
		q.push(root);
		while (!q.empty())
		{
			node *t = q.pop();
			cout << t->data << ' ';
			if (t->left)
				q.push(t->left);
			if (t->right)
				q.push(t->right);
		}
	}
private:
	void Clear(node *x)
	{
		if (x->left)
			Clear(x->left);
		if (x->right)
			Clear(x->right);
		delete x;
	}
};
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, x, y, v;
	cin >> n;
	BinaryTree *Tree = new BinaryTree[n + 1];
	Tree[0].Clear();
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y >> v;
		Tree[i].Build(Tree[x], Tree[y], v);
	}
	for (int i = 1; i <= n; i++)
		if (Tree[i].Is_root())
			Tree[i].print();
	return 0;
}
