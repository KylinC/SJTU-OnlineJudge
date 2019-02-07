#include<iostream>
using namespace std;
 
int *father;
int *flags;
int max_num = 1;
 
int get_num(int pos)
{
	int res = father[pos];
	return -1*res;
}
 
void merge(int x, int y)
{
	while (get_num(x)<0)x = father[x];
	while (get_num(y)<0)y = father[y];
	if (!get_num(x))return;
	if (!get_num(y))return;
	if (x == y)return;
	flags[get_num(x)] -= 1;
	flags[get_num(y)] -= 1;
	father[x] += father[y];
	flags[get_num(x)] += 1;
	father[y] = x;
	max_num = (get_num(x) > max_num) ? get_num(x) : max_num;
}
 
int ask(int x)
{
	int rank = 0;
	for (int i = max_num; i >= 1; i--)
	{
		rank += flags[i];
		if (rank >= x)return i;
	}
	return 0;
}
 
void erase(int x)
{
	int tmp;
	while (get_num(x) < 0)
	{
		tmp = father[x];
		father[x] = 0;
		x = tmp;
	}
	flags[get_num(x)] -= 1;
	if (get_num(x) == max_num && flags[get_num(x)] == 0)
	{
		for (int i = max_num; i >= 1; i--)
		{
			if (flags[i])
			{
				max_num = i;
				break;
			}
		}
	}
	father[x] = 0;
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	char order_str[10];
	int x, y, order;
	cin >> n >> m;
	father = new int[n + 2];
	flags = new int[n + 2];
	for (int i = 1; i <= n; i++)father[i] = -1;
	flags[1] = n;
	for (int i = 2; i <= n; i++)flags[i] = 0;
	while (m--)
	{
		cin >> order_str >> x;
		switch (order_str[0])
		{
		    case 'C':
		    {
			    cin >> y;
			    merge(x, y);
			    break;
		    }
		    case 'Q':
		    {
			    cout << ask(x) << "\n";
			    break;
		    }
		    case 'D':
		    {
			    erase(x);
			    break;
		    }
		}
	}
	return 0;
}
