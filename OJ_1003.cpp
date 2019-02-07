#include<iostream>
using namespace std;
 
bool check(int size, int **a)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i][j] == 0)return true;
		}
	}
	return false;
}
 
int main()
{
	int **a, **tmp, size;
	cin >> size;
	a = new int*[size];
	tmp=new int*[size];
	for (int i = 0; i < size; i++)
	{
		a[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		tmp[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> a[i][j];
			tmp[i][j]=a[i][j];
		}
	}
 
	int count = 0;
	while (check(size, a))
	{
		count++;
		for (int i = 0;i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (a[i][j] == 1)
				{
					if (i > 0 && tmp[i - 1][j] == 0) tmp[i - 1][j] = 1;
					if (i < size - 1 && tmp[i + 1][j] == 0) tmp[i + 1][j] = 1;
					if (j > 0 && tmp[i][j - 1] == 0) tmp[i][j - 1] = 1;
					if (j < size - 1 && tmp[i][j + 1] == 0) tmp[i][j + 1] = 1;
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				a[i][j] = tmp[i][j];
			}
		}
	}
	cout << count;
	return 0;
}
