#include<iostream>
#include<vector>
#include<string.h>
#include<sstream>
using namespace std;
 
class Pile
{
public:
	Pile(int num);
	int search(int num);
	void set(int location);
	void print();
	int size();
	int getnum(int num);
	void pop_back()
	{
		pile.pop_back();
	}
	void push_back(int num)
	{
		pile.push_back(num);
	}
	int getlast()
	{
		int i=pile.size()-1;
		return pile[i];
	}
private:
	vector<int> pile;
};
 
class Block
{
public:
	struct str_con
	{
		int origin;
		int aim;
		string former;
		string latter;
	};
	Block(int num);
	void launch();
private:
	void move_onto(int a,int b);
	void move_over(int a,int b);
	void pile_onto(int a,int b);
	void pile_over(int a,int b);
	void print();
	int stair;
	vector<Pile*> block;
	void get_order(str_con con);
	bool check(int a,int b);
    void search(int &x,int &y,int aim);
};
 
void Block::get_order(str_con con)
{
	if(check(con.origin,con.aim))return;
	if(con.former=="move"&&con.latter=="onto")move_onto(con.origin,con.aim);
	if(con.former=="move"&&con.latter=="over")move_over(con.origin,con.aim);
	if(con.former=="pile"&&con.latter=="onto")pile_onto(con.origin,con.aim);
	if(con.former=="pile"&&con.latter=="over")pile_over(con.origin,con.aim);
}
 
void Block::launch()
{
	stringstream ss;
	str_con con;
	char tmp[80];
	con.former=" ";
	while(1)
	{
		cin.getline(tmp,80);
		ss<<tmp;
		ss>>con.former;
		if(con.former=="quit")break;
		ss>>con.origin;
		ss>>con.latter;
		ss>>con.aim;
		get_order(con);
		ss.clear();
		
	}
	print();
}
 
bool Block::check(int a,int b)
{
	int x1,y1,x2,y2;
	search(x1,y1,a);
	search(x2,y2,b);
	if (x1==x2||a==b) return true;
	else return false;
}
 
Pile::Pile(int num)
{
    pile.push_back(num);
}
 
int Pile::size()
{
	return pile.size();
}
 
int Pile::getnum(int num)
{
	return pile[num];
}
 
int Pile::search(int num)
{
	for(int i=0;i<pile.size();i++)
	{
		if(num==pile[i])
		{
			return i;
		}
	}
}
 
void Pile::set(int location)
{
	pile.push_back(location);
} 
 
void Pile::print()
{
	for(int i=0;i<pile.size();i++)
	{
		cout<<pile[i]<<" ";
	}
	cout<<endl;
}
 
Block::Block(int num)
        :stair(num)
{
    for(int i=0;i<stair;i++)
    {
    	block.push_back(new Pile(i));
	}
}
 
void Block::print()
{
	for(int i=0;i<block.size();i++)
	{
		cout<<i<<": ";
		for(int j=0;j<block[i]->size();j++)
		{
			cout<<block[i]->getnum(j)<<" ";
		}
		cout<<endl;
	}
}
 
void Block::search(int &x,int &y,int aim)
{
	for(int i=0;i<block.size();i++)
	{
		for(int j=0;j<block[i]->size();j++)
		{
			if(block[i]->getnum(j)==aim)
			{
				x=i;
				y=j;
			}
		}
	}
}
 
void Block::move_onto(int a,int b)
{
	int x,y,tmp;
	search(x,y,a);
	while(block[x]->size()>y)
	{
		tmp=block[x]->getlast();
		block[x]->pop_back();
		if(tmp==a)break;
		block[tmp]->set(tmp);
	}
	
	search(x,y,b);
	while(block[x]->size()-1>y)
	{
		tmp=block[x]->getlast();
		block[x]->pop_back();
		block[tmp]->set(tmp);
	}
	block[x]->push_back(a);
}
 
void Block::move_over(int a,int b)
{
	int x,y,tmp;
	search(x,y,a);
	while(block[x]->size()>y)
	{
		tmp=block[x]->getlast();
		block[x]->pop_back();
		if(tmp==a)break;
		block[tmp]->set(tmp);
	}
	
	search(x,y,b);
	block[x]->push_back(a);
}
 
void Block::pile_onto(int a,int b)
{
	Pile temp(1);
	int x,y,tmp;
	search(x,y,a);
	while(block[x]->size()>y)
	{
		tmp=block[x]->getlast();
		block[x]->pop_back();
		temp.push_back(tmp);
	}
	
	search(x,y,b);
	while(block[x]->size()-1>y)
	{
		tmp=block[x]->getlast();
		block[x]->pop_back();
		block[tmp]->set(tmp);
	}
	for(int i=temp.size()-1;i>0;i--)
	{
		block[x]->push_back(temp.getnum(i));
	}
}
 
void Block::pile_over(int a,int b)
{
	Pile temp(1);
	int x,y,tmp;
	search(x,y,a);
	while(block[x]->size()>y)
	{
		tmp=block[x]->getlast();
		block[x]->pop_back();
		temp.push_back(tmp);
	}
	
	search(x,y,b);
	for(int i=temp.size()-1;i>0;i--)
	{
		block[x]->push_back(temp.getnum(i));
	}
}
 
int main()
{
	int stair;
	cin>>stair;
	Block one(stair);
	one.launch();
	return 0;
}
