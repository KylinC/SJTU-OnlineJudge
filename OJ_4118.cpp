#include<iostream>
using namespace std;
const int MAXN=100005;
const int np = 31;
string tmp;
unsigned long long* hush[MAXN], length[MAXN], con[MAXN];
 
void scope(int x, int y, int& a, int& b, int state)
{
	int mid = 0;
	while (a < b) {
		mid = (a + b) >> 1;
		if (hush[x][mid] == hush[y][mid]) a = mid + 1;
		else b = mid - 1;
	}
	while (hush[x][a] == hush[y][a]) a++;
}
 
void scope(int x, int y, int& a, int& b)
{
	int mid = 0;
	while (a < b) {
		mid = (a + b) >> 1;
		if ((hush[x][length[x] - 1] - hush[x][length[x] - 2 - mid] * con[mid + 1] == hush[y][length[y] - 1] - hush[y][length[y] - 2 - mid] * con[mid + 1])) a = mid + 1;
		else b = mid - 1;
	}
	while (hush[x][length[x] - 1] - hush[x][length[x] - 2 - a] * con[a + 1] == hush[y][length[y] - 1] - hush[y][length[y] - 2 - a] * con[a + 1]) a++;
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	con[0] = 1;
	for (int i = 1; i < MAXN; ++i)
	{
		con[i] = con[i - 1] * np;
	}
	int n, m, order;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		length[i] = tmp.length();
		hush[i] = new unsigned long long[tmp.length()];
		hush[i][0] = tmp[0];
		for (int j = 1; j < tmp.length(); ++j)
		{
			hush[i][j] = hush[i][j - 1] * np + tmp[j];
		}
	}
	int x, y, a, b, i;
	cin >> m;
	while (m--)
	{
		cin >> order;
		switch (order)
		{
		case 1:
			cin >> x;
			i = 1;
			for (; i < x; ++i)
			{
				if (hush[i][length[i] - 1] == hush[x][length[x] - 1])
				{
					cout << "yes\n";
					break;
				}
			}
			if (i == x) cout << "no\n";
			break;
		case 2:
			cin >> x >> y;
			a = 0;
			b = (length[x] < length[y]) ? (length[x] - 1) : (length[y] - 1);
			scope(x, y, a, b, 1);
			cout << a << "\n";
			break;
		case 3:
			cin >> x >> y;
			a = 0;
			b = (length[x] < length[y]) ? (length[x] - 1) : (length[y] - 1);
			scope(x, y, a, b);
			cout << a << "\n";
			break;
		}
	}
	return 0;
}
