#include <iostream>
using namespace std;
 
template<class elemType>
class vector
{
public:
	vector(int initSize=10)
	{
		maxSize=initSize;
		vector_size=0;
		elem=new elemType[maxSize];
	}
	~vector()
	{
		delete []elem;
	} 
	elemType &operator[] (int index)
	{
		return elem[index];
	}
	void push_back(elemType tmp)
	{
		if(vector_size==maxSize)
		{
			doubleSpace();
		}
		elem[vector_size]=tmp;
		vector_size++;
	}
	int size()
	{
		return vector_size;
	}
private:
	int maxSize;
	int vector_size;
	elemType *elem;
	void doubleSpace()
	{
		elemType* tmp=elem;
		maxSize*=2;
		elem=new elemType[maxSize];
		for(int i=0;i<vector_size;i++)
		{
			elem[i]=tmp[i];
		}
		delete tmp;
	}
}; 
 
template <class elemType>
class queue
{
public:
	virtual bool isEmpty() = 0;
	virtual void enQueue(const elemType &x) = 0;
	virtual elemType deQueue() = 0;
	virtual elemType getHead() = 0;
	virtual ~queue() {}
};
 
template <class elemType>
class seqQueue : public queue<elemType>
{
private:
	elemType *elem;
	int maxSize;
	int front, rear;
	void doubleSpace();
public:
	seqQueue(int size = 10)
	{
		elem = new elemType[size];
		maxSize = size;
		front = rear = 0;
	}
	~seqQueue()  {delete [] elem;}
	bool isEmpty() {return front==rear;}
	void enQueue(const elemType &x);
	elemType deQueue();
	elemType getHead()  {return elem[(front+1) % maxSize];}
};
 
template <class elemType>
void seqQueue<elemType>::doubleSpace()
{
	elemType *tmp = elem;
	elem = new elemType[2*maxSize];
 
	for(int i=1; i<maxSize; ++i)  elem[i] = tmp[(front+i) % maxSize];
 
	front = 0; rear = maxSize - 1;
	maxSize *= 2;
 
	delete tmp;
}
 
template <class elemType>
void seqQueue<elemType>::enQueue(const elemType &x)
{
	if((rear+1)%maxSize == front) doubleSpace();
	rear = (rear + 1) % maxSize;
	elem[rear] = x;
}  
 
template <class elemType>
elemType seqQueue<elemType>::deQueue()
{
	front = (front+1) % maxSize;
	return elem[front];
}
 
int main()
{
	int ferryTime = 0;            
	int amount;                      
	int carNum = 0, truckNum = 0;     
	int carCount = 0, count = 0;        
	double carTotalTime = 0, truckTotalTime=0;
	int temp1, temp2, topElem; 
	seqQueue<int> car_con, truck_con;  
	vector<int> carWaitTime, truckWaitTime;     
	
	cin >> amount;               
	for(int i=0; i<amount; ++i)
	{
		cin>>temp1;
		if(temp1 == 0) {carNum++; cin>>temp2; car_con.enQueue(temp2);}
		else {truckNum++; cin>>temp2; truck_con.enQueue(temp2);}
	}
 
	int i, j;
	while(!car_con.isEmpty() || !truck_con.isEmpty())
	{
		for(i=0; i<2; ++i)
		{  
			for(j=0; j<4; ++j)
			{   
				if(car_con.isEmpty())  break;
				 
				topElem = car_con.getHead();
				if(topElem<=ferryTime && count<10)
				{
					car_con.deQueue();
					carCount++; count++;
					carWaitTime.push_back(ferryTime-topElem);
				}
 
			}
 	
			if(carCount < 4) {
				while(true){
					if(truck_con.isEmpty()) break;
					 
					topElem = truck_con.getHead();
					if(topElem<=ferryTime && count<10)
					{
						truck_con.deQueue();
						count++;
						truckWaitTime.push_back(ferryTime-topElem);
					}
					else {i = 2; j = 4; break;}
				}
			}
			else{
				if(truck_con.isEmpty())  break;
				 
				topElem = truck_con.getHead();
			    if(topElem<=ferryTime && count<10)
			    {
					truck_con.deQueue();
					count++;
					truckWaitTime.push_back(ferryTime-topElem);
				}
				carCount = 0; 
			}
		}
		ferryTime += 10;
		count=0; carCount = 0; 
	}
 
	for(i=0; i<carWaitTime.size(); ++i)     carTotalTime += carWaitTime[i];
	for(j=0; j<truckWaitTime.size(); ++j)   truckTotalTime += truckWaitTime[j];
 
	double carAveTime, truckAveTime;
	if(carTotalTime == 0)  carAveTime = 0;
	else carAveTime = carTotalTime / carNum;
	if(truckTotalTime ==0) truckAveTime = 0;
	else truckAveTime = truckTotalTime / truckNum;
 
	cout<<fixed;
	cout.precision(3);
	cout<<carAveTime<<' '<<truckAveTime<<endl;
 
 
    return 0;
 
}
