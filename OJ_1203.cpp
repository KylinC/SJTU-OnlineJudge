#include<iostream>
using namespace std;
 
//base class
 
template<class elemType>
class list
{
public:
	virtual void clear()=0;
	virtual int length() const=0;
	virtual void insert(int i,const elemType& x)=0;
	virtual void remove(int i)=0;
	virtual int search(const elemType& x)const=0;
	virtual elemType visit(int i)const=0;
	virtual void traverse()const=0;
	virtual ~list(){};
};
 
//derived class
 
template<class elemType>
class seqList:public list<elemType>
{
private:
	elemType* data;
	int currentLength;
	int maxSize;
	void doubleSpace();
public:
	seqList(int initSize=10);
	~seqList();
	void clear();
	int length() const;
	void insert(int i,const elemType &x);
	void remove(int i);
	int search(const elemType &x)const;
	elemType visit(int i)const;
	void traverse()const;
	seqList<elemType> operator+(const seqList<elemType> &other);
	seqList(const seqList<elemType> &other);
	seqList<elemType> operator=(const seqList<elemType> &other);
};
 
//derived class implementation
 
template<class elemType>
seqList<elemType> seqList<elemType>::operator+(const seqList<elemType> &other)
{
	int i=0;
	seqList<elemType> tmp(other.currentLength+currentLength);
	for(;i<currentLength;i++)
	{
		tmp.data[i]=data[i];
	}
	for(int j=0;j<other.currentLength;j++)
	{
		tmp.data[i++]=other.data[j];
	}
	tmp.currentLength=i;
	return tmp;
}
 
template<class elemType>
seqList<elemType>::seqList(const seqList<elemType> &other)
{
	currentLength=other.currentLength;
	maxSize=other.maxSize;
	data=new elemType[maxSize];
	for(int i=0;i<currentLength;i++)
	{
		data[i]=other.data[i];
	}
}
 
template<class elemType>
seqList<elemType> seqList<elemType>::operator=(const seqList<elemType> &other)
{
	if(this==&other) return *this;
	delete []data;
	currentLength=other.currentLength;
	maxSize=other.maxSize;
	data=new elemType[maxSize];
	for(int i=0;i<currentLength;i++)
	{
		data[i]=other.data[i];
	}
	return *this;
}
 
template<class elemType>
seqList<elemType>::~seqList()
{
	delete []data;
}
 
template<class elemType>
void seqList<elemType>::clear()
{
	currentLength=0;
}
 
template<class elemType>
int seqList<elemType>::length() const
{
	return currentLength;
}
 
template<class elemType>
elemType seqList<elemType>::visit(int i)const
{
	return data[i];
}
 
template<class elemType>
void seqList<elemType>::traverse() const
{
	for(int i=0;i<currentLength;++i)
	{
		cout<<data[i]<<' ';
	}
}
 
template<class elemType>
seqList<elemType>::seqList(int initSize)
{
	data=new elemType[initSize];
	maxSize=initSize;
	currentLength=0;
}
 
template<class elemType>
int seqList<elemType>::search(const elemType &x) const
{
	int i=0;
	for(;i<currentLength && data[i]!=x;++i);
    if(i==currentLength)return -1;
    else return i;
}
 
template<class elemType>
void seqList<elemType>::doubleSpace()
{
	elemType *tmp=data;
	maxSize*=2;
	data=new elemType[maxSize];
	for(int i=0;i<currentLength;i++)
	{
		data[i]=tmp[i];
	}
	delete []tmp;
}
 
template<class elemType>
void seqList<elemType>::insert(int i,const elemType &x)
{
	if(currentLength==maxSize)
	{
		doubleSpace();
	}
	for(int j=currentLength;j>i;j--)
	{
		data[j]=data[j-1];
	}
	data[i]=x;
	++currentLength;
}
 
template<class elemType>
void seqList<elemType>::remove(int i)
{
	for(int j=i;j<currentLength-1;j++)
	{
		data[j]=data[j+1];
	}
	--currentLength;
}
 
//examination
 
int main()
{
	char s[6];
	cin>>s;
	seqList<int> a1,c1,result1;
	int b1;
	seqList<double> a2,c2,result2;
	double b2;
	seqList<char> a3,c3,result3;
	char b3;
	int first,second;
	cin>>first>>second;
	if (s[0]=='i')
	{
		for(int i=0;i<first;i++)
	    {
		    cin>>b1;
		    a1.insert(i,b1);
	    }
	    for(int i=0;i<second;i++)
	    {
		    cin>>b1;
		    c1.insert(i,b1);
	    }
	    result1=a1+c1;
	    result1.traverse();
	}
	else if(s[0]=='d')
	{
		for(int i=0;i<first;i++)
	    {
		    cin>>b2;
		    a2.insert(i,b2);
	    }
	    for(int i=0;i<second;i++)
	    {
		    cin>>b2;
		    c2.insert(i,b2);
	    }
	    result2=a2+c2;
	    result2.traverse();
	}
    else
	{
		for(int i=0;i<first;i++)
	    {
		    cin>>b3;
		    a3.insert(i,b3);
	    }
	    for(int i=0;i<second;i++)
	    {
		    cin>>b3;
		    c3.insert(i,b3);
	    }
	    result3=a3+c3;
	    result3.traverse();
	}
	
	return 0;
}
