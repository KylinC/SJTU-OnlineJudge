#include<iostream>
#include<cstring>
#include<deque>
using namespace std;
 
const int inf=20000000;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
 
 
struct node
{
	int num,weight;
	node* next;
	node(int t_num=0,int t_weight=0,node* t_next=NULL)
	    :num(t_num),weight(t_weight),next(t_next)
	{}
};
node *head;
int n,m,check;
 
struct point
{
	int row,column;
	int step,type;
	bool operator==(point& other)
	{
		if(row==other.row&&column==other.column)return true;
		return false;
	}
	point(int r=0,int c=0,int d=0)
	    :row(r),column(c),step(d),type(0)
	{}
};
point set[6];
 
int map[105][105];
int len[6];
int state[105][105];
int yet[6];
int result=inf;
int make(point & begin, point & end) 
{
    deque<point> queue;
    for (int i = 1; i <= n; ++i) 
	{
        for (int j = 1; j <= m; ++j) 
		{
            state[i][j] = false;
        }
    }
    begin.step = 0;
    queue.push_back(begin);
    while(!queue.empty()) 
	{
        point now = queue.front();
        queue.pop_front();
        state[now.row][now.column] = true;
        point next;
        for (int i = 0; i < 4; ++i) 
		{
            next.row = now.row + dx[i];
            next.column = now.column + dy[i];
            if (next.row >= 1&& next.row <= n&& next.column >= 1&& next.column <= m) 
			{
                if (state[next.row][next.column])continue;
                next.type = map[next.row][next.column];
                state[next.row][next.column] = true;
                if (next.type != -1) 
				{
                    next.step = now.step + 1;
                    if (next.row == end.row && next.column == end.column)return next.step;
                    queue.push_back(next);
                }
            }
        }
    }
    return -1;
}
void dfs(int start,int count,int dis,int k)
{
	if(yet[start]==1)return;
	yet[start]=1;
	if(count==k)
	{
		if(dis<result)result=dis;
	}
	else
	{
		for(node* tmp=head[start].next;tmp;tmp=tmp->next)
		{
			dfs(tmp->num,count+1,dis+tmp->weight,k);
		}
	}
	yet[start]=0;
}
int main()
{
	int size=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>check;
			map[i][j]=check;
			if(check==1)
			{
				++size;
				set[size].row=i;
				set[size].column=j;
			}
			if(check==2)
			{
				set[0].row=i;
				set[0].column=j;
			}
		}
	}
	head=new node[size+2];
	memset(yet,0,sizeof(yet));
	int root,tmp1,tmp2;
	node* tmp;
	memset(len,0,sizeof(len));
	memset(state,0,sizeof(state));
	for(int i=1;i<=size;i++)
	{
		if(make(set[0],set[i])==-1)
		{
		    cout<<"-1";
		    return 0;
		}
	}
	for(int i=0;i<=size;i++)
	{
		memset(len,0,sizeof(len));
	    memset(state,0,sizeof(state));
		//make(set[i].row,set[i].column,0);
		/*
	    for(int i=1;i<=n;i++)
	    {
		    for(int j=1;j<=m;j++)
		    {
			    cout<<len[i][j]<<" ";
		    }
		    cout<<endl;
	    }
	    cout<<endl;
		*/
		for(int j=0;j<=size;j++)
		{
			if(j==i)continue;
			int noe=make(set[i],set[j]);
			tmp=new node(j,noe,head[i].next);
		    head[i].next=tmp;
		}
	}
	/*
	for(int i=0;i<=size;i++)
	{
		node* some=head[i].next;
		while(some)
		{
			cout<<some->num<<"!"<<some->weight<<" ";
			some=some->next;
		}
		cout<<endl;
	}
	*/
	dfs(0,0,0,size);
	cout<<result;
	
	/* 
	memset(len,0,sizeof(len));
	memset(state,0,sizeof(state));
	make(set[0].row,set[0].column,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<len[i][j]<<" ";
		}
		cout<<endl;
	}
	*/ 
	/*
	for(int i=0;i<=size;i++)
	{
		cout<<set[i].row<<" "<<set[i].column<<endl;
	}
	*/
	
	
	
}
