#include<iostream>
#include<iomanip> 
using namespace std;
 
void swap(int a[],int i,int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j]  =tmp;
}
 
int partition(int a[],int start,int end)
{
	int i = start;
	int j = end + 1;
	int x = a[start];
	while (1)
	{
		while (a[++i]<x);
		while (a[--j]>x);
		if (i>=j)
			break;
		swap(a,i,j);
	}
	a[start] = a[j];
	a[j] = x;
	return j;
 
}
 
void quickSort(int lst[], int head, int tail) 
{
    if (head >= tail) return ;
    int i = head, j = tail;
    int pivot = lst[head];  
    while (i < j) 
	{ 
        while (i < j and lst[j] >= pivot) j--;
        lst[i] = lst[j];   
        while (i < j and lst[i] <= pivot) i++;
        lst[j] = lst[i];   
    }
    lst[i] = pivot; 
    quickSort(lst, head, i - 1);  
    quickSort(lst, j + 1, tail);
}
 
template<class elemType>
class queue
{
public:
	queue(int size=10)
	{
		elem = new elemType[size];
		maxSize = size;
		head = rear = 0;
	}
	~queue()
	{
		delete[]elem;
	}
	bool empty()
	{
		return head == rear;
	}
	void push(const elemType &x)
	{
		if ((rear + 1) % maxSize == head)doubleSpace();
		rear = (rear + 1) % maxSize;
		elem[rear] = x;
	}
	elemType pop()
	{
		head = (head + 1) % maxSize;
		return elem[head];
	}
	elemType top()
	{
		return elem[(head+1)%maxSize];
	}
	int size()
	{
		return rear - head;
	}
private:
	elemType* elem;
	int maxSize;
	int head, rear;
	void doubleSpace()
	{
		elemType *tmp = elem;
		elem = new elemType[2 * maxSize];
		for (int i = 1; i < maxSize; ++i)
		{
			elem[i] = tmp[(head + i) % maxSize];
		}
		head = 0; rear = maxSize-1;
		maxSize *= 2;
		delete tmp;
	}
};
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int *music,mu_num,num,tmp1,tmp2,man_num=0,woman_num=0,sum_tmp;
	int *k1,*k2;
	int ch1=0,ch2=0;
	queue<int> man,woman;
	cin>>mu_num;
	music=new int[mu_num+1];
	music[0]=0;
	for(int i=1;i<=mu_num;i++)
	{
		cin>>sum_tmp;
		music[i]=music[i-1]+sum_tmp;
	}
	cin>>num;
	k1=new int[num+1];k2=new int[num+1];
	while(num--)
	{
		cin>>tmp1>>tmp2;
		if(tmp1==1)
		{
			k1[ch1]=tmp2;
			man_num++;
			ch1++;
		}
		if(tmp1==2)
		{
			k2[ch2]=tmp2;
			woman_num++;
			ch2++;
		}
	}
	quickSort(k1,0,ch1-1);
	quickSort(k2,0,ch2-1);
	
	for(int i=0;i<ch1;i++)
	{
		man.push(k1[i]);
	}
	for(int i=0;i<ch2;i++)
	{
		woman.push(k2[i]);
	}
	
	int check=0;
	double man_sum=0,woman_sum=0;
	while(check<mu_num&&(!man.empty()||!woman.empty()))
	{
		while(!man.empty()&&!woman.empty()&&man.top()<=music[check]&&woman.top()<=music[check])
		{
			man_sum+=music[check]-man.pop();
			woman_sum+=music[check]-woman.pop();
		}
		check++;
	}
	
	if(!man.empty()||!woman.empty())
	{
		while(!man.empty())
		{
			man_sum+=music[mu_num-1]-man.pop();
		}
		while(!woman.empty())
		{
			woman_sum+=music[mu_num-1]-woman.pop();
		}
	}
	
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<man_sum/man_num<<" "<<woman_sum/woman_num;
	
	return 0;
}
