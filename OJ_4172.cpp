#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000002;
int a[maxn],n,m,i,x,y,s,cho; 
struct node{int l,r,t;}ha;
struct segtree
{
    #define lson (o<<1)
    #define rson (o<<1|1)
    #define mid ((l+r)>>1)
    int sumv[maxn<<2],suml[maxn<<2],sumr[maxn<<2],sumt[maxn<<2];
    int sumlz[maxn<<2],sumrz[maxn<<2],sumtz[maxn<<2];
    int reiv[maxn<<2],itiv[maxn<<2],xorv[maxn<<2];
    inline void pushup(int o,int l,int r){
        if(suml[lson]==mid-l+1)suml[o]=suml[lson]+suml[rson];
         else suml[o]=suml[lson];
        if(sumr[rson]==r-mid)sumr[o]=sumr[rson]+sumr[lson];
         else sumr[o]=sumr[rson];
        sumt[o]=max(max(sumt[rson],sumt[lson]),suml[rson]+sumr[lson]);
        if(sumlz[lson]==mid-l+1)sumlz[o]=sumlz[lson]+sumlz[rson];
         else sumlz[o]=sumlz[lson];
        if(sumrz[rson]==r-mid)sumrz[o]=sumrz[rson]+sumrz[lson];
         else sumrz[o]=sumrz[rson];
        sumtz[o]=max(max(sumtz[rson],sumtz[lson]),sumlz[rson]+sumrz[lson]);
        sumv[o]=sumv[lson]+sumv[rson];
    }
    inline void pushdown(int o,int l,int r){
        if(itiv[o]){
            sumv[lson]=suml[lson]=sumr[lson]=sumt[lson]=mid-l+1;
            sumv[rson]=suml[rson]=sumr[rson]=sumt[rson]=r-mid;
            sumlz[lson]=sumlz[rson]=sumrz[lson]=sumrz[rson]=sumtz[lson]=sumtz[rson]=0;
            itiv[rson]=itiv[lson]=1;
            xorv[lson]=xorv[rson]=reiv[lson]=reiv[rson]=0;
            itiv[o]=0;
        }else if(reiv[o]){
            sumlz[lson]=sumrz[lson]=sumtz[lson]=mid-l+1;
            sumlz[rson]=sumrz[rson]=sumtz[rson]=r-mid;
            sumv[lson]=sumv[rson]=suml[lson]=suml[rson]=sumr[lson]=sumr[rson]=sumt[lson]=sumt[rson]=0;
            reiv[rson]=reiv[lson]=1;
            xorv[lson]=xorv[rson]=itiv[lson]=itiv[rson]=0;
            reiv[o]=0;
        }
        if(xorv[o]){
            sumv[lson]=mid-l+1-sumv[lson],sumv[rson]=r-mid-sumv[rson];
            swap(sumt[lson],sumtz[lson]);swap(sumt[rson],sumtz[rson]);
            swap(suml[lson],sumlz[lson]);swap(suml[rson],sumlz[rson]);
            swap(sumr[lson],sumrz[lson]);swap(sumr[rson],sumrz[rson]);
            xorv[lson]^=1;xorv[rson]^=1;
            xorv[o]=0;
        }
    }
    inline void build(int o,int l,int r){
        reiv[o]=itiv[o]=xorv[o]=0;
        if(l==r){
         suml[o]=sumr[o]=sumt[o]=sumv[o]=a[l];
         sumlz[o]=sumrz[o]=sumtz[o]=a[l]^1;
         return;
        }
        build(lson,l,mid);
        build(rson,mid+1,r);
        pushup(o,l,r);
    }
    inline int querysum(int o,int l,int r,int ql,int qr){
        if(ql<=l&&qr>=r)return sumv[o];
        pushdown(o,l,r);
        int ans=0;
        if(ql<=mid)ans+=querysum(lson,l,mid,ql,qr);
        if(qr>mid)ans+=querysum(rson,mid+1,r,ql,qr);
        return ans;
    }
    inline node querymax(int o,int l,int r,int ql,int qr){
        if(ql<=l&&qr>=r)return (node){suml[o],sumr[o],sumt[o]};
        pushdown(o,l,r);
        node t,tl,tr;
        int fll=0,flr=0;
        if(ql<=mid)tl=querymax(lson,l,mid,ql,qr);else{tl=(node){0,0,0};fll=1;}
        if(qr>mid)tr=querymax(rson,mid+1,r,ql,qr);else{tr=(node){0,0,0};flr=1;}
        if(tl.l==mid-l+1)t.l=tl.l+tr.l;
         else if(fll==1)t.l=tr.l;
          else t.l=tl.l;
        if(tr.r==r-mid)t.r=tr.r+tl.r;
         else if(flr==1)t.r=tl.r;
          else t.r=tr.r;
        t.t=max(max(tr.t,tl.t),tl.r+tr.l);
        return t;
    }
    inline void optiti(int o,int l,int r,int ql,int qr){
        if(ql<=l&&qr>=r){
            sumv[o]=r-l+1;
            sumlz[o]=sumrz[o]=sumtz[o]=0;
            suml[o]=sumr[o]=sumt[o]=r-l+1;
            xorv[o]=0,itiv[o]=1,reiv[o]=0;
            return;
        }
        pushdown(o,l,r);
        if(ql<=mid)optiti(lson,l,mid,ql,qr);
        if(qr>mid)optiti(rson,mid+1,r,ql,qr);
        pushup(o,l,r);
    }
    inline void optrei(int o,int l,int r,int ql,int qr){
        if(ql<=l&&qr>=r){
            sumv[o]=0;
            sumlz[o]=sumrz[o]=sumtz[o]=r-l+1;
            suml[o]=sumr[o]=sumt[o]=0;
            xorv[o]=0,itiv[o]=0,reiv[o]=1;
            return;
        }
        pushdown(o,l,r);
        if(ql<=mid)optrei(lson,l,mid,ql,qr);
        if(qr>mid)optrei(rson,mid+1,r,ql,qr);
        pushup(o,l,r);
    }
    inline void optxor(int o,int l,int r,int ql,int qr){
        if(ql<=l&&qr>=r){
            sumv[o]=r-l+1-sumv[o];
            swap(sumt[o],sumtz[o]);
            swap(suml[o],sumlz[o]);
            swap(sumr[o],sumrz[o]);
            xorv[o]^=1;
            return;
        }
        pushdown(o,l,r);
        if(ql<=mid)optxor(lson,l,mid,ql,qr);
        if(qr>mid)optxor(rson,mid+1,r,ql,qr);
        pushup(o,l,r);
    }
}seg;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i];
    seg.build(1,1,n);
    while(m--)
	{
        cin>>s>>x>>y;
        switch(s)
		{
            case 1:
			{
				cin>>cho;
				if(cho==1)seg.optiti(1,1,n,x,y);
				else seg.optrei(1,1,n,x,y);
				break;
			}
            case 2:cout<<seg.querysum(1,1,n,x,y)<<'\n';break;
            case 3:cout<<seg.querymax(1,1,n,x,y).t<<'\n';break;
        }
    }
    return 0;
}
