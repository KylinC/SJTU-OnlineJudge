#include<iostream>
using namespace std;
 
class charRadix
{
public:
    charRadix();
	charRadix(char* tmp);
	friend ostream& operator <<(ostream& outputStream,charRadix& tmp);
	friend istream& operator >>(istream& inputStream,charRadix& tmp);
	const charRadix operator +(const charRadix& tmp) const;
    char container[101];	
};
 
charRadix::charRadix()
{
}
 
charRadix::charRadix(char* tmp)
{
	int i=0;
	while(tmp[i]!='\0')
	{
		container[i]=tmp[i];
		i++;
	}
	container[i]='\0';
}
 
const charRadix charRadix::operator +(const charRadix& tmp) const
{
	int num[101]={0};
	char result[101];
	int i=0,res=0,num1,num2;
	bool flag1=true,flag2=true;
	while(flag1||flag2||res!=0)
	{
		if(container[i]!='\0'&&flag1)
		{
			num1=int(container[i]);
		}
		else flag1=false;
		if(tmp.container[i]!='\0'&&flag2)
		{
			num2=int(tmp.container[i]);
		}
		else flag2=false;
		if(!flag1) num1=97;
		if(!flag2) num2=97;
		num[i]=(num1+num2-194+res)%26;
		res=(num1-194+num2+res)/26;
		i++;
	}
	for(int j=0;j<i;j++)
	{
		result[j]=char(97+num[j]);
	}
	result[i]='\0';
	for(int j=i-1;result[j]=='a';j--)
	{
		result[j]='\0';
	}
	return charRadix(result);
}
 
istream& operator >>(istream& inputStream,charRadix& tmp)
{
	char str[101];
	inputStream>>str;
	int i=-1;
	while(str[i+1]!='\0')
	{
		i++;
	}
	for(int j=0;j<=i;j++)
	{
		tmp.container[j]=str[i-j];
	}
	tmp.container[i+1]='\0';
	return inputStream;
}
 
ostream& operator <<(ostream& outputStream,charRadix& tmp)
{
	int i=-1;
	while(tmp.container[i+1]!='\0')
	{
		i++;
	}
	for(int j=i;j>=0;j--)
	{
		outputStream<<tmp.container[j];
	}
	return outputStream;
}
 
int main()
{
	charRadix a,b,c;
	cin>>a>>b;
	c=a+b;
	cout<<c;
}
