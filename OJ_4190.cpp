#include<iostream>
using namespace std;
 
struct Node
{
	int l, r, v;
	Node *left, *right;
};
 
Node* root;
 
void insert(Node *&T, int tmp_v)
{
	if (T == NULL)
	{
		T = new Node();
		T->v = tmp_v;
		T->left = T->right = NULL;
		T->l = T->r = 0;
		return;
	}
	if (tmp_v <= T->v)
	{
		insert(T->left, tmp_v);
		T->l++;
	}
	else
	{
		insert(T->right, tmp_v);
		T->r++;
	}
}
 
int query(Node *T, int aim)
{
	int num = T->l;
	if (aim == num + 1) return T->v;
	if (aim < num + 1) return query(T->left, aim);
	else return query(T->right, aim - num - 1);
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tmp, n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		insert(root,tmp);
		if (i % 2 == 0)cout << query(root,(i + 2) / 2)<<" ";
	}
	return 0;
}
