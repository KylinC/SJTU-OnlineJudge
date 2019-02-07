#include<iostream>
using namespace std;
int tmp[100001];
int *a, *b;
 
int lower_bound(int *a, int aim, int len)
{
	int l = 0, r = len - 1;
	int mid = (l + r) / 2;
	while (l < r)
	{
		if (aim == a[mid])break;
		else if (aim < a[mid])r = mid;
		else l = mid+1;
 
		mid = (l + r) / 2;
	}
	if (aim > a[mid])mid++;
	return mid;
}
 
int Lis_count(int *a, int *b, int len)
{
	int temp_len=1, tmp;
	b[0] = a[0];
	for (int i = 1; i < len; i++)
	{
		tmp = lower_bound(b, a[i], temp_len);
		b[tmp] = a[i];
		if (tmp == temp_len)temp_len++;
	}
	return temp_len;
}
 
int main()
{
	int n, x;
	cin >> n;
	a = new int[n + 1];
	b = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		tmp[x] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a[i] = tmp[x];
	}
	cout << Lis_count(a, b, n);
 
	return 0;
}
