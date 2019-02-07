#include<iostream>
using namespace std;
int con[200001];
int *max_con;
int head = 1, tail = 0;
 
int main()
{
	int n, k, i;
	cin>>k>>n;
	max_con=new int[n-k+2];
	for (i = 1; i <= n; ++i)cin>>con[i];
	for (i = 1; i <= k; ++i)
	{
		while (head <= tail && con[max_con[tail]]<con[i]) --tail;
		max_con[++tail] = i;
	}
	for (i = 1; i <= n-k+1; ++i)
	{
		cout<<con[max_con[head]]<<" ";
		if (i == max_con[head]) ++head;
		while (head <= tail && con[max_con[tail]]<con[i + k]) --tail;
		max_con[++tail]=i+k;
	}
	delete []max_con;
	return 0;
}
