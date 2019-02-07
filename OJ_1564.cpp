#include<iostream>
#include<cstring>
using namespace std;
int aim_x, aim_y, con[6][6], cess[6][6];
long long min_cost;
int add[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
void search(int x, int y, int state, int sum)
{
	if (sum > min_cost)return;
	if (x == aim_x && y == aim_y)
	{
		min_cost = (min_cost <= sum) ? min_cost : sum;
		return;
	}
	int tmp, next_x, next_y;
	for (int i = 0; i <= 3; i++)
	{
		next_x = x + add[i][0];
		next_y = y + add[i][1];
		if (next_x < 0 || next_y < 0 || next_x>5 || next_y>5)continue;
		if (cess[next_x][next_y] == 0)
		{
			cess[next_x][next_y] = 1;
			tmp = con[next_x][next_y] * state;
			search(next_x, next_y, tmp % 4 + 1, sum + tmp);
			cess[next_x][next_y] = 0;
		}
	}
}
 
int main()
{
	int loop, init_x, init_y;
	long long tmp_max;
	cin >> loop;
	while (loop--)
	{
		memset(cess, 0, sizeof(cess));
		tmp_max = 0;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				cin >> con[i][j];
				tmp_max = (con[i][j] > tmp_max) ? con[i][j] : tmp_max;
			}
		}
		cin >> init_x >> init_y >> aim_x >> aim_y;
		min_cost = tmp_max * 4 * 10;
		search(init_x, init_y, 1, 0);
		cout << min_cost << "\n";
	}
}
