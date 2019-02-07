#include <iostream>
using namespace std;
const int MAXN=2000010;
 
struct node
{
    int k, t;
    int value;
};
node con[MAXN];
int tot=0, all_min=MAXN;
int origin[MAXN], pos[MAXN];
 
bool cmp(node first,node second)
{
    if (first.value<second.value) return true;
    if (first.value==second.value && first.t>second.t) return true;
    return false;
}
 
inline void sub(int hole)
{
    int son;
    node x=con[hole];
    for(;hole<<1 <= tot; hole=son){
        son=hole<<1;
        if(son+1<=tot && cmp(con[son+1],con[son]))
            ++son;
        if(cmp(con[son],x)){
            con[hole]=con[son];
            pos[con[son].k]=hole;
        }
        else break;
    }
    con[hole]=x;
    pos[x.k]=hole;
}
 
inline void add(int hole)
{
    node x=con[hole];
    for(;hole>1 && cmp(x,con[hole>>1]) ;hole=hole>>1){
        con[hole]=con[hole>>1];
        pos[con[hole>>1].k]=hole;
    }
    con[hole]=x;
    pos[x.k]=hole;
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
	{
        cin>>origin[i];
        all_min=(origin[i]<all_min)?origin[i]:all_min;
    }
    for(int i=1;i<=n;++i)
        if(all_min+2*m>=origin[i])
		{
            con[++tot].value=origin[i];
            con[tot].k=i;
            con[tot].t=i;
        }
    for(int i=tot/2;i>0;--i) sub(i);
    for(int i=1;i<=tot;++i)
        pos[con[i].k]=i;
    int tmp_x, tmp_y;
    for(int i=1;i<=m;++i){
        cin>>tmp_x>>tmp_y;
        con[pos[tmp_x]].value+=tmp_y;
        con[pos[tmp_x]].t=n+i;
        if(tmp_y>0)
            sub(pos[tmp_x]);
        else
            add(pos[tmp_x]);
        cout<<con[1].k<<"\n";
    }
    return 0;
}
