#include<iostream>
using namespace std;
 
class Stack
{
public:
	Stack(int initSize=1000000)
	{
		maxSize=initSize;
		elem=new char[maxSize];
		top_p=-1;
	}
	~Stack()
	{
		delete []elem;
	}
	bool isEmpty() 
	{
		return top_p==-1;
	}
	int get_top_p()
	{
		return top_p;
	}
	void push(char tmp)
	{
		top_p++;
		elem[top_p]=tmp;
	}
	char top()
	{
		return elem[top_p];
	}
	void pop()
	{
		top_p--;
	}
	void clear()
	{
		top_p=-1;
	}
	void set_top_p(int tmp)
	{
		top_p=tmp;
	}
private:
	char* elem;
	int top_p;
	int maxSize;
};
 
bool match(char c1,char c2)
{
	if(c1=='('&&c2==')')return true;
	if(c1=='['&&c2==']')return true;
	if(c1=='{'&&c2=='}')return true;
	return false;
}
 
int main()
{
	int loop,order;
	char bracket;
	int check=-1;
	Stack container,temp;
    scanf("%d",&loop);
	while(loop--)
	{
		scanf("%d",&order);
		switch(order)
		{
			case 1:
				{
					scanf("%c",&bracket);
					scanf("%c",&bracket);
					container.push(bracket);
					if(check!=-1)
					{
						continue;
					}
					if (bracket ==')' || bracket ==']' ||bracket =='}') 
					{
                        if((temp.get_top_p()==-1) || (bracket==')' && temp.top()!='(') || (bracket==']' && temp.top()!='[') || (bracket=='}' && temp.top()!='{')) 
						{
                            check=container.get_top_p();
                        } 
						else 
						{ 
                            temp.pop();
                        }
                    } 
					else  
					{ 
                        temp.push(bracket);
                    } 
					
					break;
				}
			case 2:
				{
					if(!container.isEmpty())
					{
						if(check!=-1)
						{
							container.pop();
							if(check>container.get_top_p())
							{
								check=-1;
							}
						}
						else
						{
							if(container.top()=='(' || container.top()=='[' ||container.top()=='{') 
							{
                                temp.pop();
                            } 
							else if(container.top()==')') 
							{
                                temp.push('(');
                            } 
							else if(container.top()==']') 
							{
                                temp.push('[');
                            } 
							else if(container.top()=='}')  
							{
                                temp.push('{');
                            }
                            container.pop();
						}
					}
					
					break;
				}
			case 3:
				{
					if(!container.isEmpty())
					{
						printf("%c",container.top());
						if(loop!=0)
					    {
						    printf("\n");
					    }
					}
					break;
				}
			case 4:
				{
					if(check==-1&&temp.isEmpty())
					{
						printf("YES");
					}
					else
					{
						printf("NO");
					}
					if(loop!=0) 
					{
                        printf("\n");
                    }
                    
                    break;
				}
		}
	}
}
