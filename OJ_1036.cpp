#include <iostream>  
#include <stdio.h>  
using namespace std;  
      
int a[100000];  
long long s[3]={0},sum[3]={0};  
int minIndex(){  
    int t=(sum[1]<=sum[2]?1:2);  
    t=(sum[0]<=sum[t]?0:t);  
    return t;  
}  
long long max(long long a,long long b,long long c){  
    b=(b>c?b:c);  
    return (a>b?a:b);  
}  
int main(){  
    int n,i,k;  
    long long w1,t1,w2,t2;  
    scanf("%d",&n);  
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }  
    for(i=0;i<n;i+=3){  
        s[0]+=sum[0];  
        sum[0]+=a[i];  
    }  
    for(i=1;i<n;i+=3){  
        s[1]+=sum[1];  
        sum[1]+=a[i];  
    }  
    for(i=2;i<n;i+=3){  
        s[2]+=sum[2];  
        sum[2]+=a[i];  
    }  
    w1=s[0]+s[1]+s[2];  
    t1=max(sum[0],sum[1],sum[2]);  
    
    s[0]=s[1]=s[2]=sum[0]=sum[1]=sum[2]=0;  
    for(i=0;i<n;i++){  
        k=minIndex();  
        s[k]+=sum[k];  
        sum[k]+=a[i];  
    }  
    w2=s[0]+s[1]+s[2];  
    t2=max(sum[0],sum[1],sum[2]);  
    printf("%lld %lld\n%lld %lld\n",w1,t1,w2,t2);  
    return 0;  
}
