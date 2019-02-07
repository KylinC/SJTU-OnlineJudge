#include<iostream>
#include<cstring>
using namespace std;
 
int a[1001],b[1001],c[1001];
 
void init(int a[]){
    char n[1001];
    cin>>n;
    a[0]=strlen(n);
    for(int i=1,j=a[0]-1;i<=a[0]&&j>=0;i++,j--){
        a[i]=n[j]-48;
    }
}
 
void output(int a[]){
    for(int i=a[0];i>=1;i--)printf("%d",a[i]);
}
 
bool compare(int a[],int b[]){
    if(a[0]!=b[0])return a[0]<b[0];
    for(int i=a[0];i>=0;i--){
        if(a[i]!=b[i])return a[i]<b[i];
    }
    return false;
}
 
void abstr(int a[],int b[]){
    int c[1001];
    c[0]=max(a[0],b[0]);
    for(int i=1;i<=c[0];i++){
        if(a[i]==99){
            a[i]=9;
            if(a[i+1]!=0)a[i+1]--;
            else a[i+1]=99;
        }
        if(a[i]>=b[i])c[i]=a[i]-b[i];
        else {
            if(a[i+1]!=0)a[i+1]--;
            else a[i+1]=99;
                c[i]=a[i]+10-b[i];
        }
    }
    while(c[c[0]]==0&&c[0]>1)c[0]--;
    memcpy(a,c,sizeof(c));
}
 
void numcopy(int a[],int b[],int test){
    int t=test;
    for(int i=1;i<=a[0];i++,t++)b[t]=a[i];
    b[0]=t-1;
}
 
void divide(int a[],int b[],int c[]){
    c[0]=a[0];
    for(int i=a[0]-b[0];i>=1;i--){
        int tmp[1001];
        int ans=0;
        for(int k=0;k<1001;k++)
        {
        	tmp[k]=0;
		}
        numcopy(b,tmp,i);
        while(!compare(a,tmp)){
            abstr(a,tmp);
            ans++;
        }
        c[i]=ans;
    }
    while(c[c[0]]==0&&c[0]>1)c[0]--;
}
 
int main(){
    init(a);
    init(b);
    divide(a,b,c);
    output(c); 
    
    return 0;
}
