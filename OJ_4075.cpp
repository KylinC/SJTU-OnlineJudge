#include<iostream>
using namespace std;
int len[100001];
 
int main()
{
	char a[1000001], b[100001];
	cin >> a >> b;
	int i = 1, j = 0, tmp, pos = 0;
	len[0] = -1;
	while (b[i])
	{
		tmp = len[i - 1];
		while (tmp != -1 && b[tmp + 1] != b[i])
		{
			tmp = len[tmp];
		}
		if (b[tmp + 1] == b[i])
		{
			len[i] = tmp + 1;
		}
		else
		{
			len[i] = -1;
		}
		++i;
	}
	i = j = -1;
	while (a[i + 1] && b[j + 1])
	{
		if (a[i + 1] == b[j + 1])
		{
			i++;
			j++;
		}
		else
		{
			j = len[j];
			if (j == -1)i++;
			pos = i - j;
		}
	}
	cout << pos;
 
	return 0;
}
