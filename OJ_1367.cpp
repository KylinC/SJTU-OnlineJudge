#include<iostream>
using namespace std;
 
struct Tree
{
	Tree *left, *right;
	Tree():left(NULL),right(NULL){}
};
 
int main()
{
	Tree *root = new Tree, *ptr;
	int n, m, elem;
	cin >> n >> m;
	while (n--)
	{
		ptr = root;
		cin >> elem;
		for (int i = 30; i >= 0; i--)
		{
			if ((1 << i)&elem)
			{
				if (!ptr->left)
				{
					ptr->left = new Tree;
				}
				ptr = ptr->left;
			}
			else
			{
				if (!ptr->right)
				{
					ptr->right = new Tree;
				}
				ptr = ptr->right;
			}
		}
	}
 
	int max_all = 0, tmp;
 
	while (m--)
	{
		cin >> elem;
		ptr = root;
		tmp = 0;
		for (int i = 30; i >= 0; i--)
		{
			if ((1 << i)&elem)
			{
				if (ptr->right)
				{
					ptr = ptr->right;
					tmp += (1 << i);
				}
				else ptr = ptr->left;
			}
			else
			{
				if (ptr->left)
				{
					ptr = ptr->left;
					tmp += (1 << i);
				}
				else ptr = ptr->right;
			}
		}
		max_all = (max_all > tmp) ? max_all : tmp;
	}
	cout << max_all;
 
	return 0;
}
