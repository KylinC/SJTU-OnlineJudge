#include<iostream>
#include<cstring>
using namespace std;
 
class Text
{
private:
	struct node
	{
		char data[2010];
		node *next, *prev;
		node() {}
		~node() {}
	};
	node *head, *tail;
	int L;
public:
	Text();
	~Text() {}
	Text::node* add();
	friend istream &operator>>(istream& in, Text& obj);
	void list(int num1, int num2);
	void ins(int num1, int num2, char *tmp);
	void del(int num1, int num2, int num3);
	void quit();
};
 
Text::Text()
{
	L = 0;
	head = new node();
	tail = new node();
	head->next = tail;
	tail->prev = head;
}
 
Text::node* Text::add()
{
	node *tmp;
	tmp = new node();
	tmp->prev = tail->prev;
	tmp->next = tail;
	tail->prev->next = tmp;
	tail->prev = tmp;
	return tmp;
}
 
void Text::list(int num1, int num2)
{
	if(num1 <=0|| num2 <=0|| num1> L|| num2> L|| num1 > num2)
	{
		cout << "Error!" << endl;
	}
	else
	{
		node *tmp; tmp = head->next;
		for (int i = 0; i < L; i++)
		{
			if (i > num1 - 2 && i < num2) { cout << tmp->data << endl; }
			if (i == num2 - 1) { break; }
			tmp = tmp->next;
		}
	}
}
 
void Text::ins(int num1, int num2, char *tmp)
{
	node *Textmp; Textmp = head;
	if (num1 >= 1 && num1 <= L) 
	{
		for (int i = 0; i < num1; i++)Textmp = Textmp->next;
	}
	if (num1<1 || num2<1 || num1>L || num2>(strlen(Textmp->data) + 1))
	{
		cout << "Error!" << endl;
	}
	else
	{
		int R = strlen(Textmp->data);
		for (int
			i = (strlen(Textmp->data) - 1); i >= (num2 - 1); i--) {
			Textmp->data[i + strlen(tmp)] = Textmp->data[i];
		}
		Textmp->data[R + strlen(tmp)] = '\0';
		for (int i = 0; i < strlen(tmp); i++) 
		{
			Textmp->data[i + num2 - 1] = tmp[i];
		}
	}
}
 
istream &operator>>(istream& in, Text& obj)
{
	Text::node* tmp = obj.head;
	for (int i = 0; i < 100; ++i)
	{
		tmp = obj.add();
		in.getline(tmp->data, 2000); obj.L++;
		if (strcmp(tmp->data, "******") == 0) { obj.L--; break; }
	}
	return in;
}
 
void Text::del(int num1, int num2, int num3)
{
	node *Textmp; Textmp = head; int R = 0;
	if (num1 >= 1 && num1 <= L) 
	{
		for (int i = 0; i < num1; i++) 
		{
			Textmp = Textmp->next;
		}
		R = strlen(Textmp->data);
	}
	if (num1<1 || num2<1 || num1>L || num2>R || (num2 + num3) > (R + 1))
	{
		cout << "Error!" << endl;
	}
	else
	{
		for (int i = 0; i < (R - num3 - num2 + 1); i++) 
		{
			Textmp->data[i + num2 - 1] = Textmp->data[i + num3 + num2 - 1];
		}
		Textmp->data[R - num3] = '\0';
	}
}
 
void Text::quit()
{
	node *Textmp; Textmp = head;
	for (int i = 0; i < L; i++) 
	{
		Textmp = Textmp->next; 
		cout << Textmp->data << endl;
	}
}
 
int main()
{
	Text text; 
	cin >> text;
	char order[5];
	char tmp[100];
	int m1, m2, m3;
	while (true)
	{
 
		cin >> order;
		if (strcmp(order, "list") == 0)
		{
			cin >> m1 >> m2;
			text.list(m1, m2);
		}
		else
			if (strcmp(order, "ins") == 0)
			{
				cin >> m1 >> m2;
				cin.get();
				cin.getline(tmp, 100);
				text.ins(m1, m2, tmp);
			}
			else
				if (strcmp(order, "del") == 0)
				{
					cin >> m1 >> m2 >> m3;
					text.del(m1, m2, m3);
				}
				else
					if (strcmp(order, "quit") == 0)
					{
						break;
					}
	}
	text.quit();
	return 0;
}
