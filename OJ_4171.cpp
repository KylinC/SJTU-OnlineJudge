#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
 
int Partition(int a[], int low, int high)
{
    int x = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (a[j] < x)
        {
            int temp;
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    a[high] = a[i + 1];
    a[i + 1] = x;
    return i + 1;
}
void QuickSort(int a[],int low,int high)
{
    if (low < high)
    {
        int q = Partition(a, low, high);
        QuickSort(a, low, q - 1);
        QuickSort(a, q + 1, high);
    }
}
 
const int mmax=1000010;
int A[mmax],B[mmax];
struct Item
{
	int s,b;
	Item(int s=0,int b=0):s(s),b(b){}
	bool operator < (const Item &b) const
	{
		return s<b.s;
	}
};
 
template<class T>
class PriorityQueue
{
private:
    int Capacity = 100000;    
    int size;                 
    T* data;             
public:
    PriorityQueue()
    {	
        data = (T*) malloc((Capacity + 1)*sizeof(T));
        if (!data)
        {
            return;
        }
        size = 0;
	} 
    ~PriorityQueue()
    { 
        while (!empty())
            pop();
    }
    int Size()
    {
    	return size;
	}
    bool full()
	{
		if (size == Capacity)
            return true;
        return false;
	}  
    bool empty()
    {
    	if (size > 0)
            return false;
        return true;
	}
    void push(T key)
    {
    	if (empty())
        {
            data[++size] = key;
            return;
        }
        int i;
        if (full())
        {
            return;
        }
        for (i = ++size; key < data[i / 2]; i /= 2)
            data[i] = data[i / 2];
        data[i] = key;
	}
    void pop()
    {
    	int i, child;
        T min, last;
        if (empty())
        {
            return;
        }
 
        min = data[1];
        last = data[size--];
 
        for (i = 1; i * 2 <= size; i = child)
        {
            child = i * 2;
            if (child != size && data[child + 1] < data[child])
                child++;
 
            if (data[child] < last)
                data[i] = data[child];
            else
                break;
        }
        data[i] = last;
	}
    void clear()
    {
    	while (!empty())
            pop();
	}
    T top()
    {
    	if (empty())
        {
            return data[0];
        }
        return data[1];
	}
};
 
PriorityQueue<Item> q;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
 	cin>>n;
 	for(int i=0;i<n;i++)
 	{
 		cin>>A[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>B[i];
	}
	QuickSort(A,0,n-1);
	QuickSort(B,0,n-1);
	for(int i=0;i<n;i++)
	{
		q.push(Item(A[i]+B[0],0));
	}
	for(int i=0;i<n;i++)
	{
		Item item=q.top();
		q.pop();
		cout<<item.s;
		if(i!=n-1)
			cout<<" ";
		int b=item.b;
		if(b+1<n)
			q.push(Item(item.s-B[b]+B[b+1],b+1));
	}
	return 0;
}
