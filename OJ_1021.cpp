#include<iostream>
using namespace std;
 
int main(){
    int n,i=0,j=0;
    cin>>n;
    int a[200][200]={0};
    int count=1,cishu=0;
    while(count<=n*n){
        i=cishu;
        j=cishu;
        while(j<n-cishu){
            a[i][j]=count;
            count++;
            j++;
        }
        j--;
        i++;
        while(i<n-cishu){
            a[i][j]=count;
            count++;
            i++;
        }
        i--;
        j--;
        while(j>=cishu){
            a[i][j]=count;
            count++;
            j--;
        }
        i--;
        j++;
        while(i>cishu){
            a[i][j]=count;
            count++;
            i--;
        }
        i++;
        j++;
        cishu++;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl; 
    }
    return 0;
}
