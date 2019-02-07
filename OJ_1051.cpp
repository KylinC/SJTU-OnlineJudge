#include <iostream>
using namespace std;
 
class autoLink
{
	struct Node
	{
		Node(int tmp) :val(tmp), next(NULL) {}
		int val;
		Node* next;
	};
	long int num;
	Node *head, *rear, *ptr;
public:
	autoLink() :num(0)
	{
		head = new Node(0);
		rear = head;
	}
	long int get_num()
	{
		return num;
	}
	void build(int tmp)
	{
		rear->next = new Node(tmp);
		rear = rear->next;
	}
	void search(int tmp)
	{
		for (ptr = head->next; ptr != NULL && ptr->val != tmp; ptr = ptr->next, ++num);
		if (ptr != NULL)
		{
			++num;
			if (ptr->next != NULL) {
				ptr->val = ptr->next->val;
				rear = ptr->next;
				ptr->next = rear->next;
				delete rear;
			}
			else {
				for (rear = head; rear->next != ptr; rear = rear->next);
				delete ptr;
				rear->next = NULL;
			}
			rear = head->next;
			head->next = new Node(tmp);
			head->next->next = rear;
		}
	}
};
 
int main()
{
	int n, m, tmp;
	autoLink con;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		con.build(tmp);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		con.search(tmp);
	}
	cout << con.get_num();
}
