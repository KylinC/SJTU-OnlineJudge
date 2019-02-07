#include<iostream>
using namespace std;
int n, m, start, aim;
 
struct node
{
	int num, weight;
	node* next;
	node(int n = 0, node* to = NULL, int w = 0) :num(n), next(to), weight(w) {}
};
node* head;
int dist[10010];
 
int tail = -1, front = 0;
int que[10010];
void enque(int x)
{
	que[++tail] = x;
}
int deque() { return que[front++]; }
bool empty() { return (front > tail); }
 
int main()
{
	cin >> n >> m >> start >> aim;
	head = new node[n + 10];
	int from, to, weight;
	node *tmp;
	for (int i = 1; i <= m; i++)
	{
		cin >> from >> to >> weight;
		tmp = new node(to, head[from].next, weight);
		head[from].next = tmp;
	}
	for (int i = 1; i <= n; i++)
	{
		dist[i] = 100000000;
	}
	dist[start] = 0;
	enque(start);
	while (!empty())
	{
		int source = deque();
		for (tmp = head[source].next; tmp; tmp = tmp->next)
		{
			int to1 = tmp->num, val = tmp->weight;
			if (dist[to1] > dist[source] + val)
			{
				dist[to1] = dist[source] + val;
				enque(to1);
			}
		}
	}
	cout << dist[aim];
 
	return 0;
}
