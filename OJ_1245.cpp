#include <iostream>
#include<cmath>
using namespace std; 
 
template <class elemType>
class stack{
public:
    virtual elemType pop() = 0;
    virtual bool isEmpty() const = 0;
    virtual void push(const elemType & obj) = 0;
    virtual elemType top() const = 0;
    virtual ~stack() {}
};
 
template <class elemType>
class seqStack : public stack<elemType>{
private:
    int top_index;
    int maxSize;
    elemType * elem;
    void doubleSpace();
public:
    seqStack(int initialSize=1005);
    bool isEmpty() const;
    elemType pop();
    int get_top(){return top_index;}
    void push(const elemType & obj);
    elemType top() const;
    ~seqStack() {delete [] elem;}
};
 
template <class elemType>
seqStack<elemType>::seqStack(int initialSize)
{
    elem = new elemType [initialSize];
    maxSize = initialSize;
    top_index = -1;
}
 
template <class elemType>
bool seqStack<elemType>::isEmpty() const
{
    return top_index == -1;
}
 
template <class elemType>
elemType seqStack<elemType>::pop()
{
    return elem[top_index--];
}
 
template <class elemType>
void seqStack<elemType>::push(const elemType & obj)
{
    if (top_index == maxSize - 1) doubleSpace();
    elem[++top_index] = obj;
}
 
template <class elemType>
elemType seqStack<elemType>::top()const
{
    return elem[top_index];
}
 
template <class elemType>
void seqStack<elemType>::doubleSpace()
{
    elemType * ch = new elemType (maxSize*2);
    for (int i = 0; i<=top_index; ++i) ch[i]=elem[i];
    maxSize *= 2;
    delete [] elem;
    elem = ch;
}
 
 
int main()
{
	int table[50];
	table['+']=1;
	table['-']=1;
	table['*']=2;
	table['/']=2;
	table[')']=0;
	std::string con="",prefix="",ch,regular="";
	seqStack<char> bar,pre;
	seqStack<int> num;
	getline(cin,ch);
	for(int i=0;i<ch.length();i++)
	{
	    if(ch[i]==' ')con+=' ';
	    else if(ch[i]=='(')con+="( ";
	    else if(ch[i]==')')con+=" )";
	    else con+=ch[i];
	}
	//cout<<con<<endl;
	for(int i=con.length()-1;i>=0;i--)
	{
		if(con[i]==' ')
		{
			continue;
		}
		if(con[i]>='0'&&con[i]<='9')
		{
			if(i>=1)
			{
				if(con[i-1]<='9'&&con[i-1]>='0')pre.push(con[i]);
				else 
				{
					pre.push(con[i]);
					pre.push(' ');
				}
			}
			else
			{
				pre.push(con[i]);
				pre.push(' ');
			}
		}
		else
		{
			if(con[i]==')')
			{
			    bar.push(con[i]);
			}
			else
			{
				if(con[i]=='(')
				{
					while(bar.top()!=')')
					{
						pre.push(bar.pop());
						pre.push(' ');
					}
					bar.pop();
				}
				else
				{
					while(!bar.isEmpty()&&table[bar.top()]>table[con[i]])
					{
						pre.push(bar.pop());
						pre.push(' ');
					}
					bar.push(con[i]);
				}
			}
		}
	}
	while(!bar.isEmpty())
	{
		pre.push(bar.pop());
		pre.push(' ');
	}
	pre.pop();
	while(!pre.isEmpty())prefix+=pre.pop();
	cout<<prefix<<endl;
	
	int tmp1,tmp2,num1,num2;
	char some_ch;
	for (int j = prefix.length() - 1;j >= 0;--j)
	{
		some_ch = prefix[j];
		if (some_ch <= '9' && some_ch >= '0')
		{
			tmp1 = 0;
			tmp2 = 0;
			while (some_ch <= '9' && some_ch >= '0')
			{
				tmp1 += int(pow(10,tmp2++)) * (some_ch - '0');
				--j;
				some_ch = prefix[j];
			}
			num.push(tmp1);
		}
 
		if(some_ch == '+' || some_ch == '-' || some_ch == '*' || some_ch == '/')
		{
			num2 = num.pop();
			num1 = num.pop();
			switch (some_ch)
			{
			case '+':
			    num.push(num2 + num1);
				break;
			case '-':
			    num.push(num2 - num1);
				break;
			case '*':
			    num.push(num2 * num1);
				break;
			case '/':
			    num.push(num2 / num1);
				break;
			case ' ':
			    break;
			}
 
		}
 
	}
	cout << num.top() << endl;
}
