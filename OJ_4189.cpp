#include<iostream>
using namespace std;
 
struct node
{
	int index;
	int size;
	node* next;
	bool state;
	node():index(0), size(0), next(NULL), state(true) {}
	node(int ind):index(ind),size(0),next(NULL),state(true){}
	int get_size()
	{
		return 1 + size;
	}
};
node* con[100005];
int update(node* nod,int mark)
{
	node* tmp = nod;
	tmp = tmp->next;
	for(;tmp->next;tmp=tmp->next)
	{
		if (tmp->index == mark)
		{
			tmp->state = false;
			continue;
		}
		nod->size += update(con[tmp->index], nod->index);
	}
	if (tmp->index == mark)
	{
		tmp->state = false;
	}
	else
	{
		nod->size+=update(con[tmp->index], nod->index);
	}
	return nod->get_size();
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, x, y, count;
	node *tmp1, *tmp2, *tmp;
	cin >> n;
	for (int i = 1; i <= n; i++) con[i] = new node(i);
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		tmp1 = con[x];
		while (tmp1->next)tmp1 = tmp1->next;
		tmp2 = new node(y);
		tmp1->next = tmp2;
		tmp1 = con[y];
		while (tmp1->next)tmp1 = tmp1->next;
		tmp2 = new node(x);
		tmp1->next = tmp2;
	}
	update(con[1], 1);
	for (int i = 1; i <= n; i++)
	{
		bool flag = true;
		tmp = con[i];
		if (n - tmp->get_size() > n / 2)continue;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (!tmp->state)continue;
			if (con[tmp->index]->get_size() > n / 2)
			{
				flag = false;
				break;
			}
		}
		if (flag)cout << i << "\n";
	}
	return 0;
}
