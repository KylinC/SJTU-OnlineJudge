#include <iostream>
 
using namespace std;
 
template<class elemType>
class queue
{
public:
	queue(int size = 10)
	{
		elem = new elemType[size];
		maxSize = size;
		front = rear = 0;
	}
	~queue()
	{
		delete[]elem;
	}
	bool empty()
	{
		return front == rear;
	}
	void push(const elemType &x)
	{
		if ((rear + 1) % maxSize == front)doubleSpace();
		rear = (rear + 1) % maxSize;
		elem[rear] = x;
	}
	elemType pop()
	{
		front = (front + 1) % maxSize;
		return elem[front];
	}
	int size()
	{
		return rear - front;
	}
private:
	elemType* elem;
	int maxSize;
	int front, rear;
	void doubleSpace()
	{
		elemType *tmp = elem;
		elem = new elemType[2 * maxSize];
		for (int i = 1; i <= maxSize; ++i)
		{
			elem[i] = tmp[(front + i) % maxSize];
		}
		front = 0; rear = maxSize;
		maxSize *= 2;
		delete tmp;
	}
};
 
struct Node {
	int x, y;
	Node(int a = 0, int b = 0) :x(a), y(b) {}
};
Node node[1001];
 
int G[1001][1001];
 
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int d[1001][1001];
 
bool Valid(int x, int y, int row, int column)
{
	if (x < 1 || x > row || y < 1 || y > column) return false;
	if (d[x][y] != -1 || G[x][y] == 1) return false;
	return true;
}
 
void Clear_D(int row, int column, int x, int y) {
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= column; j++)
			d[i][j] = -1;
	d[x][y] = 0;
	return;
}
 
void bfs(int row, int column, int x, int y) {
	queue<Node> Q;
	Q.push(Node(x, y));
	Clear_D(row, column, x, y);
	while (!Q.empty()) {
		Node k = Q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = k.x + dir[i][0];
			int next_y = k.y + dir[i][1];
			if (Valid(next_x, next_y, row, column)) {
				d[next_x][next_y] = d[k.x][k.y] + 1;
				Q.push(Node(next_x, next_y));
			}
		}
	}
 
}
 
int main()
{
	int column, row;
	int x1, y1, x2, y2;
	queue<Node> first;
	cin >> column >> row;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= column; j++)
		{
			cin >> G[i][j];
			if (G[i][j] == 2)
			{
				x1 = i; y1 = j;
			}
			if (G[i][j] == 3)
			{
				x2 = i; y2 = j;
			}
			if (G[i][j] == 4)
			{
				first.push(Node(i, j));
			}
		}
	}
	int size = first.size();
	int *result = new int[size];
	bfs(row, column, x1, y1);
	Node tmp;
 
	for (int i = 0; i < size; i++)
	{
		tmp = first.pop();
		result[i] = d[tmp.x][tmp.y];
		first.push(tmp);
 
	}
 
	bfs(row, column, x2, y2);
	for (int i = 0; i < size; i++)
	{
		tmp = first.pop();
		result[i] += d[tmp.x][tmp.y];
		first.push(tmp);
	}
	int mini;
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (result[j] >= result[j + 1])
			{
				mini = result[j + 1];
				result[j + 1] = result[j];
				result[j] = mini;
			}
		}
	}
 
	for (int i = 0; i < size; i++)
	{
		if (result[i] > 0)
		{
			mini = result[i];
			break;
		}
	}
	cout << mini;
	return 0;
}
