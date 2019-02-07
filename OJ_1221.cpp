#include<iostream>
using namespace std;
 
class BStree
{
	struct node
	{
		node(int t_val,node* t_left=NULL,node* t_right=NULL) :left(t_left),right(t_right),val(t_val){}
		node *left, *right;
		int val;
	};
private:
	node* root;
	int size;
	int mark;
public:
	BStree() :size(0), root(NULL) {}
	~BStree()
	{
		clear(root);
	}
	bool find(int x)
	{
		return find(x, root);
	}
	bool find_ith(int index, int &x)
	{
		if (index > size)
			return false;
		mark = 0;
		find_ith(index, root, x);
		return true;
	}
	void insert(int x)
	{
		insert(x, root);
	}
	void del(int x)
	{
		del(x, root);
	}
	void del_less(int x)
	{
		del_less(x, root);
		if (size == 0) root = NULL;
	}
	void del_greater(int x)
	{
		del_greater(x, root);
		if (size == 0) root = NULL;
	}
	void del_interval(int a, int b)
	{
		del_interval(a, b, root);
		if (size == 0) root = NULL;
	}
private:
	void clear(node* &tmp)
	{
		if (!tmp)
			return;
		clear(tmp->left);
		clear(tmp->right);
		delete tmp;
		size--;
	}
	bool find(int x, node *tmp)
	{
		if (!tmp)
			return false;
		if (x == tmp->val)
			return true;
		else if (x < tmp->val)
			return find(x, tmp->left);
		else
			return find(x, tmp->right);
	}
	void find_ith(int index, node* tmp, int &x)
	{
		if (mark > index)
			return;
		if (tmp->left)
			find_ith(index, tmp->left, x);
		if (index == ++mark)
		{
			x = tmp->val;
			return;
		}
		if (tmp->right)
			find_ith(index, tmp->right, x);
	}
	void del_less(int x, node *&tmp)
	{
		if (!tmp) return;
		while (tmp&&x > tmp->val)
		{
			clear(tmp->left);
			node* tmp_node = tmp->right;
			delete tmp;
			tmp = tmp_node; size--;
		}
		if (tmp&&x <= tmp->val)
			del_less(x, tmp->left);
	}
	void del_greater(int x, node *&tmp)
	{
		if (!tmp) return;
		while (tmp&&tmp->val > x)
		{
			clear(tmp->right);
			node *tmp_node = tmp->left;
			delete tmp;
			tmp = tmp_node; size--;
		}
		if (tmp&&x >= tmp->val)
			del_greater(x, tmp->right);
	}
	void del_interval(int a, int b, node *&tmp)
	{
		if (a >= b || !tmp) return;
		while (tmp&&tmp->val > a&&tmp->val < b)
		{
			del(tmp->val, tmp);
		}
		if (tmp&&tmp->val >= b)
			del_interval(a, b, tmp->left);
		if (tmp&&tmp->val <= a)
			del_interval(a, b, tmp->right);
	}
	void del(int x, node *&p)
	{
		if (!p) return;
		if (x < p->val) del(x, p->left);
		else if (x > p->val) del(x, p->right);
		else if (p->left&&p->right)
		{
			node *q = p->right;
			while (q->left) q = q->left;
			p->val = q->val;
			del(p->val, p->right);
		}
		else
		{
			node *tmp_node = p;
			p = (p->left) ? p->left : p->right;
			delete tmp_node;
			size--;
		}
	}
	void insert(int x, node *&tmp)
	{
		if (tmp == NULL)
		{
			tmp = new node(x); size++;
		}
		else if (x <= tmp->val)
			insert(x, tmp->left);
		else
			insert(x, tmp->right);
	}
};
 
int main()
{
	int loop, tmp1, tmp2;
	char order[30];
	BStree tree;
 
	cin >> loop;
	while (loop--)
	{
		cin >> order;
 
		if (order[0] == 'i')
		{
			cin >> tmp1;
			tree.insert(tmp1);
		}
		else if (order[0] == 'f')
		{
			if (order[4] == '_')
			{
				cin >> tmp1;
				if (tree.find_ith(tmp1, tmp2)) cout << tmp2 << '\n';
				else cout << "N\n";
			}
			else if (order[4] == '\0')
			{
				cin >> tmp1;
				if (tree.find(tmp1)) cout << "Y\n";
				else cout << "N\n";
			}
		}
		else if (order[0] == 'd')
		{
		    if (order[6] == '\0')
		    {
			    cin >> tmp1;
			    tree.del(tmp1);
		    }
			else if (order[7] == 'l')
			{
				cin >> tmp1;
				tree.del_less(tmp1);
			}
			else if (order[7] == 'g')
			{
				cin >> tmp1;
				tree.del_greater(tmp1);
			}
			else if (order[7] == 'i')
			{
				cin >> tmp1 >> tmp2;
				tree.del_interval(tmp1, tmp2);
			}
		}
	}
}
