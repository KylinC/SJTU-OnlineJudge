#include<iostream>
using namespace std;
 
long long con1[410][410], con2[410][410];
long long bar[410];
long long *DP;
 
int main()
{
	int n;
	long long tmp;
	long long res = 0;
	DP = bar + 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> con1[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			con2[i + 1][j + 1] = con2[i + 1][j] + con1[i][j];
			con2[i + 1][j + 1] %= 2;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			tmp = 0;
			for (int k = 1; k <= n; k++)
			{
				if (con2[k][j] - con2[k][i - 1])
				{
					DP[k] = DP[tmp-1] + k - tmp;
					tmp = k;
				}
				else
				{
					DP[k] = DP[k - 1];
				}
 
				res += DP[k];
			}
		}
	}
	long long all = (n + 1)*n / 2;
	cout << res << " " << all*all-res;
 
	return 0;
}
