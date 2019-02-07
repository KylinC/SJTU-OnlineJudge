#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
 
template <class elemType>
class priorityQueue{
private:
    int currentSize;
    elemType * array;
    int maxSize;
 
    void doubleSpace();
    void buildHelp();
    void buildHelpRecursion(int hole);
    void percolateDown(int hole);
    void percolateUp(int leaf);
 
public:
    priorityQueue( int capacity = 100 )
    {
        array = new elemType[capacity];
        maxSize = capacity;
        currentSize = 0;
    }
    priorityQueue(const elemType data[], int size );
	~priorityQueue() { delete [] array; }
    bool isEmpty( ) const { return currentSize == 0; }
    void enQueue( const elemType & x );
    elemType deQueue();
    elemType getHead() {return array[1]; }
    void levelOrder() const;
};
 
template <class elemType>
void priorityQueue<elemType>::doubleSpace()
{
    elemType * tmp = new elemType [2 * maxSize];
    for (int i = 1; i <= currentSize; ++i) tmp[i] = array[i];
    delete array;
    array = tmp;
    maxSize = maxSize * 2;
}
 
template <class elemType>
void priorityQueue<elemType>::buildHelp()
{
    for (int i = currentSize / 2; i > 0; i--) percolateDown(i);
}
 
template <class elemType>
void priorityQueue<elemType>::buildHelpRecursion(int hole)
{
    if(hole * 2 <= currentSize) buildHelpRecursion(hole * 2);
    else return;
    if(hole * 2 + 1 <= currentSize) buildHelpRecursion(hole * 2 + 1);
    percolateDown(hole);
}
 
template <class elemType>
void priorityQueue<elemType>::percolateDown(int hole)
{
    if (hole * 2 > currentSize) return;
    int child;
    elemType tmp = array [hole];
    for (; hole * 2 <= currentSize; hole = child)
    {
        child = hole * 2;
        if (child != currentSize && array[child] > array [child + 1]) child ++;
        if (array[child] < tmp) array[hole] = array[child];
        else break;
    }
    array[hole] = tmp;
}
 
template <class elemType>
void priorityQueue<elemType>::percolateUp(int leaf)
{
    if (leaf <= 1) return;
    int parent;
    elemType tmp = array[leaf];
    for (; leaf > 1; leaf = parent)
    {
        parent = leaf/2;
        if (array[parent] > tmp) array[leaf] = array[parent];
        else break;
    }
    array[leaf] = tmp;
}
 
template <class elemType>
priorityQueue<elemType>::priorityQueue(const elemType data [], int size)
{
    maxSize = 2 * size; currentSize = size;
    array = new elemType [maxSize];
    for (int i = 1; i <= currentSize; ++i) array[i] = data[i-1];
    buildHelp();
    //buildHelpRecursion(1);
}
 
template <class elemType>
void priorityQueue<elemType>::enQueue(const elemType & x)
{
    if(currentSize == maxSize-1) doubleSpace();
    int hole = ++currentSize;
    for (; hole > 1 && x < array[hole/2] ; hole /= 2) array[hole] = array[hole/2];
    array[hole] = x;
}
 
template <class elemType>
elemType priorityQueue<elemType>::deQueue()
{
    elemType result = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
    return result;
}
 
template <class elemType>
void priorityQueue<elemType>::levelOrder()const
{
    for (int i = 0; i < currentSize; ++i) cout<<array[i+1]<<' ';
}
 
const int MAXN=10000;
const int MAXM=500000;
const int INF=1000000000;
struct Dijkstra
{
    int head[MAXN+5];
    struct node{int u,v,w,next;};
    node edge[MAXM+5];
    int n,m,s,cnt;
    int *dist,*pre,*ndist;
    void init(int n,int m,int s,int *dist,int *pre,int *ndist)
    {
        this->n=n;
        this->m=m;
        this->s=s;
        this->dist=dist;
        this->pre=pre;
        this->ndist=ndist;
    }
    void credge(int u,int v,int w)
    {
        edge[++cnt]=(node){u,v,w,head[u]};
        head[u]=cnt;
    }
    struct qbase{
        int key,value;
        bool operator < (const qbase &other) const
        {
            return value<other.value;
        }
        bool operator > (const qbase &other) const
        {
            return value>other.value;
        }
    };
    priorityQueue<qbase>q;
    bool vis[MAXN+5];
    void process()
    {
        for(int i=1;i<=n;i++) dist[i]=INF;
        dist[s]=0;
        q.enQueue((qbase){s,0});
        while(!q.isEmpty())
        {
            qbase h=q.deQueue();
            int hk=h.key,hv=h.value;
            int hd=ndist[hk];
            if(vis[hk]) continue;
            vis[hk]=true;
            for(int i=head[hk];i>0;i=edge[i].next)
            {
                int v=edge[i].v,w=edge[i].w;
                if(!vis[v]&&dist[v]>hv+w)
                {
                	pre[v]=hk;
                    dist[v]=hv+w;
                    ndist[v]=hd+1;
                    q.enQueue((qbase){v,dist[v]});
                }
                if(!vis[v]&&dist[v]==hv+w&&hd+1<ndist[v])
                {
                	pre[v]=hk;
                    dist[v]=hv+w;
                    ndist[v]=hd+1;
                    q.enQueue((qbase){v,dist[v]});
				}
            }
        }
    }
};
Dijkstra content;
int dist[MAXN+5],pre[MAXN+5],ndist[MAXN+5];
 
void print(int aim,int s)
{
	if(aim!=s)
	{
		print(pre[aim],s);
	}
	cout<<aim<<" ";
}
 
int main()
{
    int n,m,s,aim;
    cin>>n>>m>>s>>aim;
    memset(ndist,0,sizeof(ndist));
    content.init(n,m,s,dist,pre,ndist);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        content.credge(u,v,w);
    }
    content.process();
    cout<<((dist[aim]==INF)?2147483647:dist[aim])<<"\n";
    print(aim,s);
    return 0;
}
